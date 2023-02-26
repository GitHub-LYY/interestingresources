
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_EVENT_H_INCLUDED_
#define _NGX_EVENT_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>


#define NGX_INVALID_INDEX  0xd0d0d0d0


#if (NGX_HAVE_IOCP)

typedef struct {
    WSAOVERLAPPED    ovlp;
    ngx_event_t     *event;
    int              error;
} ngx_event_ovlp_t;

#endif

/* 在nginx中，每一个事件都由ngx_event_t结构体来表示 */
struct ngx_event_s {
    /* 事件相关的对象。通常data都是指向ngx_connection_t连接对象。开启文件异步I/O时，
       它可能会指向ngx_event_aio_t结构体 */
    void            *data;

    /* 标志位，为1时表示事件是可写的。通常情况下，它表示对应的TCP连接目前状态是可写的，
       也就是连接处于可以发送网络包的状态 */
    unsigned         write:1;

    /* 标志位，为1时表示为此事件可以建立新的连接。通常情况下，在ngx_cycle_t中的
       listening动态数组中，每一个监听对象ngx_listening_t对应的读事件中的accept
       标志位才会是1 */
    unsigned         accept:1;

    /* used to detect the stale events in kqueue and epoll */
    /* 这个标志位用于区分当前事件是否是过期的，它仅仅是给事件驱动模块使用的，而事件
       消费模块可不用关心。为什么需要这个标志位呢？当开始处理一批事件时，处理前边的
       事件可能会关闭一些链接，而这些链接有可能影响这批事件中还未处理到的后边的事件。
       这时，可通过instance标志位来避免处理后边的已经过期的事件。在9.6节中，将详细
       描述ngx_epoll_module是如何使用instance标志位区分过期事件的，这是一个巧妙的
       设计方法 */
    unsigned         instance:1;

    /*
     * the event was passed or would be passed to a kernel;
     * in aio mode - operation was posted.
     */
    /* 标志位，为1时表示当前事件是活跃的，为0时表示事件是不活跃的。这个状态对应着事件
       驱动模块处理方式的不同。例如，在添加事件、删除事件和处理事件时，active标志位
       的不同都会对应着不同的处理方式。在使用事件时，一般不会直接改变active标志位 */
    unsigned         active:1;

    /* 标志位，为1时表示禁用事件，仅在kqueue或者rtsig事件驱动模块中有效，而对于epoll事件
       驱动模块则无意义，这里不再详述 */
    unsigned         disabled:1;

    /* the ready event; in aio mode 0 means that no operation can be posted */
    /* 标志位，为1时表示当前事件已经准备就绪，也就是说，允许这个事件的消费模块处理这个
       事件。在HTTP框架中，经常会检查事件的ready标志位以确定是否可以接收请求或者发送
       响应 */
    unsigned         ready:1;

    /* 该标志位仅对kqueue，eventport等模块有意义，而对于linux上的epoll事件驱动模块
       则是无意义的，限于篇幅，不再详细说明 */
    unsigned         oneshot:1;

    /* aio operation is complete */
    /* 该标志位用于异步AIO事件的处理，在9.9节中会详细描述 */
    unsigned         complete:1;

    /* 标志位，为1时表示当前处理的字符流已经结束 */
    unsigned         eof:1;
    /* 标志位，为1时表示事件在处理过程中出现错误 */
    unsigned         error:1;

    /* 标志位，为1时表示这个事件已经超时，用以提示事件的消费模块做超时处理，它与timer_set都
       用于9.7节将要介绍的定时器 */
    unsigned         timedout:1;
    /* 标志位，为1时表示这个事件存在于定时器中 */
    unsigned         timer_set:1;

    /* 标志位，delayed为1时表示需要延迟处理这个事件，它仅用于限速功能 */
    unsigned         delayed:1;

    /* 标志位，为1时表示延迟建立TCP连接，也就是说，经过TCP三次握手后并不建立连接，
       而是要等到真正收到数据包后才会建立TCP连接 */
    unsigned         deferred_accept:1;

    /* the pending eof reported by kqueue, epoll or in aio chain operation */
    /* 标志位，为1时表示等待字符流结束，它只与kqueue和aio事件驱动机制有关，不再详述 */
    unsigned         pending_eof:1;

    unsigned         posted:1;

    // 标志位，为1时表示当前事件已经关闭，epoll模块没有使用它
    unsigned         closed:1;

    /* to test on worker exit */
    // 该标志位目前无实际意义
    unsigned         channel:1;
    // 该标志位目前无实际意义
    unsigned         resolver:1;

