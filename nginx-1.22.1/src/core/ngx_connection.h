
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_CONNECTION_H_INCLUDED_
#define _NGX_CONNECTION_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>


typedef struct ngx_listening_s  ngx_listening_t;

struct ngx_listening_s {
    ngx_socket_t        fd; // socket套接字句柄（文件描述符）

    struct sockaddr    *sockaddr; // 监听sockaddr地址
    socklen_t           socklen;    /* size of sockaddr */ // sockaddr地址长度
    size_t              addr_text_max_len; // 存储IP地址的字符串addr_text最大长度，即它指定了addr_text所分配的内存大小
    ngx_str_t           addr_text; // 以字符串形式存储IP地址

    int                 type; // 套接字类型，例如当type是SOCK_STREAM时，表示TCP

    int                 backlog; // TCP实现监听时的backlog队列，它表示允许正在通过三次握手建立TCP连接但还没有任何进程开始处理的连接最大个数
    int                 rcvbuf; // 内核中对于这个套接字的接收缓冲区大小
    int                 sndbuf; // 内核汇总对于这个套接字的发送缓冲区大小
#if (NGX_HAVE_KEEPALIVE_TUNABLE)
    int                 keepidle;
    int                 keepintvl;
    int                 keepcnt;
#endif

    /* handler of accepted connection */
    ngx_connection_handler_pt   handler; // 当新的TCP连接成功建立后的处理方法

    /*
     * 实际上框架并不使用servers指针，它更多是作为一个保留指针，
     * 目前主要用于HTTP或者MAIL等模块，用于保存当前监听端口对应
     * 着的所有主机名
     */
    void               *servers;  /* array of ngx_http_in_addr_t, for example */

    ngx_log_t           log; // log和logp都是可用的日志对象的指针
    ngx_log_t          *logp;

    size_t              pool_size; // 如果为新的TCP连接创建内存池，则内存池的初始大小应该是pool_size
    /* should be here because of the AcceptEx() preread */
    size_t              post_accept_buffer_size; // 这和陶辉使用的版本有区别

    ngx_listening_t    *previous; // 前一个ngx_listening_t结构，多个ngx_listening_t结构体之间由previous指针组成单链表
    ngx_connection_t   *connection; // 当前监听句柄对应着的ngx_connection_t结构体

    ngx_rbtree_t        rbtree;
    ngx_rbtree_node_t   sentinel;

    ngx_uint_t          worker;

    unsigned            open:1; // 标志位，为1则表示在当前监听句柄有效，且执行ngx_init_cycle时不关闭监听端口，为0时则正常关闭。该标志位框架代码会自动设置
    /*
     * 标志位，为1表示使用已有的ngx_cycle_t来初始化新的ngx_cycle_t结构体时，
     * 不关闭原先打开的监听端口，这对运行中升级程序很有用，remain为0时，表示
     * 正常关闭之前打开的监听端口。该标志位框架代码会自动设置，参见
     * ngx_init_cycle方法
     */
    unsigned            remain:1; 
    /*
     * 标志位，为1时表示跳过设置当前ngx_listening_t结构体中的套接字，
     * 为0时正常初始化套接字。该标志位框架代码会自动设置
     */
    unsigned            ignore:1;

    unsigned            bound:1;       /* already bound */ // 表示是否已经绑定，实际上目前该标志位没有使用
    /*
     * 表示当前监听句柄是否来自前一个进程（如升级nginx程序），
     * 如果为1，则表示来自前一个进程。一般会保留之前已经设置
     * 好的套接字，不做改变
     */
    unsigned            inherited:1;   /* inherited from previous process */
    unsigned            nonblocking_accept:1; // 目前未使用
    unsigned            listen:1; // 标志位，为1时表示当前结构体对应的套接字已经监听
    unsigned            nonblocking:1; // 表示套接字是否阻塞，目前该标志位没有意义
    unsigned            shared:1;    /* shared between threads or processes */ // 目前该标志位没有意义
    unsigned            addr_ntop:1; // 标志位，为1时表示nginx会将网络地址转变为字符串形式的地址
    unsigned            wildcard:1;

#if (NGX_HAVE_INET6)
    unsigned            ipv6only:1;
#endif
    unsigned            reuseport:1;
    unsigned            add_reuseport:1;
    unsigned            keepalive:2;

    unsigned            deferred_accept:1;
    unsigned            delete_deferred:1;
    unsigned            add_deferred:1;
#if (NGX_HAVE_DEFERRED_ACCEPT && defined SO_ACCEPTFILTER)
    char               *accept_filter;
#endif
#if (NGX_HAVE_SETFIB)
    int                 setfib;
#endif

#if (NGX_HAVE_TCP_FASTOPEN)
    int                 fastopen;
#endif

};


