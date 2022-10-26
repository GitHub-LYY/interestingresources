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

如果存在数据边界