    unsigned         cancelable:1;

#if (NGX_HAVE_KQUEUE)
    unsigned         kq_vnode:1;

    /* the pending errno reported by kqueue */
    int              kq_errno;
#endif

    /*
     * kqueue only:
     *   accept:     number of sockets that wait to be accepted
     *   read:       bytes to read when event is ready
     *               or lowat when event is set with NGX_LOWAT_EVENT flag
     *   write:      available space in buffer when event is ready
     *               or lowat when event is set with NGX_LOWAT_EVENT flag
     *
     * iocp: TODO
     *
     * otherwise:
     *   accept:     1 if accept many, 0 otherwise
     *   read:       bytes to read when event is ready, -1 if not known
     */

    int              available;

    /* 这个事件发生时的处理方法，每个事件消费模块都会重新实现它 
       每一个事件最核心的部分是handler回调方法，它将由每一个事件消费模块实现，
       以此决定这个事件究竟如何“消费” */
    ngx_event_handler_pt  handler;


#if (NGX_HAVE_IOCP)
    // Windows系统下的一种事件驱动模型，这里不再详述
    ngx_event_ovlp_t ovlp;
#endif

    // 由于epoll事件驱动方式不使用index，所以这里不再说明
    ngx_uint_t       index;

    // 可用于记录error_log日志的ngx_log_t对象
    ngx_log_t       *log;

    // 定时器节点，用于定时器红黑树中，在9.7节会详细介绍
    ngx_rbtree_node_t   timer;

    /* the posted queue */
    ngx_queue_t      queue;

#if 0

    /* the threads support */

    /*
     * the event thread context, we store it here
     * if $(CC) does not understand __thread declaration
     * and pthread_getspecific() is too costly
     */

    void            *thr_ctx;

#if (NGX_EVENT_T_PADDING)

    /* event should not cross cache line in SMP */

    uint32_t         padding[NGX_EVENT_T_PADDING];
#endif
#endif
};


#if (NGX_HAVE_FILE_AIO)

struct ngx_event_aio_s {
    void                      *data;
    ngx_event_handler_pt       handler;
    ngx_file_t                *file;

    ngx_fd_t                   fd;

#if (NGX_HAVE_EVENTFD)
    int64_t                    res;
#endif

#if !(NGX_HAVE_EVENTFD) || (NGX_TEST_BUILD_EPOLL)
    ngx_err_t                  err;
    size_t                     nbytes;
#endif

    ngx_aiocb_t                aiocb;
    ngx_event_t                event;
};

#endif


typedef struct {
    /* 添加事件方法，它将负责把1个感兴趣的事件添加到操作系统提供的时间驱动机制（如
       epoll、kqueue等）中，这样，在事件发生后，将可以在调用下边的process_events
       时获取这个事件 */
    ngx_int_t  (*add)(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags);
    /* 删除事件方法，它将把1个已经存在于事件驱动机制中的事件移除，这样以后即使这个
       事件发生，调用process_events方法时也无法再获取这个事件 */
    ngx_int_t  (*del)(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags);

    /* 启用1个事件，目前事件处理框架不会调用这个方法，大部分事件驱动模块对于该方法
       的实现都是与上边的add方法完全一致的 */
    ngx_int_t  (*enable)(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags);
    /* 禁用1个事件，目前事件处理框架不会调用这个方法，大部分事件驱动模块对于该方法
       的实现都是与上边的del方法完全一致的 */
    ngx_int_t  (*disable)(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags);

    /* 向事件驱动机制中添加一个新的连接，这意味着连接上的读写事件都添加到事件驱动机制中了 */
    ngx_int_t  (*add_conn)(ngx_connection_t *c);
    /* 从事件驱动机制中移除一个连接的读写事件 */
    ngx_int_t  (*del_conn)(ngx_connection_t *c, ngx_uint_t flags);

    ngx_int_t  (*notify)(ngx_event_handler_pt handler);

    /* 在正常的工作循环中，将通过调用process_events方法来处理事件。这个方法仅在
       第8章中提到的ngx_process_events_and_timers方法中调用，它是处理、分发
       事件的核心 */
    ngx_int_t  (*process_events)(ngx_cycle_t *cycle, ngx_msec_t timer,
                                 ngx_uint_t flags);

    /* 初始化事件驱动模块的方法 */
    ngx_int_t  (*init)(ngx_cycle_t *cycle, ngx_msec_t timer);
    /* 退出事件驱动模块前调用的方法 */
    void       (*done)(ngx_cycle_t *cycle);
} ngx_event_actions_t;


