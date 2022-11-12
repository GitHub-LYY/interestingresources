# C++网络编程（socket编程）

网络编程与文件输入输出很类似，而文件输入输出又与控制台（命令行）输入输出（C语言的printf函数和scanf函数，C++语言的cout和cin）很类似，因此网络编程不难。

### 网络编程的本质（概念）

网络编程的本质是编程程序使得两台联网的计算机实现数据交换。这便是网络编程的全部内容了。很简单。

### TCP套接字的比喻理解（比喻为电话机）

#### 接听套接字（接收套接字）

一、安装电话机

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-26-10-53-55-image.png)

二、分配电话号码

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-26-10-55-11-image.png)

三、连接电话线

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-26-10-55-41-image.png)

四、拿起话筒

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-26-10-56-12-image.png)

##### 总结

网络编程中接收连接请求的套接字创建过程：

第一步：调用socket函数创建套接字。

第二步：调用bind函数分配IP地址和端口号。

第三步：调用listen函数变为可接收请求状态。

第四步：调用accept函数受理连接请求。

#### 打电话套接字（发送端套接字）

一、安装电话机

调用socket函数，此处省略。

二、打电话

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-26-11-05-26-image.png)

##### 总结

网络编程中发送连接请求的套接字创建过程：

第一步：调用socket函数创建套接字。

第二步：调用connect函数连接。

### 文件描述符（文件句柄）

文件描述符理解为文件（linux一切皆文件，这儿含义很宽泛）的身份证号码，方便程序员和操作系统对文件进行操作的一种标识。

文件描述符一般用在linux系统中。

文件句柄一般用在Windows系统中。

### TCP面向连接的套接字是不存在数据边界的，怎么证明？

如果存在数据边界，则write函数的调用次数要等于read函数的调用次数。例如，快递是先后到达的，则来一个快递要去取一次快递。

如果不存在数据边界，则write函数的调用次数不用等于read函数的调用次数。

具体例子，可以参考《TCP/IP网络编程》第30页（不是PDF页码）。

TCP的数据传输不存在边界，意味着数据传输过程中调用I/O函数的次数不具有任何意义。而UDP的数据传输存在边界，调用I/O函数的次数具有重要意义。因此在UDP中，输入函数的调用次数要和输出函数的调用次数必须一致才能保证接收到全部的发送数据。具体例子，参考《TCP/IP网络编程》第109页。

### 客户端准备延迟读取数据，延迟方法？

```cpp
for (int i = 0; i <3000; i++) {
    cout << "Wait time" << i << endl;
}
```

令CPU执行多余任务用以延迟read等函数的调用，这种方式成为"Busy Waiting"，使用得当即可延迟函数调用。

### IP地址的寻址方法？

IP地址前边部分是网络ID，后边部分是主机ID，在转发数据的时候，不是看全部的IP地址，先看网络ID，定位到某个网络后，再看主机ID，定位到具体的主机。

### 快速区分A,B,C类IP地址的方法？

A类地址的首位以0开始。

B类地址的前2位以10开始。

C类地址的前3位以110开始。

### IP地址是区分计算机的，端口号是区分套接字的

### 套接字的端口号的大小？

套接字socket的端口号是16位的，范围是0-65535。0-1023是知名端口号，被占用了，分配的时候从1024开始分配。

### TCP的端口号、UDP的端口号允许重复吗？

TCP的端口号不允许重复，UDP的端口号也不允许重复，但是TCP、UDP的允许重复。例如，TCP占用了9190端口号，UDP此时也可以使用这个端口号，但另外的TCP不能使用9190端口号了。

### 为什么Linux有很多数据类型，如uint32_t等？

这是为了保证在不同的平台如32位，64位，使用这个数据类型始终是32位的，而不是int类型的在32位平台的是32位的，在64位平台的是64位，避免不一致。

### bind函数的第二个参数是struct sockaddr类型的，但是常用的做法是定义struct sockaddr_in类型的，再强制转换。原因参考《TCP/IP网络编程》第42页（不是PDF页码）。

### 大端序、小端序的区别？

大端序，Big Endian，高位字节存放到低位地址。

小端序，Little Endian，高位字节存放到高位地址。

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-21-31-image.png)

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-21-45-image.png)

