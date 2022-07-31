1、什么是Docker?

2、什么是Docker镜像?

3、什么是Docker容器?

4、Docker容器有几种状态?

5、DockerFile中最常见的指定是什么?

6、DockerFile中的命令COPY和ADD命令有什么区别?

7、Docker的常用命今?

8、容器与主机之间的数据拷贝命令?

9、启动nginx容器（随机端口映射），并挂载本地文件目录到容器html的命令?

10、解释一下dockerfile的ONBUILD指令?

11、什么是docker Swarm?

12、如何在生产中监控docker?

13、Docker如何在非Linux系统中运行容器?

14、如何批量清理临时镜像文件?

15、如何查看镜像支持的环境变量?

16、本地的镜像文件都存放在哪里?

17、构建docker镜像应该遵循哪些原则?

18、容器退出后，通过docker ps命令查看不到，数据会丢失么?

19、如何停止所有正在运行的容器?

20、如何清理批量后台停止容器?

21、如何临时退出一个正在交互的容器的终端，而不终止它？

22、很多应用容器都是默认后台运行的，怎么查看他们的输出和日志信息?

23、使用docker port命令映射容器的端口时系统报错Error∶NO public port '80'publis hed for …，是什么意思?

24、可以在一个容器中同时运行多个应用进程吗?

25、如何控制容器占用系统资源（CPU，内存）的份额?

26、仓库（Repository）、注册服务器（Regi stry）、注册索引（Index）有何关系?27、从非官方仓库（如∶dl.dockerpool.com 】下载镜像的时候，有时候会提示"Error∶lnvail d registry endpoint https://dl.docker.com:5000/v1."?

28、Docker的配置文件放在那里。如何修改配置?

29、如何更改docker的默认存储设置?

30、docker与LXC（Linux Container）有何不同?

31、Docker于Vagrant有何不同?

32、开发环境中Docker与Vagrant该如何选择？

33、如何将一台宿主机的docker环境迁移到另外一台宿主机?

34、Docker容器创建后，删除了/var/run/net ns目录下的网络名字空间文件，可以手动恢复它∶

35、什么是Docker镜像?

36、解释基本的Docker使用工作流程是怎样的？

37、什么是docker-compose?

38、Docker镜像联合文件系统

39、什么类型的应用程序无状态或有状态更适合Docker容器?

40、Docker 和虚拟机有啥不同?

41、Docker 安全么?42、如何清理后台停止的容器?

43、如何查看镜像支持的环境变量?

44、当启动容器的时候提示∶exec format err or?如何解决问题

45、本地的镜像文件都存放在哪里?

46、如何退出一个镜像的bash，而不终止它?

47、退出容器时候自动删除?

48、怎么快速查看本地的镜像和容器?

49、什么是Docker Hub?

50、Docker容器可扩展到多远?

51、Docker容器退出时是否丢失数据