extern ngx_event_actions_t   ngx_event_actions;
#if (NGX_HAVE_EPOLLRDHUP)
extern ngx_uint_t            ngx_use_epoll_rdhup;
#endif


/*
 * The event filter requires to read/write the whole data:
 * select, poll, /dev/poll, kqueue, epoll.
 */
#define NGX_USE_LEVEL_EVENT      0x00000001

/*
 * The event filter is deleted after a notification without an additional
 * syscall: kqueue, epoll.
 */
#define NGX_USE_ONESHOT_EVENT    0x00000002

/*
 * The event filter notifies only the changes and an initial level:
 * kqueue, epoll.
 */
#define NGX_USE_CLEAR_EVENT      0x00000004

/*
 * The event filter has kqueue features: the eof flag, errno,
 * available data, etc.
 */
#define NGX_USE_KQUEUE_EVENT     0x00000008

/*
 * The event filter supports low water mark: kqueue's NOTE_LOWAT.
 * kqueue in FreeBSD 4.1-4.2 has no NOTE_LOWAT so we need a separate flag.
 */
#define NGX_USE_LOWAT_EVENT      0x00000010

/*
 * The event filter requires to do i/o operation until EAGAIN: epoll.
 */
#define NGX_USE_GREEDY_EVENT     0x00000020

/*
 * The event filter is epoll.
 */
#define NGX_USE_EPOLL_EVENT      0x00000040

/*
 * Obsolete.
 */
#define NGX_USE_RTSIG_EVENT      0x00000080

/*
 * Obsolete.
 */
#define NGX_USE_AIO_EVENT        0x00000100

/*
 * Need to add socket or handle only once: i/o completion port.
 */
#define NGX_USE_IOCP_EVENT       0x00000200

/*
 * The event filter has no opaque data and requires file descriptors table:
 * poll, /dev/poll.
 */
#define NGX_USE_FD_EVENT         0x00000400

/*
 * The event module handles periodic or absolute timer event by itself:
 * kqueue in FreeBSD 4.4, NetBSD 2.0, and MacOSX 10.4, Solaris 10's event ports.
 */
#define NGX_USE_TIMER_EVENT      0x00000800

/*
 * All event filters on file descriptor are deleted after a notification:
 * Solaris 10's event ports.
 */
#define NGX_USE_EVENTPORT_EVENT  0x00001000

/*
 * The event filter support vnode notifications: kqueue.
 */
#define NGX_USE_VNODE_EVENT      0x00002000


/*
 * The event filter is deleted just before the closing file.
 * Has no meaning for select and poll.
 * kqueue, epoll, eventport:         allows to avoid explicit delete,
 *                                   because filter automatically is deleted
 *                                   on file close,
 *
 * /dev/poll:                        we need to flush POLLREMOVE event
 *                                   before closing file.
 */
#define NGX_CLOSE_EVENT    1

/*
 * disable temporarily event filter, this may avoid locks
 * in kernel malloc()/free(): kqueue.
 */
#define NGX_DISABLE_EVENT  2

/*
 * event must be passed to kernel right now, do not wait until batch processing.
 */
#define NGX_FLUSH_EVENT    4


/* these flags have a meaning only for kqueue */
#define NGX_LOWAT_EVENT    0
#define NGX_VNODE_EVENT    0


#if (NGX_HAVE_EPOLL) && !(NGX_HAVE_EPOLLRDHUP)
#define EPOLLRDHUP         0
#endif


#if (NGX_HAVE_KQUEUE)

#define NGX_READ_EVENT     EVFILT_READ
#define NGX_WRITE_EVENT    EVFILT_WRITE

#undef  NGX_VNODE_EVENT
#define NGX_VNODE_EVENT    EVFILT_VNODE

/*
 * NGX_CLOSE_EVENT, NGX_LOWAT_EVENT, and NGX_FLUSH_EVENT are the module flags
 * and they must not go into a kernel so we need to choose the value
 * that must not interfere with any existent and future kqueue flags.
 * kqueue has such values - EV_FLAG1, EV_EOF, and EV_ERROR:
 * they are reserved and cleared on a kernel entrance.
 */
#undef  NGX_CLOSE_EVENT
#define NGX_CLOSE_EVENT    EV_EOF

#undef  NGX_LOWAT_EVENT
#define NGX_LOWAT_EVENT    EV_FLAG1

#undef  NGX_FLUSH_EVENT
#define NGX_FLUSH_EVENT    EV_ERROR

