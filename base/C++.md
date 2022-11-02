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