[50个Docker常见的面试题和答案合集介绍](https://www.lsbin.com/13411.html)



在这里，我们列出了一份 Docker 顶级面试问题的综合列表：

#### **问题：解释 Docker 容器？**

**答：**容器是保存代码及其所有依赖项的软件的基本单元，目的是使应用程序从一个计算生态系统平稳、快速、可靠地运行到另一个计算生态系统。可以使用 Docker 映像创建 Docker 容器。它是软件的可执行包，其中包含运行应用程序所需的一切，包括系统工具、库、代码、运行时和设置。

#### **问题：解释Docker架构的组成部分。**

**答：** Docker架构中的组件如下：

- **主机：**此组件包含 Docker 守护程序、镜像和容器。当 Docker 守护进程与注册表建立链接时，Docker 镜像充当 Docker 容器中保存的应用程序的元数据。
- **客户端：** Docker 客户端组件运行操作以设置与 Docker 主机的通信。
- **Registry：**这个 Docker 组件用于存储 Docker 镜像。Docker Hub 和 Docker Cloud 是公共注册表，任何人都可以使用。

#### **Docker常见的面试题有哪些：详细解释Docker Registry。**

**答：**存储所有 Docker 镜像的地方称为 Docker 注册表。Docker Hub 是一个公共注册中心，它是这些镜像的默认存储。另一个公共注册中心是 Docker Cloud。Docker Hub 是最重要的镜像容器公共仓库，由大量开发人员和许多个人贡献者持续维护。

#### **问题：简要说明 Docker Container 的生活方式。**

**答：** Docker Container 的生命周期是：

- 容器的创建
- 运行容器
- 暂停容器
- 取消暂停容器
- 启动容器
- 停止容器
- 重启容器
- 杀死容器
- 销毁容器

#### **问题：命名一些重要的 Docker 命令**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**以下是一些重要的 Docker 命令：

- build：为Docker构建一个镜像文件
- create：用于创建新容器
- kill：杀死一个容器
- dockerd：用于启动 Docker 守护进程
- commit：用于从容器更改创建新镜像

#### **问题：Docker 中的命名空间是什么。**

**答：** Docker Namespaces 是一种提供隔离工作区的技术，称为容器。一旦容器启动，就会为所述容器创建一组命名空间。这些命名空间为这些容器提供了一层隔离，因为每个容器在不同的命名空间中运行，其访问仅限于提到的命名空间。

#### **问题：什么是 Docker Swarm？**

**答：** Docker Swarm 是用于集群和调度 Docker 容器的原生工具。使用 Docker Swarm，开发人员和 IT 主管可以轻松地在 Docker 或单独的虚拟系统 (VS) 中建立和管理一堆节点。

#### **问题：如何识别Docker Container的状态？**

**答：**要识别 Docker 容器的状态，应运行以下命令

“ **docker ps-a。**”

此命令将提供所有可用 Docker 容器的列表以及主机上的相应状态。从列表中，人们可以很容易地确定预期的容器以检查其状态。

#### **问题：什么是 Docker Image 和 Docker Run 命令？**

**答：** Docker 映像是一组文件和一组参数，这些参数允许创建在不同容器中作为隔离进程运行的实例。映像基本上是使用应用程序的完整和可执行版本的指令构建的，该版本依赖于主机操作系统内核。Docker run 命令可用于创建名为容器的实例，该实例可使用 Docker 映像运行。当 Docker 用户运行一个镜像时，它成为该容器的一个或多个实例。

#### **问题：陈述 Docker 的功能和应用。**

**答：**以下是实现Docker的一些功能和应用：

- 它使配置更简单，并提供了基础设施级别的轻松配置
- 通过帮助开发人员专注于业务逻辑，它减少了开发时间并提高了生产力
- 它放大了提供有用功能的调试功能
- 它允许隔离应用程序
- 它以容器化的形式减少了多台服务器的使用
- 它有利于在操作系统级别的快速部署

#### **问题：什么是 Docker 对象？**

**答：** Docker 镜像、服务和容器被称为 Docker 对象。

- **镜像**：包含创建 Docker 容器说明的只读模板
- **Containers** : 一个可运行的镜像实例
- **服务**：它允许在各种 Docker 守护进程之间扩展容器，这些守护进程都作为一个群一起工作。

其他 Docker 对象包括网络和卷。

#### **问题：Docker Container、Stateless 和 Stateful 应用哪个更适合？**

**答：**无状态应用程序应该优先于 Docker 容器的有状态应用程序。我们可以从我们的应用程序中创建一个容器并取出应用程序的可配置状态参数。一旦它是一个，我们就可以运行具有不同生产参数和其他环境的同一个容器。通过无状态应用程序，我们可以在不同的场景中重用相同的镜像。当涉及到 Docker 容器时，扩展无状态应用程序也比有状态应用程序更容易。

#### **问题：解释Dockerfile的使用。**

**答：** Dockerfile 包含了很多在 Docker 上传递的指令，使镜像的构建过程成为可能，可以自动读取这些指令。它也可以称为包含用户可以在命令行上调用以创建镜像的所有可能命令的文本文档。

#### **问题：Docker 中默认哪些网络可用？**

**答：** Docker 中可用的默认网络是：

- **bridge** : 如果网络未另行指定，则容器连接到的默认网络
- **none**：连接到缺少网络接口的特定于容器的网络堆栈
- **host**：连接到主机的网络堆栈

#### **Docker常见的面试题有哪些：列出存储在 Git 存储库中的 Dockerized 应用程序的部署过程中的步骤。**

**答：**虽然部署过程会随着你的生产环境而变化，但基本的部署过程将具有以下内容：

- 通过位于代码目录中的 Docker Build 构建应用程序
- 执行镜像测试
- 将新镜像推送到注册表 docker
- 通知远程应用服务器从注册表中获取镜像并运行它
- HTTP 代理中的端口交换
- 停止旧容器

#### **问题：解释 Docker 与其他容器技术的不同之处。**

**答：** Docker 是最新的容器技术之一，并且已经成为最受欢迎的技术之一。内置于云时代，Docker 带来了许多旧容器技术所缺少的新功能。Docker 最好的特性之一是它可以在任何基础设施上运行，无论是你的家用机器还是云。

通过 Docker，现在可以在旧服务器上运行更多应用程序，并且还允许进程打包和发送程序。Docker 还有一个 Container Hub 充当容器的存储库，易于下载和使用。此外，这些容器也可以由你的应用程序共享。它也有很好的文档记录，这使得它比其他容器技术更好。

#### **Docker常见的面试题和答案合集：如果退出 Docker 容器，数据会丢失吗？**

**答：** Docker Container 退出时，不会发生数据丢失，因为应用程序将所有数据写入磁盘，仅用于保存。这个过程一直重复，直到并且除非容器被明确删除。此外，Docker 容器的文件系统即使在 Docker 容器停止后仍然存在。

#### **问题：Docker 在生产中是如何监控的？**

**答：** ;要在生产中监控 Docker，可以使用 Docker stats 和 Docker events 等工具。通过这些工具，人们可以获得有关重要统计数据的报告。一旦使用容器 ID 调用 Docker 统计信息，它就会返回容器的 CPU 和内存使用情况。它类似于Linux 中的top 命令。另一方面，Docker 事件是用于查看 Docker 守护进程中正在进行的活动列表的命令。其中一些事件被附加、提交、重命名、销毁、死亡等等。还可以选择过滤他们感兴趣的事件。

#### **问题：阐明 Docker 使用的工作流程。**

**答：**下面简单介绍一下Docker使用的工作流程：

- 由于Dockerfile是镜像的源代码，一切从它开始
- 创建后，Dockerfile 将用于构建容器的映像。这个镜像只是Dockerfile的编译版本
- 然后使用注册表重新分发此映像，注册表就像一个映像存储库。
- 此外，该映像可用于运行容器。容器在运行时与没有管理程序的 VM 非常相似。

#### **问题：解释“Docker run”和“Docker created”命令之间的差异。**

**回答：;** Docker run 和 Docker create 之间的主要区别在于，如果你使用后者，则创建的容器处于“停止”状态。此外，Docker 创建可用于存储和输出容器 ID 以备后用。最好的方法是将“docker run”与 —cidfile FILE_NAME 一起使用，因为再次运行它不允许覆盖文件。

#### **问题：什么是虚拟化？**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**在早期，虚拟化被称为一种逻辑划分大型机以允许多个应用程序同时运行的方法。但是随着时间的推移，行业能够允许在一个基于 x86 的系统上同时运行多个操作系统，虚拟化的含义发生了很大的变化。

净结果？虚拟化允许用户在同一硬件上运行两个不同的操作系统。虽然主要操作系统是管理员，但每个客户操作系统都会经历诸如引导、加载内核等过程。它也非常适合安全性，因为可能不允许每个来宾操作系统完全访问主机操作系统，从而导致数据泄露。

主要有三种类型的虚拟化：

- 半虚拟化
- 仿真
- 基于容器的虚拟化

#### **问题：注册中心和存储库有什么区别？**

**答：** Docker Registry 是用于托管和分发映像的服务，而 Docker Hub 是默认注册表。另一方面，Docker Repository 是相关 Docker 镜像的集合。也就是说，它们具有相同的名称但具有不同的标签。

#### **问题：Docker 中的 compose 文件可以使用 JSON 代替 YAML 吗？如果是，如何？**

**答：** 是的，Docker 撰写文件可以使用 JSON 代替 YAML。要使用 JSON 文件进行组合，文件名应指定如下：

“docker-compose -f docker-compose.json up。”

#### **问题：解释Dockerfile中的CMD和ENTRYPOINT？**

**答：** 在 Dockerfile 中，CMD 和 ENTRYPOINT 指令都定义了运行容器时将执行的命令。对于他们的合作，有一些规则，比如：

- Dockerfile 应至少指定一个来自 CMD 或 ENTRYPOINT 的命令
- 将容器用作可执行文件时，需要定义 ENTRYPOINT
- 当使用替代参数运行容器时，CMD 将被覆盖

#### **问题：解释使用 Docker 在 Linux 容器内运行应用程序的过程**

**答：** 以下是如何使用 Docker 在 Linux 容器内运行应用程序的步骤

- 安装并运行 Docker
- 从 Docker 中心获取 Fedora 21（基于 Linux 的操作系统）基础镜像
- 在 Docker 基础映像中加载你的应用程序
- 以交互模式使用新镜像运行容器
- 检查系统中的容器
- 启动或停止 Docker 容器
- 进入 Docker 容器
- 删除容器或镜像

#### **问题：什么是管理程序？**

**答：**虚拟机监视器，称为 Hypervisor，是用于创建和运行虚拟机的软件。它允许一台主机支持多个来宾 VM。这是通过共享内存、处理等资源来完成的，从而减少内存、空间和维护需求。有两种类型的管理程序：

- Type I：就像是运行在主机硬件上的轻量级操作系统。
- 类型 II：像操作系统上的软件程序一样运行。

#### **问题：解释容器化？**

**答：** Docker 容器包含不同的软件包，例如代码、系统工具、库、运行时和运行应用程序所需的设置。应用程序驻留在 Docker 引擎层之上。这称为容器化。无论环境如何，它都有助于应用程序顺利运行。

#### **问题：解释容器化和虚拟化之间的主要区别。**

**答：**通过虚拟化，你可以在单个物理服务器上运行多个操作系统。容器化发生在同一操作系统上，其中应用程序被打包为容器并在单个服务器或 VM 下运行。

![50个Docker常见的面试题和答案合集介绍](https://hackr.io/blog/media/containerization-vs-virtualization.png)

#### **问题：解释 Docker 镜像、Docker Hub、Docker 文件？**

**答：** Docker 镜像：这些是包含多个层的文件，用于在 Docker 容器内执行代码。镜像是根据应用程序可执行版本的指令构建的。镜像通过允许缓存每个步骤来加速 docker 构建。

Docker hub：它是一种在团队内查找和共享容器镜像的服务。你可以推送和拉取镜像，访问容器镜像的私有存储库，从 Github（或 Bitbucket）自动构建容器镜像，并将它们推送到 DockerHub。Docker 本身提供服务。[阅读更多](https://www.lsbin.com/wp-content/themes/begin%20lts/inc/go.php?url=https://docs.docker.com/docker-hub/)。

Docker 文件：用于构建镜像的文本文档。它包含构建映像的说明和命令。Docker 读取命令并自动组装镜像。

#### **Docker常见的面试题和答案合集：如何检查Docker Client和Docker Server版本？**

**答：**我们可以使用命令docker version [options]来查看docker版本。如果我们不提供任何选项，则 Docker 会提供有关客户端和服务器的所有版本相关信息。例如，要仅获取服务器版本，请使用：

```
$ docker version --format '{{.Server.Version}}'
```

#### **问题： 解释一下 Docker Repository 的登录过程？**

**答：**要登录到 Docker 存储库，请使用以下命令：

```
docker login [OPTIONS] [SERVER]
```

例如，要登录自托管（本地）注册中心，你可以添加服务器名称：

```
$ docker login localhost:8080
```

#### **Docker常见的面试题有哪些：解释各种 Docker 基本命令？**

答：一些 Docker 命令是：

- docker push：将存储库或镜像推送到注册表
- docker run：在新容器中运行命令
- docker pull：从注册表中拉取存储库或镜像
- docker start：启动一个或多个容器
- docker stop：停止运行容器
- docker search：在 docker hub 中搜索镜像
- docker commit：提交新镜像

#### **问题：解释一下 Docker Container 与其他容器化方法的区别？**

**答：** Docker 容器可以轻松部署到任何云平台。此外，开发人员可以更快地创建可立即运行的容器化应用程序，并轻松管理和部署应用程序。容器也可以与应用程序共享。这些功能在其他容器化方法中不存在。

#### **问题：列出运行Docker的平台。**

**答：**它可以在 Windows (x86-64) 和 Linux（在 x86-64、ARM 和其他 CPU 架构上）、s390x、ppc64le 上运行。

#### **问题：容器是否可以自行重启？**

**回答：**是的，这是可能的。Docker 定义了某些策略来重新启动容器。这些是关闭的：如果容器停止或失败，则不会重新启动，

- On-failure：容器仅在非用户原因发生的故障时重新启动，
- 除非停止：容器仅在用户执行停止它的命令时重新启动，
- 始终：无论出现错误或其他问题，始终重新启动容器。

命令是：

```
$ docker run -dit — restart [unless-stopped|off|on-failure|always] [CONTAINER]
```

#### **问：云有没有可能超越容器化的使用？**

**答：**在这类问题中，你可以发表你的个人意见。例如，根据我的理解，虽然云是一个很好的竞争对手，但它不能取代容器化。大多数公司正在同时使用云和容器化，以充分利用这两种技术。

#### **问题：Docker Container 有哪些可能的状态？**

**Docker面试题解析：** Docker容器的不同状态是：

- 已创建 - 已创建但未处于活动状态的容器。
- 正在重新启动 - 正在重新启动的容器。
- 运行 - 运行容器。
- 暂停 - 其进程已暂停的容器。
- 退出 - 运行并完成的容器。
- Dead - 守护进程尝试停止但未能停止的容器。

#### **问题：解释容器编排以及我们为什么需要使用它？**

**答：**容器编排有助于管理在动态和大型环境中运行的容器。容器编排可以控制和自动化以下任务：

- 容器的供应和部署，
- 负载均衡，
- 容器之间的资源分配，
- 监控容器和主机的健康状况，
- 容器的缩放，
- 当主机不可用或缺乏资源时，将容器从一台主机切换到另一台主机。

#### **问题：解释内存交换标志？**

内存交换标志是一个修饰符标志，允许容器在使用完所有可用 RAM 后将多余的内存需求写入磁盘。仅当设置了 --memory 标志时才设置它。例如，如果 memory = "400m" 并且 memory-swap = "1g"，那么容器可以使用 400m 的内存和 600m (1g-400m) 的交换。

#### **Docker常见的面试题和答案合集：docker 卷存储在哪里？**

**答：**卷由 Docker 创建和管理（不能被非 Docker 进程访问）并存储在 Docker 主机文件系统的一部分中：/var/lib/docker/volumes/。卷是在 Docker 中持久化数据的最有效方式。

#### **问题：解释各种 Docker 高级命令？**

**答：**一些重要的 Docker 命令是：

- docker -version：了解安装的docker版本。语法，Docker --version
- docker ps：列出所有正在运行的 docker 容器以及容器详细信息。语法：docker ps
- docker ps -a：列出所有容器，包括那些正在运行、停止、退出的容器以及详细信息。语法：docker ps -a
- docker exec：访问容器并在该容器内运行命令。语法：docker exec [选项]
- docker build：从 Dockerfile 构建镜像。语法：docker build [options] path|URL
- docker rm：删除具有上述容器 ID 的容器。语法：docker rm <container_id>
- docker rmi：删除带有提到的镜像 ID 的 docker 镜像。语法：docker rmi <image_id>
- docker info：获取系统上安装的 Docker 的详细信息，如容器数量、镜像、运行、暂停、停止、服务器版本、容量、运行时间、内核版本、总内存等。 语法：docker info;
- docker cp：将文件从 docker 容器复制到本地系统。语法：docker cp <source_path> <dest_path>
- docker history：显示带有提到的镜像名称的 docker 镜像的历史记录。语法：docker history <img_name>

#### **问题：使用 Systemd 控制 Docker 的命令是什么？**

**答：**要启动 Docker 守护进程，许多 Linux 发行版都使用该系统。要启动服务，请使用命令 systemct1。如果 systemct1 不可用，则使用 service 命令。

```
$ sudo systemctl start docker 
$ sudo service docker start
```

要在引导期间启用和禁用守护程序，请使用：

```
$ sudo systemctl enable docker 
$ sudo systemctl disable docker
```

要修改守护程序选项，请使用：;

```
$ sudo systemctl edit docker
```

查看与 Docker 服务相关的日志：

```
$ journalctl -u docker;
```

#### **问题：扩展 Docker 容器的过程是什么**

答：Docker 容器可以使用 Docker-decompose 的 scale 命令进行缩放。过程如下：

- 使用以下方法扩展服务器容器并启动服务器的“n”个实例：

```
$] docker-compose --file docker-compose-run-srvr.yml scale < service_name > = < n >
```

在上面的命令中，服务名称在 docker-compose-run-srvr.yml 中定义，并将其缩放为“n”倍，其中 n 可以是任何整数值。

- Docker 容器扩容后，要查看容器详细信息，请执行以下命令：

```
$] docker ps -a
```

#### **Docker常见的面试题有哪些：介绍一下Docker容器生命周期的步骤。**

**答：**步骤如下：

- 创建容器： docker create --name <container-name> <image-name>
- 运行 docker 容器： docker run -it -d --name <container-name> <image-name> bash
- 暂停容器： docker pause <container-id/name>
- 取消暂停容器： docker unpause <container-id/name>
- 启动容器：docker start <container-id/name>
- 停止容器： docker stop <container-id/name>
- 重启容器： docker restart <container-id/name>
- 杀死容器： docker kill <container-id/name>
- 销毁容器：docker rm <container-id/name>

#### **问题：什么是CNM？**

**答：** CNM 或容器网络模型是一种规范，它正式定义了为容器提供网络所需的步骤，同时保持用于支持多个网络驱动程序的抽象。CNM 建立在三个组件之上，即沙箱、端点和网络。

#### **问题：Docker 中有哪些不同类型的挂载类型？**

**答：**三种类型是：

- 绑定挂载：这些可以存储在主机系统的任何地方
- 卷挂载：它们由 Docker 管理并存储在主机文件系统的一部分中。
- tmpfs mount：它们存储在主机系统的内存中。这些挂载永远不能写入主机的文件系统。

#### **问题：解释Docker Trusted Registry？**

**答：**它是一个镜像存储解决方案，用于安全地存储和管理 Docker 镜像。Docker Trusted Registry 可在本地或私有云中使用。DTR 可在 CI/CD 过程中用于构建、交付和运行应用程序。DTR 具有高可用性、高效性并且具有内置的访问控制。

#### **问题：Docker_Host 的目的是什么？**

**答：** Docker_host 指定用于连接到 Docker API 的 URL 或 Unix 套接字路径。默认值为：UNIX://var/run/docker.sock

要连接到远程主机，请提供 TCP 连接字符串作为 TCP://192.0.1.20:3230

#### **问题：是否可以在同一主机上运行 Compose 文件的多个副本？如何？**

**Docker面试题解析：**这是通过使用 docker-compose 完成的。使用 Docker Compose，我们可以使用 YAML 文件来配置应用程序的服务。在此之后，只需一个命令，就可以创建和启动所有服务。要使用 Compose，请按照以下步骤操作：

- 在 Dockerfile 中定义应用环境，以便它可以在任何地方复制
- 在 docker-compose.yml 文件中定义应用程序的所有服务。
- 运行 docker-compose up 以创建并启动整个应用程序。

#### **问题：解释 Docker 对象标签。**

**答：** Docker 对象标签是一个键值对，以字符串形式存储。我们可以使用标签应用元数据。标签可以应用于 Docker 对象，如镜像、容器、卷、网络、本地守护进程、swarm 节点和服务。每个对象的键值对应该是唯一的。标签在对象的整个生命周期内都是静态的。

## Docker常见的面试题和答案合集**概括**

所以这是 Docker 面试中最热门的问题列表。你知道几个答案？在下面的评论窗口中告诉我们。此外，请查看我们的最佳 Docker 教程，由社区提交和推荐。Docker 于 2013 年发布，是用于在“容器”中打包、运送和运行应用程序的有用工具。由于谷歌、亚马逊和 VMware 等许多大公司都将 Docker 作为首选容器技术，现在正是学习该工具并以此为业的好时机。如果你想这样做，下面是你需要知道的 Docker 面试的主要问题。

## **热门的Docker常见的面试题和答案合集**

在这里，我们列出了一份 Docker 顶级面试问题的综合列表：

#### **问题：解释 Docker 容器？**

**答：**容器是保存代码及其所有依赖项的软件的基本单元，目的是使应用程序从一个计算生态系统平稳、快速、可靠地运行到另一个计算生态系统。可以使用 Docker 映像创建 Docker 容器。它是软件的可执行包，其中包含运行应用程序所需的一切，包括系统工具、库、代码、运行时和设置。

#### **问题：解释Docker架构的组成部分。**

**答：** Docker架构中的组件如下：

- **主机：**此组件包含 Docker 守护程序、镜像和容器。当 Docker 守护进程与注册表建立链接时，Docker 镜像充当 Docker 容器中保存的应用程序的元数据。
- **客户端：** Docker 客户端组件运行操作以设置与 Docker 主机的通信。
- **Registry：**这个 Docker 组件用于存储 Docker 镜像。Docker Hub 和 Docker Cloud 是公共注册表，任何人都可以使用。

#### **Docker常见的面试题有哪些：详细解释Docker Registry。**

**答：**存储所有 Docker 镜像的地方称为 Docker 注册表。Docker Hub 是一个公共注册中心，它是这些镜像的默认存储。另一个公共注册中心是 Docker Cloud。Docker Hub 是最重要的镜像容器公共仓库，由大量开发人员和许多个人贡献者持续维护。

#### **问题：简要说明 Docker Container 的生活方式。**

**答：** Docker Container 的生命周期是：

- 容器的创建
- 运行容器
- 暂停容器
- 取消暂停容器
- 启动容器
- 停止容器
- 重启容器
- 杀死容器
- 销毁容器

#### **问题：命名一些重要的 Docker 命令**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**以下是一些重要的 Docker 命令：

- build：为Docker构建一个镜像文件
- create：用于创建新容器
- kill：杀死一个容器
- dockerd：用于启动 Docker 守护进程
- commit：用于从容器更改创建新镜像

#### **问题：Docker 中的命名空间是什么。**

**答：** Docker Namespaces 是一种提供隔离工作区的技术，称为容器。一旦容器启动，就会为所述容器创建一组命名空间。这些命名空间为这些容器提供了一层隔离，因为每个容器在不同的命名空间中运行，其访问仅限于提到的命名空间。

#### **问题：什么是 Docker Swarm？**

**答：** Docker Swarm 是用于集群和调度 Docker 容器的原生工具。使用 Docker Swarm，开发人员和 IT 主管可以轻松地在 Docker 或单独的虚拟系统 (VS) 中建立和管理一堆节点。

#### **问题：如何识别Docker Container的状态？**

**答：**要识别 Docker 容器的状态，应运行以下命令

“ **docker ps-a。**”

此命令将提供所有可用 Docker 容器的列表以及主机上的相应状态。从列表中，人们可以很容易地确定预期的容器以检查其状态。

#### **问题：什么是 Docker Image 和 Docker Run 命令？**

**答：** Docker 映像是一组文件和一组参数，这些参数允许创建在不同容器中作为隔离进程运行的实例。映像基本上是使用应用程序的完整和可执行版本的指令构建的，该版本依赖于主机操作系统内核。Docker run 命令可用于创建名为容器的实例，该实例可使用 Docker 映像运行。当 Docker 用户运行一个镜像时，它成为该容器的一个或多个实例。

#### **问题：陈述 Docker 的功能和应用。**

**答：**以下是实现Docker的一些功能和应用：

- 它使配置更简单，并提供了基础设施级别的轻松配置
- 通过帮助开发人员专注于业务逻辑，它减少了开发时间并提高了生产力
- 它放大了提供有用功能的调试功能
- 它允许隔离应用程序
- 它以容器化的形式减少了多台服务器的使用
- 它有利于在操作系统级别的快速部署

#### **问题：什么是 Docker 对象？**

**答：** Docker 镜像、服务和容器被称为 Docker 对象。

- **镜像**：包含创建 Docker 容器说明的只读模板
- **Containers** : 一个可运行的镜像实例
- **服务**：它允许在各种 Docker 守护进程之间扩展容器，这些守护进程都作为一个群一起工作。

其他 Docker 对象包括网络和卷。

#### **问题：Docker Container、Stateless 和 Stateful 应用哪个更适合？**

**答：**无状态应用程序应该优先于 Docker 容器的有状态应用程序。我们可以从我们的应用程序中创建一个容器并取出应用程序的可配置状态参数。一旦它是一个，我们就可以运行具有不同生产参数和其他环境的同一个容器。通过无状态应用程序，我们可以在不同的场景中重用相同的镜像。当涉及到 Docker 容器时，扩展无状态应用程序也比有状态应用程序更容易。

#### **问题：解释Dockerfile的使用。**

**答：** Dockerfile 包含了很多在 Docker 上传递的指令，使镜像的构建过程成为可能，可以自动读取这些指令。它也可以称为包含用户可以在命令行上调用以创建镜像的所有可能命令的文本文档。

#### **问题：Docker 中默认哪些网络可用？**

**答：** Docker 中可用的默认网络是：

- **bridge** : 如果网络未另行指定，则容器连接到的默认网络
- **none**：连接到缺少网络接口的特定于容器的网络堆栈
- **host**：连接到主机的网络堆栈

#### **Docker常见的面试题有哪些：列出存储在 Git 存储库中的 Dockerized 应用程序的部署过程中的步骤。**

**答：**虽然部署过程会随着你的生产环境而变化，但基本的部署过程将具有以下内容：

- 通过位于代码目录中的 Docker Build 构建应用程序
- 执行镜像测试
- 将新镜像推送到注册表 docker
- 通知远程应用服务器从注册表中获取镜像并运行它
- HTTP 代理中的端口交换
- 停止旧容器

#### **问题：解释 Docker 与其他容器技术的不同之处。**

**答：** Docker 是最新的容器技术之一，并且已经成为最受欢迎的技术之一。内置于云时代，Docker 带来了许多旧容器技术所缺少的新功能。Docker 最好的特性之一是它可以在任何基础设施上运行，无论是你的家用机器还是云。

通过 Docker，现在可以在旧服务器上运行更多应用程序，并且还允许进程打包和发送程序。Docker 还有一个 Container Hub 充当容器的存储库，易于下载和使用。此外，这些容器也可以由你的应用程序共享。它也有很好的文档记录，这使得它比其他容器技术更好。

#### **Docker常见的面试题和答案合集：如果退出 Docker 容器，数据会丢失吗？**

**答：** Docker Container 退出时，不会发生数据丢失，因为应用程序将所有数据写入磁盘，仅用于保存。这个过程一直重复，直到并且除非容器被明确删除。此外，Docker 容器的文件系统即使在 Docker 容器停止后仍然存在。

#### **问题：Docker 在生产中是如何监控的？**

**答：** ;要在生产中监控 Docker，可以使用 Docker stats 和 Docker events 等工具。通过这些工具，人们可以获得有关重要统计数据的报告。一旦使用容器 ID 调用 Docker 统计信息，它就会返回容器的 CPU 和内存使用情况。它类似于Linux 中的top 命令。另一方面，Docker 事件是用于查看 Docker 守护进程中正在进行的活动列表的命令。其中一些事件被附加、提交、重命名、销毁、死亡等等。还可以选择过滤他们感兴趣的事件。

#### **问题：阐明 Docker 使用的工作流程。**

**答：**下面简单介绍一下Docker使用的工作流程：

- 由于Dockerfile是镜像的源代码，一切从它开始
- 创建后，Dockerfile 将用于构建容器的映像。这个镜像只是Dockerfile的编译版本
- 然后使用注册表重新分发此映像，注册表就像一个映像存储库。
- 此外，该映像可用于运行容器。容器在运行时与没有管理程序的 VM 非常相似。

#### **问题：解释“Docker run”和“Docker created”命令之间的差异。**

**回答：;** Docker run 和 Docker create 之间的主要区别在于，如果你使用后者，则创建的容器处于“停止”状态。此外，Docker 创建可用于存储和输出容器 ID 以备后用。最好的方法是将“docker run”与 —cidfile FILE_NAME 一起使用，因为再次运行它不允许覆盖文件。

#### **问题：什么是虚拟化？**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**在早期，虚拟化被称为一种逻辑划分大型机以允许多个应用程序同时运行的方法。但是随着时间的推移，行业能够允许在一个基于 x86 的系统上同时运行多个操作系统，虚拟化的含义发生了很大的变化。

净结果？虚拟化允许用户在同一硬件上运行两个不同的操作系统。虽然主要操作系统是管理员，但每个客户操作系统都会经历诸如引导、加载内核等过程。它也非常适合安全性，因为可能不允许每个来宾操作系统完全访问主机操作系统，从而导致数据泄露。

主要有三种类型的虚拟化：

- 半虚拟化
- 仿真
- 基于容器的虚拟化

#### **问题：注册中心和存储库有什么区别？**

**答：** Docker Registry 是用于托管和分发映像的服务，而 Docker Hub 是默认注册表。另一方面，Docker Repository 是相关 Docker 镜像的集合。也就是说，它们具有相同的名称但具有不同的标签。

#### **问题：Docker 中的 compose 文件可以使用 JSON 代替 YAML 吗？如果是，如何？**

**答：** 是的，Docker 撰写文件可以使用 JSON 代替 YAML。要使用 JSON 文件进行组合，文件名应指定如下：

“docker-compose -f docker-compose.json up。”

#### **问题：解释Dockerfile中的CMD和ENTRYPOINT？**

**答：** 在 Dockerfile 中，CMD 和 ENTRYPOINT 指令都定义了运行容器时将执行的命令。对于他们的合作，有一些规则，比如：

- Dockerfile 应至少指定一个来自 CMD 或 ENTRYPOINT 的命令
- 将容器用作可执行文件时，需要定义 ENTRYPOINT
- 当使用替代参数运行容器时，CMD 将被覆盖

#### **问题：解释使用 Docker 在 Linux 容器内运行应用程序的过程**

**答：** 以下是如何使用 Docker 在 Linux 容器内运行应用程序的步骤

- 安装并运行 Docker
- 从 Docker 中心获取 Fedora 21（基于 Linux 的操作系统）基础镜像
- 在 Docker 基础映像中加载你的应用程序
- 以交互模式使用新镜像运行容器
- 检查系统中的容器
- 启动或停止 Docker 容器
- 进入 Docker 容器
- 删除容器或镜像

#### **问题：什么是管理程序？**

**答：**虚拟机监视器，称为 Hypervisor，是用于创建和运行虚拟机的软件。它允许一台主机支持多个来宾 VM。这是通过共享内存、处理等资源来完成的，从而减少内存、空间和维护需求。有两种类型的管理程序：

- Type I：就像是运行在主机硬件上的轻量级操作系统。
- 类型 II：像操作系统上的软件程序一样运行。

#### **问题：解释容器化？**

**答：** Docker 容器包含不同的软件包，例如代码、系统工具、库、运行时和运行应用程序所需的设置。应用程序驻留在 Docker 引擎层之上。这称为容器化。无论环境如何，它都有助于应用程序顺利运行。

#### **问题：解释容器化和虚拟化之间的主要区别。**

**答：**通过虚拟化，你可以在单个物理服务器上运行多个操作系统。容器化发生在同一操作系统上，其中应用程序被打包为容器并在单个服务器或 VM 下运行。

![50个Docker常见的面试题和答案合集介绍](https://hackr.io/blog/media/containerization-vs-virtualization.png)

#### **问题：解释 Docker 镜像、Docker Hub、Docker 文件？**

**答：** Docker 镜像：这些是包含多个层的文件，用于在 Docker 容器内执行代码。镜像是根据应用程序可执行版本的指令构建的。镜像通过允许缓存每个步骤来加速 docker 构建。

Docker hub：它是一种在团队内查找和共享容器镜像的服务。你可以推送和拉取镜像，访问容器镜像的私有存储库，从 Github（或 Bitbucket）自动构建容器镜像，并将它们推送到 DockerHub。Docker 本身提供服务。[阅读更多](https://www.lsbin.com/wp-content/themes/begin%20lts/inc/go.php?url=https://docs.docker.com/docker-hub/)。

Docker 文件：用于构建镜像的文本文档。它包含构建映像的说明和命令。Docker 读取命令并自动组装镜像。

#### **Docker常见的面试题和答案合集：如何检查Docker Client和Docker Server版本？**

**答：**我们可以使用命令docker version [options]来查看docker版本。如果我们不提供任何选项，则 Docker 会提供有关客户端和服务器的所有版本相关信息。例如，要仅获取服务器版本，请使用：

```
$ docker version --format '{{.Server.Version}}'
```

#### **问题： 解释一下 Docker Repository 的登录过程？**

**答：**要登录到 Docker 存储库，请使用以下命令：

```
docker login [OPTIONS] [SERVER]
```

例如，要登录自托管（本地）注册中心，你可以添加服务器名称：

```
$ docker login localhost:8080
```

#### **Docker常见的面试题有哪些：解释各种 Docker 基本命令？**

答：一些 Docker 命令是：

- docker push：将存储库或镜像推送到注册表
- docker run：在新容器中运行命令
- docker pull：从注册表中拉取存储库或镜像
- docker start：启动一个或多个容器
- docker stop：停止运行容器
- docker search：在 docker hub 中搜索镜像
- docker commit：提交新镜像

#### **问题：解释一下 Docker Container 与其他容器化方法的区别？**

**答：** Docker 容器可以轻松部署到任何云平台。此外，开发人员可以更快地创建可立即运行的容器化应用程序，并轻松管理和部署应用程序。容器也可以与应用程序共享。这些功能在其他容器化方法中不存在。

#### **问题：列出运行Docker的平台。**

**答：**它可以在 Windows (x86-64) 和 Linux（在 x86-64、ARM 和其他 CPU 架构上）、s390x、ppc64le 上运行。

#### **问题：容器是否可以自行重启？**

**回答：**是的，这是可能的。Docker 定义了某些策略来重新启动容器。这些是关闭的：如果容器停止或失败，则不会重新启动，

- On-failure：容器仅在非用户原因发生的故障时重新启动，
- 除非停止：容器仅在用户执行停止它的命令时重新启动，
- 始终：无论出现错误或其他问题，始终重新启动容器。

命令是：

```
$ docker run -dit — restart [unless-stopped|off|on-failure|always] [CONTAINER]
```

#### **问：云有没有可能超越容器化的使用？**

**答：**在这类问题中，你可以发表你的个人意见。例如，根据我的理解，虽然云是一个很好的竞争对手，但它不能取代容器化。大多数公司正在同时使用云和容器化，以充分利用这两种技术。

#### **问题：Docker Container 有哪些可能的状态？**

**Docker面试题解析：** Docker容器的不同状态是：

- 已创建 - 已创建但未处于活动状态的容器。
- 正在重新启动 - 正在重新启动的容器。
- 运行 - 运行容器。
- 暂停 - 其进程已暂停的容器。
- 退出 - 运行并完成的容器。
- Dead - 守护进程尝试停止但未能停止的容器。

#### **问题：解释容器编排以及我们为什么需要使用它？**

**答：**容器编排有助于管理在动态和大型环境中运行的容器。容器编排可以控制和自动化以下任务：

- 容器的供应和部署，
- 负载均衡，
- 容器之间的资源分配，
- 监控容器和主机的健康状况，
- 容器的缩放，
- 当主机不可用或缺乏资源时，将容器从一台主机切换到另一台主机。

#### **问题：解释内存交换标志？**

内存交换标志是一个修饰符标志，允许容器在使用完所有可用 RAM 后将多余的内存需求写入磁盘。仅当设置了 --memory 标志时才设置它。例如，如果 memory = "400m" 并且 memory-swap = "1g"，那么容器可以使用 400m 的内存和 600m (1g-400m) 的交换。

#### **Docker常见的面试题和答案合集：docker 卷存储在哪里？**

**答：**卷由 Docker 创建和管理（不能被非 Docker 进程访问）并存储在 Docker 主机文件系统的一部分中：/var/lib/docker/volumes/。卷是在 Docker 中持久化数据的最有效方式。

#### **问题：解释各种 Docker 高级命令？**

**答：**一些重要的 Docker 命令是：

- docker -version：了解安装的docker版本。语法，Docker --version
- docker ps：列出所有正在运行的 docker 容器以及容器详细信息。语法：docker ps
- docker ps -a：列出所有容器，包括那些正在运行、停止、退出的容器以及详细信息。语法：docker ps -a
- docker exec：访问容器并在该容器内运行命令。语法：docker exec [选项]
- docker build：从 Dockerfile 构建镜像。语法：docker build [options] path|URL
- docker rm：删除具有上述容器 ID 的容器。语法：docker rm <container_id>
- docker rmi：删除带有提到的镜像 ID 的 docker 镜像。语法：docker rmi <image_id>
- docker info：获取系统上安装的 Docker 的详细信息，如容器数量、镜像、运行、暂停、停止、服务器版本、容量、运行时间、内核版本、总内存等。 语法：docker info;
- docker cp：将文件从 docker 容器复制到本地系统。语法：docker cp <source_path> <dest_path>
- docker history：显示带有提到的镜像名称的 docker 镜像的历史记录。语法：docker history <img_name>

#### **问题：使用 Systemd 控制 Docker 的命令是什么？**

**答：**要启动 Docker 守护进程，许多 Linux 发行版都使用该系统。要启动服务，请使用命令 systemct1。如果 systemct1 不可用，则使用 service 命令。

```
$ sudo systemctl start docker 
$ sudo service docker start
```

要在引导期间启用和禁用守护程序，请使用：

```
$ sudo systemctl enable docker 
$ sudo systemctl disable docker
```

要修改守护程序选项，请使用：;

```
$ sudo systemctl edit docker
```

查看与 Docker 服务相关的日志：

```
$ journalctl -u docker;
```

#### **问题：扩展 Docker 容器的过程是什么**

答：Docker 容器可以使用 Docker-decompose 的 scale 命令进行缩放。过程如下：

- 使用以下方法扩展服务器容器并启动服务器的“n”个实例：

```
$] docker-compose --file docker-compose-run-srvr.yml scale < service_name > = < n >
```

在上面的命令中，服务名称在 docker-compose-run-srvr.yml 中定义，并将其缩放为“n”倍，其中 n 可以是任何整数值。

- Docker 容器扩容后，要查看容器详细信息，请执行以下命令：

```
$] docker ps -a
```

#### **Docker常见的面试题有哪些：介绍一下Docker容器生命周期的步骤。**

**答：**步骤如下：

- 创建容器： docker create --name <container-name> <image-name>
- 运行 docker 容器： docker run -it -d --name <container-name> <image-name> bash
- 暂停容器： docker pause <container-id/name>
- 取消暂停容器： docker unpause <container-id/name>
- 启动容器：docker start <container-id/name>
- 停止容器： docker stop <container-id/name>
- 重启容器： docker restart <container-id/name>
- 杀死容器： docker kill <container-id/name>
- 销毁容器：docker rm <container-id/name>

#### **问题：什么是CNM？**

**答：** CNM 或容器网络模型是一种规范，它正式定义了为容器提供网络所需的步骤，同时保持用于支持多个网络驱动程序的抽象。CNM 建立在三个组件之上，即沙箱、端点和网络。

#### **问题：Docker 中有哪些不同类型的挂载类型？**

**答：**三种类型是：

- 绑定挂载：这些可以存储在主机系统的任何地方
- 卷挂载：它们由 Docker 管理并存储在主机文件系统的一部分中。
- tmpfs mount：它们存储在主机系统的内存中。这些挂载永远不能写入主机的文件系统。

#### **问题：解释Docker Trusted Registry？**

**答：**它是一个镜像存储解决方案，用于安全地存储和管理 Docker 镜像。Docker Trusted Registry 可在本地或私有云中使用。DTR 可在 CI/CD 过程中用于构建、交付和运行应用程序。DTR 具有高可用性、高效性并且具有内置的访问控制。

#### **问题：Docker_Host 的目的是什么？**

**答：** Docker_host 指定用于连接到 Docker API 的 URL 或 Unix 套接字路径。默认值为：UNIX://var/run/docker.sock

要连接到远程主机，请提供 TCP 连接字符串作为 TCP://192.0.1.20:3230

#### **问题：是否可以在同一主机上运行 Compose 文件的多个副本？如何？**

**Docker面试题解析：**这是通过使用 docker-compose 完成的。使用 Docker Compose，我们可以使用 YAML 文件来配置应用程序的服务。在此之后，只需一个命令，就可以创建和启动所有服务。要使用 Compose，请按照以下步骤操作：

- 在 Dockerfile 中定义应用环境，以便它可以在任何地方复制
- 在 docker-compose.yml 文件中定义应用程序的所有服务。
- 运行 docker-compose up 以创建并启动整个应用程序。

#### **问题：解释 Docker 对象标签。**

**答：** Docker 对象标签是一个键值对，以字符串形式存储。我们可以使用标签应用元数据。标签可以应用于 Docker 对象，如镜像、容器、卷、网络、本地守护进程、swarm 节点和服务。每个对象的键值对应该是唯一的。标签在对象的整个生命周期内都是静态的。

## Docker常见的面试题和答案合集**概括**

所以这是 Docker 面试中最热门的问题列表。你知道几个答案？在下面的评论窗口中告诉我们。此外，请查看我们的最佳 Docker 教程，由社区提交和推荐。Docker 于 2013 年发布，是用于在“容器”中打包、运送和运行应用程序的有用工具。由于谷歌、亚马逊和 VMware 等许多大公司都将 Docker 作为首选容器技术，现在正是学习该工具并以此为业的好时机。如果你想这样做，下面是你需要知道的 Docker 面试的主要问题。

## **热门的Docker常见的面试题和答案合集**

在这里，我们列出了一份 Docker 顶级面试问题的综合列表：

#### **问题：解释 Docker 容器？**

**答：**容器是保存代码及其所有依赖项的软件的基本单元，目的是使应用程序从一个计算生态系统平稳、快速、可靠地运行到另一个计算生态系统。可以使用 Docker 映像创建 Docker 容器。它是软件的可执行包，其中包含运行应用程序所需的一切，包括系统工具、库、代码、运行时和设置。

#### **问题：解释Docker架构的组成部分。**

**答：** Docker架构中的组件如下：

- **主机：**此组件包含 Docker 守护程序、镜像和容器。当 Docker 守护进程与注册表建立链接时，Docker 镜像充当 Docker 容器中保存的应用程序的元数据。
- **客户端：** Docker 客户端组件运行操作以设置与 Docker 主机的通信。
- **Registry：**这个 Docker 组件用于存储 Docker 镜像。Docker Hub 和 Docker Cloud 是公共注册表，任何人都可以使用。

#### **Docker常见的面试题有哪些：详细解释Docker Registry。**

**答：**存储所有 Docker 镜像的地方称为 Docker 注册表。Docker Hub 是一个公共注册中心，它是这些镜像的默认存储。另一个公共注册中心是 Docker Cloud。Docker Hub 是最重要的镜像容器公共仓库，由大量开发人员和许多个人贡献者持续维护。

#### **问题：简要说明 Docker Container 的生活方式。**

**答：** Docker Container 的生命周期是：

- 容器的创建
- 运行容器
- 暂停容器
- 取消暂停容器
- 启动容器
- 停止容器
- 重启容器
- 杀死容器
- 销毁容器

#### **问题：命名一些重要的 Docker 命令**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**以下是一些重要的 Docker 命令：

- build：为Docker构建一个镜像文件
- create：用于创建新容器
- kill：杀死一个容器
- dockerd：用于启动 Docker 守护进程
- commit：用于从容器更改创建新镜像

#### **问题：Docker 中的命名空间是什么。**

**答：** Docker Namespaces 是一种提供隔离工作区的技术，称为容器。一旦容器启动，就会为所述容器创建一组命名空间。这些命名空间为这些容器提供了一层隔离，因为每个容器在不同的命名空间中运行，其访问仅限于提到的命名空间。

#### **问题：什么是 Docker Swarm？**

**答：** Docker Swarm 是用于集群和调度 Docker 容器的原生工具。使用 Docker Swarm，开发人员和 IT 主管可以轻松地在 Docker 或单独的虚拟系统 (VS) 中建立和管理一堆节点。

#### **问题：如何识别Docker Container的状态？**

**答：**要识别 Docker 容器的状态，应运行以下命令

“ **docker ps-a。**”

此命令将提供所有可用 Docker 容器的列表以及主机上的相应状态。从列表中，人们可以很容易地确定预期的容器以检查其状态。

#### **问题：什么是 Docker Image 和 Docker Run 命令？**

**答：** Docker 映像是一组文件和一组参数，这些参数允许创建在不同容器中作为隔离进程运行的实例。映像基本上是使用应用程序的完整和可执行版本的指令构建的，该版本依赖于主机操作系统内核。Docker run 命令可用于创建名为容器的实例，该实例可使用 Docker 映像运行。当 Docker 用户运行一个镜像时，它成为该容器的一个或多个实例。

#### **问题：陈述 Docker 的功能和应用。**

**答：**以下是实现Docker的一些功能和应用：

- 它使配置更简单，并提供了基础设施级别的轻松配置
- 通过帮助开发人员专注于业务逻辑，它减少了开发时间并提高了生产力
- 它放大了提供有用功能的调试功能
- 它允许隔离应用程序
- 它以容器化的形式减少了多台服务器的使用
- 它有利于在操作系统级别的快速部署

#### **问题：什么是 Docker 对象？**

**答：** Docker 镜像、服务和容器被称为 Docker 对象。

- **镜像**：包含创建 Docker 容器说明的只读模板
- **Containers** : 一个可运行的镜像实例
- **服务**：它允许在各种 Docker 守护进程之间扩展容器，这些守护进程都作为一个群一起工作。

其他 Docker 对象包括网络和卷。

#### **问题：Docker Container、Stateless 和 Stateful 应用哪个更适合？**

**答：**无状态应用程序应该优先于 Docker 容器的有状态应用程序。我们可以从我们的应用程序中创建一个容器并取出应用程序的可配置状态参数。一旦它是一个，我们就可以运行具有不同生产参数和其他环境的同一个容器。通过无状态应用程序，我们可以在不同的场景中重用相同的镜像。当涉及到 Docker 容器时，扩展无状态应用程序也比有状态应用程序更容易。

#### **问题：解释Dockerfile的使用。**

**答：** Dockerfile 包含了很多在 Docker 上传递的指令，使镜像的构建过程成为可能，可以自动读取这些指令。它也可以称为包含用户可以在命令行上调用以创建镜像的所有可能命令的文本文档。

#### **问题：Docker 中默认哪些网络可用？**

**答：** Docker 中可用的默认网络是：

- **bridge** : 如果网络未另行指定，则容器连接到的默认网络
- **none**：连接到缺少网络接口的特定于容器的网络堆栈
- **host**：连接到主机的网络堆栈

#### **Docker常见的面试题有哪些：列出存储在 Git 存储库中的 Dockerized 应用程序的部署过程中的步骤。**

**答：**虽然部署过程会随着你的生产环境而变化，但基本的部署过程将具有以下内容：

- 通过位于代码目录中的 Docker Build 构建应用程序
- 执行镜像测试
- 将新镜像推送到注册表 docker
- 通知远程应用服务器从注册表中获取镜像并运行它
- HTTP 代理中的端口交换
- 停止旧容器

#### **问题：解释 Docker 与其他容器技术的不同之处。**

**答：** Docker 是最新的容器技术之一，并且已经成为最受欢迎的技术之一。内置于云时代，Docker 带来了许多旧容器技术所缺少的新功能。Docker 最好的特性之一是它可以在任何基础设施上运行，无论是你的家用机器还是云。

通过 Docker，现在可以在旧服务器上运行更多应用程序，并且还允许进程打包和发送程序。Docker 还有一个 Container Hub 充当容器的存储库，易于下载和使用。此外，这些容器也可以由你的应用程序共享。它也有很好的文档记录，这使得它比其他容器技术更好。

#### **Docker常见的面试题和答案合集：如果退出 Docker 容器，数据会丢失吗？**

**答：** Docker Container 退出时，不会发生数据丢失，因为应用程序将所有数据写入磁盘，仅用于保存。这个过程一直重复，直到并且除非容器被明确删除。此外，Docker 容器的文件系统即使在 Docker 容器停止后仍然存在。

#### **问题：Docker 在生产中是如何监控的？**

**答：** ;要在生产中监控 Docker，可以使用 Docker stats 和 Docker events 等工具。通过这些工具，人们可以获得有关重要统计数据的报告。一旦使用容器 ID 调用 Docker 统计信息，它就会返回容器的 CPU 和内存使用情况。它类似于Linux 中的top 命令。另一方面，Docker 事件是用于查看 Docker 守护进程中正在进行的活动列表的命令。其中一些事件被附加、提交、重命名、销毁、死亡等等。还可以选择过滤他们感兴趣的事件。

#### **问题：阐明 Docker 使用的工作流程。**

**答：**下面简单介绍一下Docker使用的工作流程：

- 由于Dockerfile是镜像的源代码，一切从它开始
- 创建后，Dockerfile 将用于构建容器的映像。这个镜像只是Dockerfile的编译版本
- 然后使用注册表重新分发此映像，注册表就像一个映像存储库。
- 此外，该映像可用于运行容器。容器在运行时与没有管理程序的 VM 非常相似。

#### **问题：解释“Docker run”和“Docker created”命令之间的差异。**

**回答：;** Docker run 和 Docker create 之间的主要区别在于，如果你使用后者，则创建的容器处于“停止”状态。此外，Docker 创建可用于存储和输出容器 ID 以备后用。最好的方法是将“docker run”与 —cidfile FILE_NAME 一起使用，因为再次运行它不允许覆盖文件。

#### **问题：什么是虚拟化？**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**在早期，虚拟化被称为一种逻辑划分大型机以允许多个应用程序同时运行的方法。但是随着时间的推移，行业能够允许在一个基于 x86 的系统上同时运行多个操作系统，虚拟化的含义发生了很大的变化。

净结果？虚拟化允许用户在同一硬件上运行两个不同的操作系统。虽然主要操作系统是管理员，但每个客户操作系统都会经历诸如引导、加载内核等过程。它也非常适合安全性，因为可能不允许每个来宾操作系统完全访问主机操作系统，从而导致数据泄露。

主要有三种类型的虚拟化：

- 半虚拟化
- 仿真
- 基于容器的虚拟化

#### **问题：注册中心和存储库有什么区别？**

**答：** Docker Registry 是用于托管和分发映像的服务，而 Docker Hub 是默认注册表。另一方面，Docker Repository 是相关 Docker 镜像的集合。也就是说，它们具有相同的名称但具有不同的标签。

#### **问题：Docker 中的 compose 文件可以使用 JSON 代替 YAML 吗？如果是，如何？**

**答：** 是的，Docker 撰写文件可以使用 JSON 代替 YAML。要使用 JSON 文件进行组合，文件名应指定如下：

“docker-compose -f docker-compose.json up。”

#### **问题：解释Dockerfile中的CMD和ENTRYPOINT？**

**答：** 在 Dockerfile 中，CMD 和 ENTRYPOINT 指令都定义了运行容器时将执行的命令。对于他们的合作，有一些规则，比如：

- Dockerfile 应至少指定一个来自 CMD 或 ENTRYPOINT 的命令
- 将容器用作可执行文件时，需要定义 ENTRYPOINT
- 当使用替代参数运行容器时，CMD 将被覆盖

#### **问题：解释使用 Docker 在 Linux 容器内运行应用程序的过程**

**答：** 以下是如何使用 Docker 在 Linux 容器内运行应用程序的步骤

- 安装并运行 Docker
- 从 Docker 中心获取 Fedora 21（基于 Linux 的操作系统）基础镜像
- 在 Docker 基础映像中加载你的应用程序
- 以交互模式使用新镜像运行容器
- 检查系统中的容器
- 启动或停止 Docker 容器
- 进入 Docker 容器
- 删除容器或镜像

#### **问题：什么是管理程序？**

**答：**虚拟机监视器，称为 Hypervisor，是用于创建和运行虚拟机的软件。它允许一台主机支持多个来宾 VM。这是通过共享内存、处理等资源来完成的，从而减少内存、空间和维护需求。有两种类型的管理程序：

- Type I：就像是运行在主机硬件上的轻量级操作系统。
- 类型 II：像操作系统上的软件程序一样运行。

#### **问题：解释容器化？**

**答：** Docker 容器包含不同的软件包，例如代码、系统工具、库、运行时和运行应用程序所需的设置。应用程序驻留在 Docker 引擎层之上。这称为容器化。无论环境如何，它都有助于应用程序顺利运行。

#### **问题：解释容器化和虚拟化之间的主要区别。**

**答：**通过虚拟化，你可以在单个物理服务器上运行多个操作系统。容器化发生在同一操作系统上，其中应用程序被打包为容器并在单个服务器或 VM 下运行。

![50个Docker常见的面试题和答案合集介绍](https://hackr.io/blog/media/containerization-vs-virtualization.png)

#### **问题：解释 Docker 镜像、Docker Hub、Docker 文件？**

**答：** Docker 镜像：这些是包含多个层的文件，用于在 Docker 容器内执行代码。镜像是根据应用程序可执行版本的指令构建的。镜像通过允许缓存每个步骤来加速 docker 构建。

Docker hub：它是一种在团队内查找和共享容器镜像的服务。你可以推送和拉取镜像，访问容器镜像的私有存储库，从 Github（或 Bitbucket）自动构建容器镜像，并将它们推送到 DockerHub。Docker 本身提供服务。[阅读更多](https://www.lsbin.com/wp-content/themes/begin%20lts/inc/go.php?url=https://docs.docker.com/docker-hub/)。

Docker 文件：用于构建镜像的文本文档。它包含构建映像的说明和命令。Docker 读取命令并自动组装镜像。

#### **Docker常见的面试题和答案合集：如何检查Docker Client和Docker Server版本？**

**答：**我们可以使用命令docker version [options]来查看docker版本。如果我们不提供任何选项，则 Docker 会提供有关客户端和服务器的所有版本相关信息。例如，要仅获取服务器版本，请使用：

```
$ docker version --format '{{.Server.Version}}'
```

#### **问题： 解释一下 Docker Repository 的登录过程？**

**答：**要登录到 Docker 存储库，请使用以下命令：

```
docker login [OPTIONS] [SERVER]
```

例如，要登录自托管（本地）注册中心，你可以添加服务器名称：

```
$ docker login localhost:8080
```

#### **Docker常见的面试题有哪些：解释各种 Docker 基本命令？**

答：一些 Docker 命令是：

- docker push：将存储库或镜像推送到注册表
- docker run：在新容器中运行命令
- docker pull：从注册表中拉取存储库或镜像
- docker start：启动一个或多个容器
- docker stop：停止运行容器
- docker search：在 docker hub 中搜索镜像
- docker commit：提交新镜像

#### **问题：解释一下 Docker Container 与其他容器化方法的区别？**

**答：** Docker 容器可以轻松部署到任何云平台。此外，开发人员可以更快地创建可立即运行的容器化应用程序，并轻松管理和部署应用程序。容器也可以与应用程序共享。这些功能在其他容器化方法中不存在。

#### **问题：列出运行Docker的平台。**

**答：**它可以在 Windows (x86-64) 和 Linux（在 x86-64、ARM 和其他 CPU 架构上）、s390x、ppc64le 上运行。

#### **问题：容器是否可以自行重启？**

**回答：**是的，这是可能的。Docker 定义了某些策略来重新启动容器。这些是关闭的：如果容器停止或失败，则不会重新启动，

- On-failure：容器仅在非用户原因发生的故障时重新启动，
- 除非停止：容器仅在用户执行停止它的命令时重新启动，
- 始终：无论出现错误或其他问题，始终重新启动容器。

命令是：

```
$ docker run -dit — restart [unless-stopped|off|on-failure|always] [CONTAINER]
```

#### **问：云有没有可能超越容器化的使用？**

**答：**在这类问题中，你可以发表你的个人意见。例如，根据我的理解，虽然云是一个很好的竞争对手，但它不能取代容器化。大多数公司正在同时使用云和容器化，以充分利用这两种技术。

#### **问题：Docker Container 有哪些可能的状态？**

**Docker面试题解析：** Docker容器的不同状态是：

- 已创建 - 已创建但未处于活动状态的容器。
- 正在重新启动 - 正在重新启动的容器。
- 运行 - 运行容器。
- 暂停 - 其进程已暂停的容器。
- 退出 - 运行并完成的容器。
- Dead - 守护进程尝试停止但未能停止的容器。

#### **问题：解释容器编排以及我们为什么需要使用它？**

**答：**容器编排有助于管理在动态和大型环境中运行的容器。容器编排可以控制和自动化以下任务：

- 容器的供应和部署，
- 负载均衡，
- 容器之间的资源分配，
- 监控容器和主机的健康状况，
- 容器的缩放，
- 当主机不可用或缺乏资源时，将容器从一台主机切换到另一台主机。

#### **问题：解释内存交换标志？**

内存交换标志是一个修饰符标志，允许容器在使用完所有可用 RAM 后将多余的内存需求写入磁盘。仅当设置了 --memory 标志时才设置它。例如，如果 memory = "400m" 并且 memory-swap = "1g"，那么容器可以使用 400m 的内存和 600m (1g-400m) 的交换。

#### **Docker常见的面试题和答案合集：docker 卷存储在哪里？**

**答：**卷由 Docker 创建和管理（不能被非 Docker 进程访问）并存储在 Docker 主机文件系统的一部分中：/var/lib/docker/volumes/。卷是在 Docker 中持久化数据的最有效方式。

#### **问题：解释各种 Docker 高级命令？**

**答：**一些重要的 Docker 命令是：

- docker -version：了解安装的docker版本。语法，Docker --version
- docker ps：列出所有正在运行的 docker 容器以及容器详细信息。语法：docker ps
- docker ps -a：列出所有容器，包括那些正在运行、停止、退出的容器以及详细信息。语法：docker ps -a
- docker exec：访问容器并在该容器内运行命令。语法：docker exec [选项]
- docker build：从 Dockerfile 构建镜像。语法：docker build [options] path|URL
- docker rm：删除具有上述容器 ID 的容器。语法：docker rm <container_id>
- docker rmi：删除带有提到的镜像 ID 的 docker 镜像。语法：docker rmi <image_id>
- docker info：获取系统上安装的 Docker 的详细信息，如容器数量、镜像、运行、暂停、停止、服务器版本、容量、运行时间、内核版本、总内存等。 语法：docker info;
- docker cp：将文件从 docker 容器复制到本地系统。语法：docker cp <source_path> <dest_path>
- docker history：显示带有提到的镜像名称的 docker 镜像的历史记录。语法：docker history <img_name>

#### **问题：使用 Systemd 控制 Docker 的命令是什么？**

**答：**要启动 Docker 守护进程，许多 Linux 发行版都使用该系统。要启动服务，请使用命令 systemct1。如果 systemct1 不可用，则使用 service 命令。

```
$ sudo systemctl start docker 
$ sudo service docker start
```

要在引导期间启用和禁用守护程序，请使用：

```
$ sudo systemctl enable docker 
$ sudo systemctl disable docker
```

要修改守护程序选项，请使用：;

```
$ sudo systemctl edit docker
```

查看与 Docker 服务相关的日志：

```
$ journalctl -u docker;
```

#### **问题：扩展 Docker 容器的过程是什么**

答：Docker 容器可以使用 Docker-decompose 的 scale 命令进行缩放。过程如下：

- 使用以下方法扩展服务器容器并启动服务器的“n”个实例：

```
$] docker-compose --file docker-compose-run-srvr.yml scale < service_name > = < n >
```

在上面的命令中，服务名称在 docker-compose-run-srvr.yml 中定义，并将其缩放为“n”倍，其中 n 可以是任何整数值。

- Docker 容器扩容后，要查看容器详细信息，请执行以下命令：

```
$] docker ps -a
```

#### **Docker常见的面试题有哪些：介绍一下Docker容器生命周期的步骤。**

**答：**步骤如下：

- 创建容器： docker create --name <container-name> <image-name>
- 运行 docker 容器： docker run -it -d --name <container-name> <image-name> bash
- 暂停容器： docker pause <container-id/name>
- 取消暂停容器： docker unpause <container-id/name>
- 启动容器：docker start <container-id/name>
- 停止容器： docker stop <container-id/name>
- 重启容器： docker restart <container-id/name>
- 杀死容器： docker kill <container-id/name>
- 销毁容器：docker rm <container-id/name>

#### **问题：什么是CNM？**

**答：** CNM 或容器网络模型是一种规范，它正式定义了为容器提供网络所需的步骤，同时保持用于支持多个网络驱动程序的抽象。CNM 建立在三个组件之上，即沙箱、端点和网络。

#### **问题：Docker 中有哪些不同类型的挂载类型？**

**答：**三种类型是：

- 绑定挂载：这些可以存储在主机系统的任何地方
- 卷挂载：它们由 Docker 管理并存储在主机文件系统的一部分中。
- tmpfs mount：它们存储在主机系统的内存中。这些挂载永远不能写入主机的文件系统。

#### **问题：解释Docker Trusted Registry？**

**答：**它是一个镜像存储解决方案，用于安全地存储和管理 Docker 镜像。Docker Trusted Registry 可在本地或私有云中使用。DTR 可在 CI/CD 过程中用于构建、交付和运行应用程序。DTR 具有高可用性、高效性并且具有内置的访问控制。

#### **问题：Docker_Host 的目的是什么？**

**答：** Docker_host 指定用于连接到 Docker API 的 URL 或 Unix 套接字路径。默认值为：UNIX://var/run/docker.sock

要连接到远程主机，请提供 TCP 连接字符串作为 TCP://192.0.1.20:3230

#### **问题：是否可以在同一主机上运行 Compose 文件的多个副本？如何？**

**Docker面试题解析：**这是通过使用 docker-compose 完成的。使用 Docker Compose，我们可以使用 YAML 文件来配置应用程序的服务。在此之后，只需一个命令，就可以创建和启动所有服务。要使用 Compose，请按照以下步骤操作：

- 在 Dockerfile 中定义应用环境，以便它可以在任何地方复制
- 在 docker-compose.yml 文件中定义应用程序的所有服务。
- 运行 docker-compose up 以创建并启动整个应用程序。

#### **问题：解释 Docker 对象标签。**

**答：** Docker 对象标签是一个键值对，以字符串形式存储。我们可以使用标签应用元数据。标签可以应用于 Docker 对象，如镜像、容器、卷、网络、本地守护进程、swarm 节点和服务。每个对象的键值对应该是唯一的。标签在对象的整个生命周期内都是静态的。

## Docker常见的面试题和答案合集**概括**

所以这是 Docker 面试中最热门的问题列表。你知道几个答案？在下面的评论窗口中告诉我们。此外，请查看我们的最佳 Docker 教程，由社区提交和推荐。Docker 于 2013 年发布，是用于在“容器”中打包、运送和运行应用程序的有用工具。由于谷歌、亚马逊和 VMware 等许多大公司都将 Docker 作为首选容器技术，现在正是学习该工具并以此为业的好时机。如果你想这样做，下面是你需要知道的 Docker 面试的主要问题。

## **热门的Docker常见的面试题和答案合集**

在这里，我们列出了一份 Docker 顶级面试问题的综合列表：

#### **问题：解释 Docker 容器？**

**答：**容器是保存代码及其所有依赖项的软件的基本单元，目的是使应用程序从一个计算生态系统平稳、快速、可靠地运行到另一个计算生态系统。可以使用 Docker 映像创建 Docker 容器。它是软件的可执行包，其中包含运行应用程序所需的一切，包括系统工具、库、代码、运行时和设置。

#### **问题：解释Docker架构的组成部分。**

**答：** Docker架构中的组件如下：

- **主机：**此组件包含 Docker 守护程序、镜像和容器。当 Docker 守护进程与注册表建立链接时，Docker 镜像充当 Docker 容器中保存的应用程序的元数据。
- **客户端：** Docker 客户端组件运行操作以设置与 Docker 主机的通信。
- **Registry：**这个 Docker 组件用于存储 Docker 镜像。Docker Hub 和 Docker Cloud 是公共注册表，任何人都可以使用。

#### **Docker常见的面试题有哪些：详细解释Docker Registry。**

**答：**存储所有 Docker 镜像的地方称为 Docker 注册表。Docker Hub 是一个公共注册中心，它是这些镜像的默认存储。另一个公共注册中心是 Docker Cloud。Docker Hub 是最重要的镜像容器公共仓库，由大量开发人员和许多个人贡献者持续维护。

#### **问题：简要说明 Docker Container 的生活方式。**

**答：** Docker Container 的生命周期是：

- 容器的创建
- 运行容器
- 暂停容器
- 取消暂停容器
- 启动容器
- 停止容器
- 重启容器
- 杀死容器
- 销毁容器

#### **问题：命名一些重要的 Docker 命令**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**以下是一些重要的 Docker 命令：

- build：为Docker构建一个镜像文件
- create：用于创建新容器
- kill：杀死一个容器
- dockerd：用于启动 Docker 守护进程
- commit：用于从容器更改创建新镜像

#### **问题：Docker 中的命名空间是什么。**

**答：** Docker Namespaces 是一种提供隔离工作区的技术，称为容器。一旦容器启动，就会为所述容器创建一组命名空间。这些命名空间为这些容器提供了一层隔离，因为每个容器在不同的命名空间中运行，其访问仅限于提到的命名空间。

#### **问题：什么是 Docker Swarm？**

**答：** Docker Swarm 是用于集群和调度 Docker 容器的原生工具。使用 Docker Swarm，开发人员和 IT 主管可以轻松地在 Docker 或单独的虚拟系统 (VS) 中建立和管理一堆节点。

#### **问题：如何识别Docker Container的状态？**

**答：**要识别 Docker 容器的状态，应运行以下命令

“ **docker ps-a。**”

此命令将提供所有可用 Docker 容器的列表以及主机上的相应状态。从列表中，人们可以很容易地确定预期的容器以检查其状态。

#### **问题：什么是 Docker Image 和 Docker Run 命令？**

**答：** Docker 映像是一组文件和一组参数，这些参数允许创建在不同容器中作为隔离进程运行的实例。映像基本上是使用应用程序的完整和可执行版本的指令构建的，该版本依赖于主机操作系统内核。Docker run 命令可用于创建名为容器的实例，该实例可使用 Docker 映像运行。当 Docker 用户运行一个镜像时，它成为该容器的一个或多个实例。

#### **问题：陈述 Docker 的功能和应用。**

**答：**以下是实现Docker的一些功能和应用：

- 它使配置更简单，并提供了基础设施级别的轻松配置
- 通过帮助开发人员专注于业务逻辑，它减少了开发时间并提高了生产力
- 它放大了提供有用功能的调试功能
- 它允许隔离应用程序
- 它以容器化的形式减少了多台服务器的使用
- 它有利于在操作系统级别的快速部署

#### **问题：什么是 Docker 对象？**

**答：** Docker 镜像、服务和容器被称为 Docker 对象。

- **镜像**：包含创建 Docker 容器说明的只读模板
- **Containers** : 一个可运行的镜像实例
- **服务**：它允许在各种 Docker 守护进程之间扩展容器，这些守护进程都作为一个群一起工作。

其他 Docker 对象包括网络和卷。

#### **问题：Docker Container、Stateless 和 Stateful 应用哪个更适合？**

**答：**无状态应用程序应该优先于 Docker 容器的有状态应用程序。我们可以从我们的应用程序中创建一个容器并取出应用程序的可配置状态参数。一旦它是一个，我们就可以运行具有不同生产参数和其他环境的同一个容器。通过无状态应用程序，我们可以在不同的场景中重用相同的镜像。当涉及到 Docker 容器时，扩展无状态应用程序也比有状态应用程序更容易。

#### **问题：解释Dockerfile的使用。**

**答：** Dockerfile 包含了很多在 Docker 上传递的指令，使镜像的构建过程成为可能，可以自动读取这些指令。它也可以称为包含用户可以在命令行上调用以创建镜像的所有可能命令的文本文档。

#### **问题：Docker 中默认哪些网络可用？**

**答：** Docker 中可用的默认网络是：

- **bridge** : 如果网络未另行指定，则容器连接到的默认网络
- **none**：连接到缺少网络接口的特定于容器的网络堆栈
- **host**：连接到主机的网络堆栈

#### **Docker常见的面试题有哪些：列出存储在 Git 存储库中的 Dockerized 应用程序的部署过程中的步骤。**

**答：**虽然部署过程会随着你的生产环境而变化，但基本的部署过程将具有以下内容：

- 通过位于代码目录中的 Docker Build 构建应用程序
- 执行镜像测试
- 将新镜像推送到注册表 docker
- 通知远程应用服务器从注册表中获取镜像并运行它
- HTTP 代理中的端口交换
- 停止旧容器

#### **问题：解释 Docker 与其他容器技术的不同之处。**

**答：** Docker 是最新的容器技术之一，并且已经成为最受欢迎的技术之一。内置于云时代，Docker 带来了许多旧容器技术所缺少的新功能。Docker 最好的特性之一是它可以在任何基础设施上运行，无论是你的家用机器还是云。

通过 Docker，现在可以在旧服务器上运行更多应用程序，并且还允许进程打包和发送程序。Docker 还有一个 Container Hub 充当容器的存储库，易于下载和使用。此外，这些容器也可以由你的应用程序共享。它也有很好的文档记录，这使得它比其他容器技术更好。

#### **Docker常见的面试题和答案合集：如果退出 Docker 容器，数据会丢失吗？**

**答：** Docker Container 退出时，不会发生数据丢失，因为应用程序将所有数据写入磁盘，仅用于保存。这个过程一直重复，直到并且除非容器被明确删除。此外，Docker 容器的文件系统即使在 Docker 容器停止后仍然存在。

#### **问题：Docker 在生产中是如何监控的？**

**答：** ;要在生产中监控 Docker，可以使用 Docker stats 和 Docker events 等工具。通过这些工具，人们可以获得有关重要统计数据的报告。一旦使用容器 ID 调用 Docker 统计信息，它就会返回容器的 CPU 和内存使用情况。它类似于Linux 中的top 命令。另一方面，Docker 事件是用于查看 Docker 守护进程中正在进行的活动列表的命令。其中一些事件被附加、提交、重命名、销毁、死亡等等。还可以选择过滤他们感兴趣的事件。

#### **问题：阐明 Docker 使用的工作流程。**

**答：**下面简单介绍一下Docker使用的工作流程：

- 由于Dockerfile是镜像的源代码，一切从它开始
- 创建后，Dockerfile 将用于构建容器的映像。这个镜像只是Dockerfile的编译版本
- 然后使用注册表重新分发此映像，注册表就像一个映像存储库。
- 此外，该映像可用于运行容器。容器在运行时与没有管理程序的 VM 非常相似。

#### **问题：解释“Docker run”和“Docker created”命令之间的差异。**

**回答：;** Docker run 和 Docker create 之间的主要区别在于，如果你使用后者，则创建的容器处于“停止”状态。此外，Docker 创建可用于存储和输出容器 ID 以备后用。最好的方法是将“docker run”与 —cidfile FILE_NAME 一起使用，因为再次运行它不允许覆盖文件。

#### **问题：什么是虚拟化？**

**[Docker面试题解析](https://www.lsbin.com/tag/docker%e9%9d%a2%e8%af%95%e9%a2%98%e8%a7%a3%e6%9e%90/ "查看与 Docker面试题解析 相关的文章")：**在早期，虚拟化被称为一种逻辑划分大型机以允许多个应用程序同时运行的方法。但是随着时间的推移，行业能够允许在一个基于 x86 的系统上同时运行多个操作系统，虚拟化的含义发生了很大的变化。

净结果？虚拟化允许用户在同一硬件上运行两个不同的操作系统。虽然主要操作系统是管理员，但每个客户操作系统都会经历诸如引导、加载内核等过程。它也非常适合安全性，因为可能不允许每个来宾操作系统完全访问主机操作系统，从而导致数据泄露。

主要有三种类型的虚拟化：

- 半虚拟化
- 仿真
- 基于容器的虚拟化

#### **问题：注册中心和存储库有什么区别？**

**答：** Docker Registry 是用于托管和分发映像的服务，而 Docker Hub 是默认注册表。另一方面，Docker Repository 是相关 Docker 镜像的集合。也就是说，它们具有相同的名称但具有不同的标签。

#### **问题：Docker 中的 compose 文件可以使用 JSON 代替 YAML 吗？如果是，如何？**

**答：** 是的，Docker 撰写文件可以使用 JSON 代替 YAML。要使用 JSON 文件进行组合，文件名应指定如下：

“docker-compose -f docker-compose.json up。”

#### **问题：解释Dockerfile中的CMD和ENTRYPOINT？**

**答：** 在 Dockerfile 中，CMD 和 ENTRYPOINT 指令都定义了运行容器时将执行的命令。对于他们的合作，有一些规则，比如：

- Dockerfile 应至少指定一个来自 CMD 或 ENTRYPOINT 的命令
- 将容器用作可执行文件时，需要定义 ENTRYPOINT
- 当使用替代参数运行容器时，CMD 将被覆盖

#### **问题：解释使用 Docker 在 Linux 容器内运行应用程序的过程**

**答：** 以下是如何使用 Docker 在 Linux 容器内运行应用程序的步骤

- 安装并运行 Docker
- 从 Docker 中心获取 Fedora 21（基于 Linux 的操作系统）基础镜像
- 在 Docker 基础映像中加载你的应用程序
- 以交互模式使用新镜像运行容器
- 检查系统中的容器
- 启动或停止 Docker 容器
- 进入 Docker 容器
- 删除容器或镜像

#### **问题：什么是管理程序？**

**答：**虚拟机监视器，称为 Hypervisor，是用于创建和运行虚拟机的软件。它允许一台主机支持多个来宾 VM。这是通过共享内存、处理等资源来完成的，从而减少内存、空间和维护需求。有两种类型的管理程序：

- Type I：就像是运行在主机硬件上的轻量级操作系统。
- 类型 II：像操作系统上的软件程序一样运行。

#### **问题：解释容器化？**

**答：** Docker 容器包含不同的软件包，例如代码、系统工具、库、运行时和运行应用程序所需的设置。应用程序驻留在 Docker 引擎层之上。这称为容器化。无论环境如何，它都有助于应用程序顺利运行。

#### **问题：解释容器化和虚拟化之间的主要区别。**

**答：**通过虚拟化，你可以在单个物理服务器上运行多个操作系统。容器化发生在同一操作系统上，其中应用程序被打包为容器并在单个服务器或 VM 下运行。

![50个Docker常见的面试题和答案合集介绍](https://hackr.io/blog/media/containerization-vs-virtualization.png)

#### **问题：解释 Docker 镜像、Docker Hub、Docker 文件？**

**答：** Docker 镜像：这些是包含多个层的文件，用于在 Docker 容器内执行代码。镜像是根据应用程序可执行版本的指令构建的。镜像通过允许缓存每个步骤来加速 docker 构建。

Docker hub：它是一种在团队内查找和共享容器镜像的服务。你可以推送和拉取镜像，访问容器镜像的私有存储库，从 Github（或 Bitbucket）自动构建容器镜像，并将它们推送到 DockerHub。Docker 本身提供服务。[阅读更多](https://www.lsbin.com/wp-content/themes/begin%20lts/inc/go.php?url=https://docs.docker.com/docker-hub/)。

Docker 文件：用于构建镜像的文本文档。它包含构建映像的说明和命令。Docker 读取命令并自动组装镜像。

#### **Docker常见的面试题和答案合集：如何检查Docker Client和Docker Server版本？**

**答：**我们可以使用命令docker version [options]来查看docker版本。如果我们不提供任何选项，则 Docker 会提供有关客户端和服务器的所有版本相关信息。例如，要仅获取服务器版本，请使用：

```
$ docker version --format '{{.Server.Version}}'
```

#### **问题： 解释一下 Docker Repository 的登录过程？**

**答：**要登录到 Docker 存储库，请使用以下命令：

```
docker login [OPTIONS] [SERVER]
```

例如，要登录自托管（本地）注册中心，你可以添加服务器名称：

```
$ docker login localhost:8080
```

#### **Docker常见的面试题有哪些：解释各种 Docker 基本命令？**

答：一些 Docker 命令是：

- docker push：将存储库或镜像推送到注册表
- docker run：在新容器中运行命令
- docker pull：从注册表中拉取存储库或镜像
- docker start：启动一个或多个容器
- docker stop：停止运行容器
- docker search：在 docker hub 中搜索镜像
- docker commit：提交新镜像

#### **问题：解释一下 Docker Container 与其他容器化方法的区别？**

**答：** Docker 容器可以轻松部署到任何云平台。此外，开发人员可以更快地创建可立即运行的容器化应用程序，并轻松管理和部署应用程序。容器也可以与应用程序共享。这些功能在其他容器化方法中不存在。

#### **问题：列出运行Docker的平台。**

**答：**它可以在 Windows (x86-64) 和 Linux（在 x86-64、ARM 和其他 CPU 架构上）、s390x、ppc64le 上运行。

#### **问题：容器是否可以自行重启？**

**回答：**是的，这是可能的。Docker 定义了某些策略来重新启动容器。这些是关闭的：如果容器停止或失败，则不会重新启动，

- On-failure：容器仅在非用户原因发生的故障时重新启动，
- 除非停止：容器仅在用户执行停止它的命令时重新启动，
- 始终：无论出现错误或其他问题，始终重新启动容器。

命令是：

```
$ docker run -dit — restart [unless-stopped|off|on-failure|always] [CONTAINER]
```

#### **问：云有没有可能超越容器化的使用？**

**答：**在这类问题中，你可以发表你的个人意见。例如，根据我的理解，虽然云是一个很好的竞争对手，但它不能取代容器化。大多数公司正在同时使用云和容器化，以充分利用这两种技术。

#### **问题：Docker Container 有哪些可能的状态？**

**Docker面试题解析：** Docker容器的不同状态是：

- 已创建 - 已创建但未处于活动状态的容器。
- 正在重新启动 - 正在重新启动的容器。
- 运行 - 运行容器。
- 暂停 - 其进程已暂停的容器。
- 退出 - 运行并完成的容器。
- Dead - 守护进程尝试停止但未能停止的容器。

#### **问题：解释容器编排以及我们为什么需要使用它？**

**答：**容器编排有助于管理在动态和大型环境中运行的容器。容器编排可以控制和自动化以下任务：

- 容器的供应和部署，
- 负载均衡，
- 容器之间的资源分配，
- 监控容器和主机的健康状况，
- 容器的缩放，
- 当主机不可用或缺乏资源时，将容器从一台主机切换到另一台主机。

#### **问题：解释内存交换标志？**

内存交换标志是一个修饰符标志，允许容器在使用完所有可用 RAM 后将多余的内存需求写入磁盘。仅当设置了 --memory 标志时才设置它。例如，如果 memory = "400m" 并且 memory-swap = "1g"，那么容器可以使用 400m 的内存和 600m (1g-400m) 的交换。

#### **Docker常见的面试题和答案合集：docker 卷存储在哪里？**

**答：**卷由 Docker 创建和管理（不能被非 Docker 进程访问）并存储在 Docker 主机文件系统的一部分中：/var/lib/docker/volumes/。卷是在 Docker 中持久化数据的最有效方式。

#### **问题：解释各种 Docker 高级命令？**

**答：**一些重要的 Docker 命令是：

- docker -version：了解安装的docker版本。语法，Docker --version
- docker ps：列出所有正在运行的 docker 容器以及容器详细信息。语法：docker ps
- docker ps -a：列出所有容器，包括那些正在运行、停止、退出的容器以及详细信息。语法：docker ps -a
- docker exec：访问容器并在该容器内运行命令。语法：docker exec [选项]
- docker build：从 Dockerfile 构建镜像。语法：docker build [options] path|URL
- docker rm：删除具有上述容器 ID 的容器。语法：docker rm <container_id>
- docker rmi：删除带有提到的镜像 ID 的 docker 镜像。语法：docker rmi <image_id>
- docker info：获取系统上安装的 Docker 的详细信息，如容器数量、镜像、运行、暂停、停止、服务器版本、容量、运行时间、内核版本、总内存等。 语法：docker info;
- docker cp：将文件从 docker 容器复制到本地系统。语法：docker cp <source_path> <dest_path>
- docker history：显示带有提到的镜像名称的 docker 镜像的历史记录。语法：docker history <img_name>

#### **问题：使用 Systemd 控制 Docker 的命令是什么？**

**答：**要启动 Docker 守护进程，许多 Linux 发行版都使用该系统。要启动服务，请使用命令 systemct1。如果 systemct1 不可用，则使用 service 命令。

```
$ sudo systemctl start docker 
$ sudo service docker start
```

要在引导期间启用和禁用守护程序，请使用：

```
$ sudo systemctl enable docker 
$ sudo systemctl disable docker
```

要修改守护程序选项，请使用：;

```
$ sudo systemctl edit docker
```

查看与 Docker 服务相关的日志：

```
$ journalctl -u docker;
```

#### **问题：扩展 Docker 容器的过程是什么**

答：Docker 容器可以使用 Docker-decompose 的 scale 命令进行缩放。过程如下：

- 使用以下方法扩展服务器容器并启动服务器的“n”个实例：

```
$] docker-compose --file docker-compose-run-srvr.yml scale < service_name > = < n >
```

在上面的命令中，服务名称在 docker-compose-run-srvr.yml 中定义，并将其缩放为“n”倍，其中 n 可以是任何整数值。

- Docker 容器扩容后，要查看容器详细信息，请执行以下命令：

```
$] docker ps -a
```

#### **Docker常见的面试题有哪些：介绍一下Docker容器生命周期的步骤。**

**答：**步骤如下：

- 创建容器： docker create --name <container-name> <image-name>
- 运行 docker 容器： docker run -it -d --name <container-name> <image-name> bash
- 暂停容器： docker pause <container-id/name>
- 取消暂停容器： docker unpause <container-id/name>
- 启动容器：docker start <container-id/name>
- 停止容器： docker stop <container-id/name>
- 重启容器： docker restart <container-id/name>
- 杀死容器： docker kill <container-id/name>
- 销毁容器：docker rm <container-id/name>

#### **问题：什么是CNM？**

**答：** CNM 或容器网络模型是一种规范，它正式定义了为容器提供网络所需的步骤，同时保持用于支持多个网络驱动程序的抽象。CNM 建立在三个组件之上，即沙箱、端点和网络。

#### **问题：Docker 中有哪些不同类型的挂载类型？**

**答：**三种类型是：

- 绑定挂载：这些可以存储在主机系统的任何地方
- 卷挂载：它们由 Docker 管理并存储在主机文件系统的一部分中。
- tmpfs mount：它们存储在主机系统的内存中。这些挂载永远不能写入主机的文件系统。

#### **问题：解释Docker Trusted Registry？**

**答：**它是一个镜像存储解决方案，用于安全地存储和管理 Docker 镜像。Docker Trusted Registry 可在本地或私有云中使用。DTR 可在 CI/CD 过程中用于构建、交付和运行应用程序。DTR 具有高可用性、高效性并且具有内置的访问控制。

#### **问题：Docker_Host 的目的是什么？**

**答：** Docker_host 指定用于连接到 Docker API 的 URL 或 Unix 套接字路径。默认值为：UNIX://var/run/docker.sock

要连接到远程主机，请提供 TCP 连接字符串作为 TCP://192.0.1.20:3230

#### **问题：是否可以在同一主机上运行 Compose 文件的多个副本？如何？**

**Docker面试题解析：**这是通过使用 docker-compose 完成的。使用 Docker Compose，我们可以使用 YAML 文件来配置应用程序的服务。在此之后，只需一个命令，就可以创建和启动所有服务。要使用 Compose，请按照以下步骤操作：

- 在 Dockerfile 中定义应用环境，以便它可以在任何地方复制
- 在 docker-compose.yml 文件中定义应用程序的所有服务。
- 运行 docker-compose up 以创建并启动整个应用程序。

#### **问题：解释 Docker 对象标签。**

**答：** Docker 对象标签是一个键值对，以字符串形式存储。我们可以使用标签应用元数据。标签可以应用于 Docker 对象，如镜像、容器、卷、网络、本地守护进程、swarm 节点和服务。每个对象的键值对应该是唯一的。标签在对象的整个生命周期内都是静态的。

## Docker常见的面试题和答案合集**概括**

所以这是 Docker 面试中最热门的问题列表。你知道几个答案？在下面的评论窗口中告诉我们。此外，请查看我们的最佳 Docker 教程，由社区提交和推荐。