typedef enum {
    NGX_ERROR_ALERT = 0,
    NGX_ERROR_ERR,
    NGX_ERROR_INFO,
    NGX_ERROR_IGNORE_ECONNRESET,
    NGX_ERROR_IGNORE_EINVAL
} ngx_connection_log_error_e;


typedef enum {
    NGX_TCP_NODELAY_UNSET = 0,
    NGX_TCP_NODELAY_SET,
    NGX_TCP_NODELAY_DISABLED
} ngx_connection_tcp_nodelay_e;


typedef enum {
    NGX_TCP_NOPUSH_UNSET = 0,
    NGX_TCP_NOPUSH_SET,
    NGX_TCP_NOPUSH_DISABLED
} ngx_connection_tcp_nopush_e;


#define NGX_LOWLEVEL_BUFFERED  0x0f
#define NGX_SSL_BUFFERED       0x01
#define NGX_HTTP_V2_BUFFERED   0x02


struct ngx_connection_s {
    void               *data;
    ngx_event_t        *read;
    ngx_event_t        *write;

    ngx_socket_t        fd;

    ngx_recv_pt         recv;
    ngx_send_pt         send;
    ngx_recv_chain_pt   recv_chain;
    ngx_send_chain_pt   send_chain;

    ngx_listening_t    *listening;

    off_t               sent;

    ngx_log_t          *log;

    ngx_pool_t         *pool;

    int                 type;

    struct sockaddr    *sockaddr;
    socklen_t           socklen;
    ngx_str_t           addr_text;

    ngx_proxy_protocol_t  *proxy_protocol;

#if (NGX_SSL || NGX_COMPAT)
    ngx_ssl_connection_t  *ssl;
#endif

    ngx_udp_connection_t  *udp;

    struct sockaddr    *local_sockaddr;
    socklen_t           local_socklen;

    ngx_buf_t          *buffer;

    ngx_queue_t         queue;

    ngx_atomic_uint_t   number;

    ngx_msec_t          start_time;
    ngx_uint_t          requests;

    unsigned            buffered:8;

    unsigned            log_error:3;     /* ngx_connection_log_error_e */

    unsigned            timedout:1;
    unsigned            error:1;
    unsigned            destroyed:1;

    unsigned            idle:1;
    unsigned            reusable:1;
    unsigned            close:1;
    unsigned            shared:1;

    unsigned            sendfile:1;
    unsigned            sndlowat:1;
    unsigned            tcp_nodelay:2;   /* ngx_connection_tcp_nodelay_e */
    unsigned            tcp_nopush:2;    /* ngx_connection_tcp_nopush_e */

    unsigned            need_last_buf:1;

#if (NGX_HAVE_SENDFILE_NODISKIO || NGX_COMPAT)
    unsigned            busy_count:2;
#endif

#if (NGX_THREADS || NGX_COMPAT)
    ngx_thread_task_t  *sendfile_task;
#endif
};


#define ngx_set_connection_log(c, l)                                         \
                                                                             \
    c->log->file = l->file;                                                  \
    c->log->next = l->next;                                                  \
    c->log->writer = l->writer;                                              \
    c->log->wdata = l->wdata;                                                \
    if (!(c->log->log_level & NGX_LOG_DEBUG_CONNECTION)) {                   \
        c->log->log_level = l->log_level;                                    \
    }


ngx_listening_t *ngx_create_listening(ngx_conf_t *cf, struct sockaddr *sockaddr,
    socklen_t socklen);
ngx_int_t ngx_clone_listening(ngx_cycle_t *cycle, ngx_listening_t *ls);
ngx_int_t ngx_set_inherited_sockets(ngx_cycle_t *cycle);
ngx_int_t ngx_open_listening_sockets(ngx_cycle_t *cycle);
void ngx_configure_listening_sockets(ngx_cycle_t *cycle);
void ngx_close_listening_sockets(ngx_cycle_t *cycle);
void ngx_close_connection(ngx_connection_t *c);
void ngx_close_idle_connections(ngx_cycle_t *cycle);
ngx_int_t ngx_connection_local_sockaddr(ngx_connection_t *c, ngx_str_t *s,
    ngx_uint_t port);
ngx_int_t ngx_tcp_nodelay(ngx_connection_t *c);
ngx_int_t ngx_connection_error(ngx_connection_t *c, ngx_err_t err, char *text);

ngx_connection_t *ngx_get_connection(ngx_socket_t s, ngx_log_t *log);
void ngx_free_connection(ngx_connection_t *c);

void ngx_reusable_connection(ngx_connection_t *c, ngx_uint_t reusable);

#endif /* _NGX_CONNECTION_H_INCLUDED_ */