#define NGX_LEVEL_EVENT    0
#define NGX_ONESHOT_EVENT  EV_ONESHOT
#define NGX_CLEAR_EVENT    EV_CLEAR

#undef  NGX_DISABLE_EVENT
#define NGX_DISABLE_EVENT  EV_DISABLE


#elif (NGX_HAVE_DEVPOLL && !(NGX_TEST_BUILD_DEVPOLL)) \
      || (NGX_HAVE_EVENTPORT && !(NGX_TEST_BUILD_EVENTPORT))

#define NGX_READ_EVENT     POLLIN
#define NGX_WRITE_EVENT    POLLOUT

#define NGX_LEVEL_EVENT    0
#define NGX_ONESHOT_EVENT  1


#elif (NGX_HAVE_EPOLL) && !(NGX_TEST_BUILD_EPOLL)

#define NGX_READ_EVENT     (EPOLLIN|EPOLLRDHUP)
#define NGX_WRITE_EVENT    EPOLLOUT

#define NGX_LEVEL_EVENT    0
#define NGX_CLEAR_EVENT    EPOLLET
#define NGX_ONESHOT_EVENT  0x70000000
#if 0
#define NGX_ONESHOT_EVENT  EPOLLONESHOT
#endif

#if (NGX_HAVE_EPOLLEXCLUSIVE)
#define NGX_EXCLUSIVE_EVENT  EPOLLEXCLUSIVE
#endif

#elif (NGX_HAVE_POLL)

#define NGX_READ_EVENT     POLLIN
#define NGX_WRITE_EVENT    POLLOUT

#define NGX_LEVEL_EVENT    0
#define NGX_ONESHOT_EVENT  1


#else /* select */

#define NGX_READ_EVENT     0
#define NGX_WRITE_EVENT    1

#define NGX_LEVEL_EVENT    0
#define NGX_ONESHOT_EVENT  1

#endif /* NGX_HAVE_KQUEUE */


#if (NGX_HAVE_IOCP)
#define NGX_IOCP_ACCEPT      0
#define NGX_IOCP_IO          1
#define NGX_IOCP_CONNECT     2
#endif


#if (NGX_TEST_BUILD_EPOLL)
#define NGX_EXCLUSIVE_EVENT  0
#endif


#ifndef NGX_CLEAR_EVENT
#define NGX_CLEAR_EVENT    0    /* dummy declaration */
#endif


#define ngx_process_events   ngx_event_actions.process_events
#define ngx_done_events      ngx_event_actions.done

/* 一般在向epoll中添加可读或者可写事件时，都是使用ngx_handle_read_event
或者ngx_handle_write_event方法的。对于事件驱动模块实现的
ngx_event_actions结构体中的事件设置方法，最好不要直接调用，下面这4个方法
直接使用时都会与具体的事件驱动机制强相关，而使用ngx_handle_read_event
或者ngx_handle_write_event方法则可以屏蔽这种差异 */
#define ngx_add_event        ngx_event_actions.add
#define ngx_del_event        ngx_event_actions.del
#define ngx_add_conn         ngx_event_actions.add_conn
#define ngx_del_conn         ngx_event_actions.del_conn

#define ngx_notify           ngx_event_actions.notify

#define ngx_add_timer        ngx_event_add_timer
#define ngx_del_timer        ngx_event_del_timer


extern ngx_os_io_t  ngx_io;

#define ngx_recv             ngx_io.recv
#define ngx_recv_chain       ngx_io.recv_chain
#define ngx_udp_recv         ngx_io.udp_recv
#define ngx_send             ngx_io.send
#define ngx_send_chain       ngx_io.send_chain
#define ngx_udp_send         ngx_io.udp_send
#define ngx_udp_send_chain   ngx_io.udp_send_chain


#define NGX_EVENT_MODULE      0x544E5645  /* "EVNT" */
#define NGX_EVENT_CONF        0x02000000


typedef struct {
    ngx_uint_t    connections;
    ngx_uint_t    use;

    ngx_flag_t    multi_accept;
    ngx_flag_t    accept_mutex;

    ngx_msec_t    accept_mutex_delay;

    u_char       *name;

#if (NGX_DEBUG)
    ngx_array_t   debug_connection;
#endif
} ngx_event_conf_t;


