# C++知识点

### 指针常量、常量指针的区别？

### 顶层const（top level const）、底层const（low level const）的是什么意思？它们的区别是什么？

### 左值、右值分别是什么意思？

### STL中deque容器的内存结构是什么？

[![zligG6.png](https://s1.ax1x.com/2022/11/21/zligG6.png)](https://imgse.com/i/zligG6)

![1667383132368](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667383132368.png)

deque的内存结构是分段连续的，每一个段称为一个buffer，在每一个buffer中内存是连续的，buffer之间的内存是不连续的，但是deque号称是连续内存的，这个连续内存是在使用层面虚拟出来的连续，本质上是不连续的，仅仅在buffer内是连续的。

deque在扩充内存的时候，如果内存不够了，则在front后者back端再分配一个buffer，用指针指向这个buffer。每次扩充一个buffer。

### STL有哪些构成？

[![zlivLQ.png](https://s1.ax1x.com/2022/11/21/zlivLQ.png)](https://imgse.com/i/zlivLQ)

![1667384079716](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667384079716.png)

container有array，vector，deque，list，forward_list，而stack，queue叫做container adapter。必须指出的是，stack，queue是没有iterator的，否则能修改元素，破坏了它们的结构。没有iterator也意味着没有find函数。

### associative container的find和标准库的find的使用例子？

[![zlizZj.png](https://s1.ax1x.com/2022/11/21/zlizZj.png)](https://imgse.com/i/zlizZj)

![1667384722880](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667384722880.png)

第338行是标准库的find的使用例子，第348行是multiset自带的find的使用例子。如果container有自带的，一般使用自带的。

### unordered_set/unordered_map底层用什么数据结构实现的？

[![zlFSds.png](https://s1.ax1x.com/2022/11/21/zlFSds.png)](https://imgse.com/i/zlFSds)

![1667467862119](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667467862119.png)

使用的是hash table。而set/multiset,map/multimap底层是RBTree。RBTree有完美的数学证明，但是hash table是一个带有经验用法的结构。当元素数量大于bucket的数量的时候，bucket的数量扩充2倍，一般，bucket的数量是大于元素的数量的。例如，元素有10个，bucket也有10个，此时要扩充bucket到20个，此时的元素也要重新打乱再放入hash table。

### multimap有insert方法吗？

[![zlFCiq.png](https://s1.ax1x.com/2022/11/21/zlFCiq.png)](https://imgse.com/i/zlFCiq)

![1667468406493](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468406493.png)

没有。

![1667468475657](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468475657.png)

map有insert方法。

### unordered_set/unordered_map/unordered_multiset/unordered_multimap的从什么演变来的？

[![zlFiWV.png](https://s1.ax1x.com/2022/11/21/zlFiWV.png)](https://imgse.com/i/zlFiWV)

![1667468678278](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468678278.png)

从GNU C编译器的标准库的这几个哈希表演变来的。

### STL的allocator一般不直接使用，因为直接使用container，能直接使用吗？

[![zlFFzT.png](https://s1.ax1x.com/2022/11/21/zlFFzT.png)](https://imgse.com/i/zlFFzT)

![1667469281376](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667469281376.png)

可以直接使用，上图右边是直接使用allocator的例子，allocator是一个模板类，有两个member function，allocate和deallocate。

为什么不直接使用allocator？因为allocator使用allocate分配空间后，在调用deallocate释放空间的时候需要指定指针的位置和要释放的内存大小，单纯指定指针的位置没什么，如果每次要指定大小，没人受得了。因此，要分配和释放内存，一般使用new和delete，或者malloc和free，它们不需要在释放的时候指定要释放的内存大小。

### STL没有很多的OOP的内容，有很多的GP泛型编程的内容。OOP和GP的区别是什么？

[![zlFEyF.png](https://s1.ax1x.com/2022/11/21/zlFEyF.png)](https://imgse.com/i/zlFEyF)

![1667470536626](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667470536626.png)

[![zlFVL4.png](https://s1.ax1x.com/2022/11/21/zlFVL4.png)](https://imgse.com/i/zlFVL4)

![1667470552030](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667470552030.png)

### 模板的泛华、特化、全特化（Full specialization）、偏特化（partial specialization）的概念？

[![zlFeeJ.png](https://s1.ax1x.com/2022/11/21/zlFeeJ.png)](https://imgse.com/i/zlFeeJ)

![1667643214241](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667643214241.png)

全特化是全部的模板参数进行某种实例化，偏特化有两种，上图左边是参数数量上的偏特化，右边是类型或者范围上的偏特化。

类模板才有特化，函数模板没有。类模板需要用尖括号<>指定参数类型，而函数模板不用，函数模板有参数推导机制。

### STL中有很多类似allocator\<int>()).的用法，这个圆括号是什么意思？

这是生成了一个临时对象。

[![zlFaFI.png](https://s1.ax1x.com/2022/11/21/zlFaFI.png)](https://imgse.com/i/zlFaFI)

![1667644187929](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667644187929.png)

### 哪个编译器的哪个版本的STL易读性好？

[![zlF4pV.png](https://s1.ax1x.com/2022/11/21/zlF4pV.png)](https://imgse.com/i/zlF4pV)

![1667725911500](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667725911500.png)

GNU 编译器的2.9版本是最容易阅读的版本。

### GNU编译器的4.9版本的默认allocator没有沿用2.9版本的allocator的优秀设计，2.9的设计还在吗？

[![zlFff0.png](https://s1.ax1x.com/2022/11/21/zlFff0.png)](https://imgse.com/i/zlFff0)

![1667727450656](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667727450656.png)

2.9版本的优秀设计还在，作为扩充allocator存在，默认使用的是不优秀的，没有特殊设计的，要使用2.9版本的优秀设计，使用上图中的例子。

### STL的容器之间的关系是什么？

[![zlFI6U.png](https://s1.ax1x.com/2022/11/21/zlFI6U.png)](https://imgse.com/i/zlFI6U)

![1667727884431](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667727884431.png)

这个图是侯捷自己总结出来的。缩进代表的是composition而不是inheritance，composition意思是拥有。

### void*指针你能说些什么？

[![zlF5lT.png](https://s1.ax1x.com/2022/11/21/zlF5lT.png)](https://imgse.com/i/zlF5lT)

![1667728610797](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667728610797.png)

### STL的iterator必须要回答algorithm的问题，这些问题必须回答的有哪些？

[![zlFoXF.png](https://s1.ax1x.com/2022/11/21/zlFoXF.png)](https://imgse.com/i/zlFoXF)

![1667899815572](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667899815572.png)iterator必须要回答的有5个问题，在上图中，而目前的STL只用了三个，分别是iterator_category，value_type，difference_type。这些问题在iterator traits，iterator traits意思是提取iterator的特征，萃取。

[![zlF7m4.png](https://s1.ax1x.com/2022/11/21/zlF7m4.png)](https://imgse.com/i/zlF7m4)

![1667900466869](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667900466869.png)

traits的作用是当algorithm不能直接问出答案的时候，比如iterator不是一个class类型的，是一个指针，则直接问问不出来，需要使用traits了。

[![zlF6mQ.png](https://s1.ax1x.com/2022/11/21/zlF6mQ.png)](https://imgse.com/i/zlF6mQ)

![1667900781408](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667900781408.png)

意思是一种类型，则直接问能问出来，没问题，但是若是指针，则问不出来，因此有了traits。在设计的时候，上图，也是用了一个traits来问。

[![zlFRkn.png](https://s1.ax1x.com/2022/11/21/zlFRkn.png)](https://imgse.com/i/zlFRkn)

![1667901273410](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667901273410.png)

iterator traits是用来作为媒介存在的，algorithm问iterator问题的时候，traits回答。实现中用了partial specialization应对指针类型的。

### traits有哪些？

[![zlFsOg.png](https://s1.ax1x.com/2022/11/21/zlFsOg.png)](https://imgse.com/i/zlFsOg)

![1667901624694](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667901624694.png)

### vector容易理解，有哪些缺点呢？

vector扩容的时候是两倍扩容，因此，数量大的时候会大量调用object的copy constructor和destructor，比较慢。

### stack和queue是容器吗？有没有iterator？

stack和queue准确来说不叫容器，而叫容器适配器，container adapter。没有iterator。

### 一个类，没有data member，这个类的大小是多少字节？

理论上是0，但是大多数的编译器在实现的时候分配一个字节的大小，而C/C++使用了内存对齐，则此时的一个字节占用4个字节的空间。

### 在associative container中，哪个container有[]运算符？

只有map有[]运算符。unordered_map也有。

### 哈希表的bucket的数量怎么确定的？

在GNU C中，最小的篮子数量是53，是一个质数、素数。如果bucket不够了，也就是说元素的数量大于bucket的数量，此时要rehash，rehash的bucket的数量是多少？采用53的倍数附近的质数作为bucket的数量。

### hash function的功能是什么？

hash function的功能是计算一个object的hash code，hash code用来%上哈希表的长度，从而求出放这个object的位置。

### 函数的名称的理解？

函数的名称也是函数的地址。

### GNU C的hash function计算string的hash code的方式是什么？

[![zlFcwj.png](https://s1.ax1x.com/2022/11/21/zlFcwj.png)](https://imgse.com/i/zlFcwj)

![1668248348140](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1668248348140.png)

用每个字符的ASCII码加上5倍的自己，不断操作。这个没有标准，但是有一个原则，是要使得计算出来的hash code尽量乱，这也是hash table叫做散列表的原因。

### STL六大部件分别是什么类型的？是类模板还是函数模板？

[![zlFgTs.png](https://s1.ax1x.com/2022/11/21/zlFgTs.png)](https://imgse.com/i/zlFgTs)

![1668331488956](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1668331488956.png)

六大部分，算法是函数模板，剩下的全部是类模板。

### STL的iterator的分类有哪些？每种container的iterator是哪种类型的？

[![zlFWYq.png](https://s1.ax1x.com/2022/11/21/zlFWYq.png)](https://imgse.com/i/zlFWYq)

![1668332032687](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1668332032687.png)

iterator有图上的5种。array的iterator是random access iterator，vector的是random access iterator，deque的是random access iterator，list的是bidirectional iterator，forward list的是forward iterator，rbtree的是bidirectional iterator，hash table的需要知道每个bucket的链表是list还是forward list，是list则是bidirectional iterator，是forward list则是forward iterator。

### C++11的关键字final、override、=default、=delete是什么意思？

这几个关键字全部和类有关。

final是标记这个类不能被继承了。

override标记类的函数是重载的，编译器检查一下参数之类的。

=default是使用编译器默认生成的构造函数。

=delete是告诉编译器不要生成默认构造函数，即这个类没有默认的构造函数。

### C++的98/03标准的auto_ptr为什么在C++11中被放弃使用，取而代之的是什么？

鉴于 std：：auto_ptr 的前车之鉴，std：：unique_ptr 禁止复制语义，为了达到这个效果，std：：unique_ptr类的拷贝构造函数和赋值运算符（operator=）均被标记为=delete。

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-14-11-03-59-image.png)

不过禁止复制语义也存在特例，例如可以通过一个函数返回一个std：：unique_ptr：

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-14-11-05-26-image.png)

以上代码从func函数中得到一个std：：unique_ptr对象，然后返回给sp1。  

既然 std：：unique_ptr 不能被复制，那么如何将一个 std：：unique_ptr 对象持有的堆内存转移给另外一个呢？答案是使用移动构造，示例代码如下：

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-14-11-06-14-image.png)

以上代码利用了std：：move将sp1持有的堆内存（值为123）转移给sp2，再将sp2转移给 sp3。最后，sp1 和 sp2 不再持有堆内存的引用，变成一个空的智能指针对象。并不是所有对象的std：：move操作都有意义，只有实现了移动构造函数（Move Constructor）或移动赋值运算符（operator=）的类才行，而std：：unique_ptr正好实现了二者。以下是该实现的伪代码：

![](C:\Users\Administrator\AppData\Roaming\marktext\images\2022-11-14-11-08-40-image.png)

这就是std：：unique_ptr具有移动语义的原因。

### GDB调试中，怎么知道哪个是主线程？

使用info threads命令查看后，有星号的是当前的线程，在当前线程中使用backtrace命令，如果显示的有main函数的堆栈，则当前线程是主线程。

### functor在模板参数和STL的算法中的写法是什么？

functor在模板参数中必须写类名字，如priority_queue<int, vector<int>, Cmp> pri_que。而在算法中的参数必须写一个类的对象，如sort(vec.begin(), vec.end(), Cmp())。

### 类能继承哪些？

类能继承data member，member function等，但是也能继承typedef，这在STL标准库中经常出现。

### algorithm要问iterator问题，有没有类似的别的？

有，adapter要问functor问题，functor回答问题。

### STL的adapter能修饰container、algorithm、functor，它修饰谁，就要形成谁的样子

### 类的constructor、copy constructor、copy assignment、move constructor、move assignment能有几个？

[![z86sI0.png](https://s1.ax1x.com/2022/11/23/z86sI0.png)](https://imgse.com/i/z86sI0)

类的constructor可以有多个，但是别的一旦定义，不能有多个了。



### 内存管理的目标是什么？

两个，一个是速度，一个是空间。即时间和空间。

### new有那些？

new，array new，placement new。operator new。