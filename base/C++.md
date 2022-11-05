# C++知识点

### 指针常量、常量指针的区别？



### 顶层const（top level const）、底层const（low level const）的是什么意思？它们的区别是什么？



### 左值、右值分别是什么意思？



### STL中deque容器的内存结构是什么？

![1667383132368](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667383132368.png)

deque的内存结构是分段连续的，每一个段称为一个buffer，在每一个buffer中内存是连续的，buffer之间的内存是不连续的，但是deque号称是连续内存的，这个连续内存是在使用层面虚拟出来的连续，本质上是不连续的，仅仅在buffer内是连续的。

deque在扩充内存的时候，如果内存不够了，则在front后者back端再分配一个buffer，用指针指向这个buffer。每次扩充一个buffer。



### STL有哪些构成？

![1667384079716](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667384079716.png)

container有array，vector，deque，list，forward_list，而stack，queue叫做container adapter。必须指出的是，stack，queue是没有iterator的，否则能修改元素，破坏了它们的结构。没有iterator也意味着没有find函数。



### associative container的find和标准库的find的使用例子？

![1667384722880](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667384722880.png)

第338行是标准库的find的使用例子，第348行是multiset自带的find的使用例子。如果container有自带的，一般使用自带的。

### unordered_set/unordered_map底层用什么数据结构实现的？

![1667467862119](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667467862119.png)

使用的是hash table。而set/multiset,map/multimap底层是RBTree。RBTree有完美的数学证明，但是hash table是一个带有经验用法的结构。当元素数量大于bucket的数量的时候，bucket的数量扩充2倍，一般，bucket的数量是大于元素的数量的。例如，元素有10个，bucket也有10个，此时要扩充bucket到20个，此时的元素也要重新打乱再放入hash table。



### multimap有insert方法吗？

![1667468406493](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468406493.png)

没有。

![1667468475657](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468475657.png)

map有insert方法。

### unordered_set/unordered_map/unordered_multiset/unordered_multimap的从什么演变来的？

![1667468678278](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667468678278.png)

从GNU C编译器的标准库的这几个哈希表演变来的。

### STL的allocator一般不直接使用，因为直接使用container，能直接使用吗？

![1667469281376](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667469281376.png)

可以直接使用，上图右边是直接使用allocator的例子，allocator是一个模板类，有两个member function，allocate和deallocate。

为什么不直接使用allocator？因为allocator使用allocate分配空间后，在调用deallocate释放空间的时候需要指定指针的位置和要释放的内存大小，单纯指定指针的位置没什么，如果每次要指定大小，没人受得了。因此，要分配和释放内存，一般使用new和delete，或者malloc和free，它们不需要在释放的时候指定要释放的内存大小。

### STL没有很多的OOP的内容，有很多的GP泛型编程的内容。OOP和GP的区别是什么？

![1667470536626](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667470536626.png)

![1667470552030](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667470552030.png)

### 模板的泛华、特化、全特化（Full specialization）、偏特化（partial specialization）的概念？

![1667643214241](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667643214241.png)

全特化是全部的模板参数进行某种实例化，偏特化有两种，上图左边是参数数量上的偏特化，右边是类型或者范围上的偏特化。

类模板才有特化，函数模板没有。类模板需要用尖括号<>指定参数类型，而函数模板不用，函数模板有参数推导机制。

### STL中有很多类似allocator\<int>()).的用法，这个圆括号是什么意思？

这是生成了一个临时对象。

![1667644187929](C:\Users\nsus\AppData\Roaming\Typora\typora-user-images\1667644187929.png)