key point：地址从左到右是从低位到高位，字节数据从左到右是从高位到低位，字节数据的最右边是最低位。

Intel系列CPU使用小端序保存数据。

网络字节序统一为大端序。

现代PC大多采用小端字节序，因此小端字节序又称为主机字节序。

### 字节序转换函数有哪些？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-28-06-image.png)

一般来说，以s作为后缀的函数，s代表2个字节short，因此用于端口号转换。以l作为后缀的函数，l代表4个字节，因此用于IP地址转换。

### 服务端为了避免每次创建套接字要输入IP地址，有哪些方法？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-48-36-image.png)

利用常数INADDR_ANY指定服务器端IP地址，可以自动获取IP地址，不用每次手动输入。

### 为什么服务端每次在创建套接字的时候要指定IP地址？

因为服务器不一定仅有一个IP地址，有多个网卡，则有多个IP地址，因此需要指定IP地址。

### 客户端的什么时候才可以发起connect？

服务器端进行了socket、bind、listen之后，才可以发起connect，connect可以连接服务器端的listen，也可以直接连接accept。这儿可以用一个例子来理解，银行办理业务，银行9点开始上班，8点30先把门打开，这时候相当于listen，请求可以到来了，但是人们需要先在大厅等候，等9点工作人员上班了，这时候调用accept处理请求。如果现在有个vip，可以直接连接accept，或者现在没有等候的人了，此时来的人可以直接连接accept。

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-28-11-35-54-image.png)

key point：客户端仅仅在服务器端调用listen之后才可以调用connect。

### 《TCP/IP网络编程》第77页（不是PDF页码）提到了echo服务器程序存在的问题，在第五章解决，第84页说了存在的问题及解决方案

存在的问题是在调用write函数后立即调用了一次read函数。数据传输的小，不太出现问题，而且是在同一个机器上。但是如果数据量太大，服务器端还没有来得及发送，此时客户端已经在读取了，而现在肯定是读不到数据的或者只读到了一部分数据，因此可能导致读取的数据不完整。解决方法是根据发送数据的大小，来进行循环调用read函数读取完数据。

这个例子也有一个问题，因此这个例子是echo服务器，客户端知道接收的数据大小，这在大多数实际情况下是不现实的。这引出另外的问题：无法提前知道接收数据长度，怎么实现完整收发数据？

### Linux系统编程的read、write函数怎么容易理解？

read函数是接收，读取的意思，write是发送，写入的意思。这一点从Windows相同功能的函数名称也可以知道，在Windows系统中分别对应的是recv、send。

### 套接字的I/O缓冲

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-29-10-55-44-image.png)

调用write函数后，不是立即发送数据，调用read函数后，也不是立即接收数据。如上图所示，在调用write函数的瞬间，数据移至输出缓冲，在适当的时候，再分批或者一次性传到对方的输入缓冲，调用read函数的瞬间，从输入缓冲读取数据。

### 客户端输入缓冲有50字节，服务器端传输了100字节，请问此时发生什么情况？

TCP有滑动窗口机制，保证不会出现这类情况。

### write函数什么时候返回？

write函数在数据移至输出缓冲后便立即返回，不是等到完成向对方的数据传输时才返回。很多地方说write函数在数据传输完成时返回，是移至输出缓冲。

### TCP和UDP的本质区别或者最大区别是什么？

TCP具有流控制机制。

### TCP和UDP的数据传输速率相差的有多大？

在每次交换的数据量足够大的时候，TCP的传输速率接近UDP的传输速率。

### TCP比UDP大多数时候慢，慢在哪？

两点，第一，收发数据前后进行的连接设置及清除过程。第二，收发数据过程中为保证可靠性而添加的流控制。

### TCP相对UDP，具有连接的操作，具体体现在哪？

TCP连接的时候必须调用listen函数和accept函数，这个便是TCP的连接的体现。

### TCP、UDP的套接字的数量上有区别吗？

TCP中的套接字之间是一对一的关系，如果要向10个客户端提供服务，则除了守门的服务器套接字外，还需要10个服务器端套接字。但在UDP中，不管服务器端还是客户端，只需要1个套接字。

### UDP相比TCP，不存在请求连接和受理过程，因此在某种意义上无法明确区分服务器端和客户端，仅仅是因为它提供服务而称为服务器。

