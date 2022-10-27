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

### 字节序转换函数有哪些？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-28-06-image.png)

一般来说，以s作为后缀的函数，s代表2个字节short，因此用于端口号转换。以l作为后缀的函数，l代表4个字节，因此用于IP地址转换。

### 服务端为了避免每次创建套接字要输入IP地址，有哪些方法？

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-10-27-11-48-36-image.png)

利用常数INADDR_ANY指定服务器端IP地址，可以自动获取IP地址，不用每次手动输入。

### 为什么服务端每次在创建套接字的时候要指定IP地址？

因为服务器不一定仅有一个IP地址，有多个网卡，则有多个IP地址，因此需要指定IP地址。