/* 事件模块的通用接口 */
typedef struct {
    ngx_str_t              *name; // 事件模块的名称

    // create_conf和init_conf方法的调用可参见图9-3
    // 在解析配置项前，这个回调方法用于创建存储配置项参数的结构体
    void                 *(*create_conf)(ngx_cycle_t *cycle);
    // 在解析配置项完成后，init_conf方法会被调用，用以综合处理当前事件模块感兴趣的全部配置项
    char                 *(*init_conf)(ngx_cycle_t *cycle, void *conf);

    ngx_event_actions_t     actions; // 对于事件驱动机制，每个事件模块需要实现的10个抽象方法
} ngx_event_module_t;


extern ngx_atomic_t          *ngx_connection_counter;

extern ngx_atomic_t          *ngx_accept_mutex_ptr;
extern ngx_shmtx_t            ngx_accept_mutex;
extern ngx_uint_t             ngx_use_accept_mutex;
extern ngx_uint_t             ngx_accept_events;
extern ngx_uint_t             ngx_accept_mutex_held;
extern ngx_msec_t             ngx_accept_mutex_delay;
extern ngx_int_t              ngx_accept_disabled;
extern ngx_uint_t             ngx_use_exclusive_accept;


#if (NGX_STAT_STUB)

extern ngx_atomic_t  *ngx_stat_accepted;
extern ngx_atomic_t  *ngx_stat_handled;
extern ngx_atomic_t  *ngx_stat_requests;
extern ngx_atomic_t  *ngx_stat_active;
extern ngx_atomic_t  *ngx_stat_reading;
extern ngx_atomic_t  *ngx_stat_writing;
extern ngx_atomic_t  *ngx_stat_waiting;

#endif


#define NGX_UPDATE_TIME         1
#define NGX_POST_EVENTS         2


extern sig_atomic_t           ngx_event_timer_alarm;
extern ngx_uint_t             ngx_event_flags;
extern ngx_module_t           ngx_events_module;
extern ngx_module_t           ngx_event_core_module;


#define ngx_event_get_conf(conf_ctx, module)                                  \
             (*(ngx_get_conf(conf_ctx, ngx_events_module))) [module.ctx_index]



void ngx_event_accept(ngx_event_t *ev);
#if !(NGX_WIN32)
void ngx_event_recvmsg(ngx_event_t *ev);
void ngx_udp_rbtree_insert_value(ngx_rbtree_node_t *temp,
    ngx_rbtree_node_t *node, ngx_rbtree_node_t *sentinel);
#endif
void ngx_delete_udp_connection(void *data);
ngx_int_t ngx_trylock_accept_mutex(ngx_cycle_t *cycle);
ngx_int_t ngx_enable_accept_events(ngx_cycle_t *cycle);
u_char *ngx_accept_log_error(ngx_log_t *log, u_char *buf, size_t len);
#if (NGX_DEBUG)
void ngx_debug_accepted_connection(ngx_event_conf_t *ecf, ngx_connection_t *c);
#endif


void ngx_process_events_and_timers(ngx_cycle_t *cycle);
/* 那么，怎么把事件添加到epoll等事件驱动模块中呢？需要调用9.1.1节中提到的
ngx_event_actions_t结构体的add方法或者del方法吗？答案是nginx为我们封装了
两个简单的方法用于在事件驱动模块中添加或者移除事件，当前，也可以调用ngx_event_actions_t
结构体的add或者del等方法，但并不推荐这样做，因为nginx提供的
ngx_handle_read_event和ngx_handle_write_event方法还是做了许多通用性的工作的。

ngx_handle_read_event方法会将读事件添加到事件驱动模块中，这样该事件对应的
TCP连接上一旦出现可读事件（如接收到TCP连接另一端发送来的字符流）就会回调该事件
的handler方法 */
ngx_int_t ngx_handle_read_event(ngx_event_t *rev, ngx_uint_t flags);
ngx_int_t ngx_handle_write_event(ngx_event_t *wev, size_t lowat);


#if (NGX_WIN32)
void ngx_event_acceptex(ngx_event_t *ev);
ngx_int_t ngx_event_post_acceptex(ngx_listening_t *ls, ngx_uint_t n);
u_char *ngx_acceptex_log_error(ngx_log_t *log, u_char *buf, size_t len);
#endif


ngx_int_t ngx_send_lowat(ngx_connection_t *c, size_t lowat);


/* used in ngx_log_debugX() */
#define ngx_event_ident(p)  ((ngx_connection_t *) (p))->fd


#include <ngx_event_timer.h>
#include <ngx_event_posted.h>

#if (NGX_WIN32)
#include <ngx_iocp_module.h>
#endif


#endif /* _NGX_EVENT_H_INCLUDED_ */