### UDP的客户端可以不用bind函数绑定IP地址和端口号，原因是什么？

如果使用了bind函数，则使用指定的IP地址和端口号，如果没有在客户端中调用bind函数，则在首次调用sendto函数的时候给响应的套接字自动分配IP地址和端口号。因此，UDP实现的客户端中经常无需额外的地址分配过程，这也是普遍的实现方式。

### UDP每次数据传输需要带上IP地址和端口号信息，如果一直和一个机器通信，效率上有折扣，有解决方法吗？

有。使用connect函数，构造连接的UDP，没错，UDP也有连接的，使用connect之后，只用传递信息即可，不用每次传输IP地址和端口号了。使用了connect函数后，不仅仅可以使用UDP特有的sendto函数、recvfrom函数，也可以使用read函数、write函数。因为read函数和write函数是配合connect函数使用的，因此使用了connect函数后，经常使用read函数和write函数，如果使用sendto函数和recvfrom函数还是需要指定IP地址和端口号，也可以，但是没必要。

### 程序阻塞的理解？

调用的函数没有返回是阻塞。

### 使用close函数关闭TCP连接不优雅，优雅的关闭方式是使用半关闭，为什么使用半关闭？

服务器端传输完数据后如果调用了close关闭了输入流和输出流，而此时客户端还准备往服务器端发送一个信息，此时的服务器端因为关闭了输入流，接收不到客户端发送的信息了，因此优雅的关闭连接，使用shutdown函数进行半关闭。只关闭服务器端的输出流，因为服务器完成了输出数据的任务，此时客户端发送的信息，服务器端还可以接收到，但是服务器端不能再发送数据了。

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-29-12-11-27-image.png)

### 编程中使用IP地址还是域名？

使用域名，利用域名转换函数转换出IP地址。函数返回hostent结构体变量指针，如下，

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-10-52-16-image.png)

### 服务器端和客户端的time wait有哪些区别？

客户端先发送FIN的时候，有time wait状态，此时客户端立即建立另一个连接也没问题，因为客户端的端口号一般是随机分配的，不太出现重复的端口号。而服务器端先发送FIN的时候，因为服务器端的端口号一般是固定的，因此，服务器端此时立即建立另一个连接是不行的，服务器端处在time wait状态，必须等time wait状态结束后才能建立另一个连接。这在服务器发送宕机的时候不是优点，宕机的时候需要立即重启服务器，而此时time wait状态是不能成功的，有没有方法解决呢？有，如下，

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-11-25-55-image.png)

修改SO_REUSEADDR可选项的true，默认是false。表示time wait状态的端口号可以立即分配给服务器。

### Nagle算法在哪一层？有优点吗？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-11-30-18-image.png)

nagle算法在tcp层，左边是nagle算法，比右边不使用nagle算法的要好，减少数据包的发送次数，数据包的头开销较大的时候，发的数据包多了，造成网络拥塞。但是nagle算法也不是什么时候全部适用，在网络流量未受太大影响时，不使用nagle算法要比使用nagle算法传输速度快。

使用nagle算法的原则是，一般情况下，不适用nagle算法可以提高传输速度，但如果无条件放弃使用nagle算法，网络流量提升变快，反而影响传输，因此，未准确判断数据特性时不应该禁用nagle算法。

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-11-36-39-image.png)

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-11-37-01-image.png)

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-01-11-37-10-image.png)

### CPU核数和进程数的关系是什么？

一个进程运行在CPU的一个核上，因此单核CPU一次运行一个程序，两个核的CPU可以同时运行两个进程，以此类推。进程数比核数多，则分时使用CPU。但是因此CPU速度极快，觉得多个进程是同时运行在CPU上的。

### 什么是僵尸进程？

父进程创建了子进程，子进程在销毁的时候没有把返回值给父进程，则这个子进程此时是僵尸进程。

### 怎么解决僵尸进程的问题？

wait函数。

waitpid函数。

signal函数。

sigaction函数。

### readv和writev函数、read和write的区别？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-05-11-56-55-image.png)

### 线程的分类有哪些？

线程分为内核线程，用户线程。内核线程由内核调度，用户线程由线程库调度。当进程的一个内核线程获得CPU的使用权时，它便加载并运行一个用户线程。因此，内核线程相当于用户线程运行的“容器”。
