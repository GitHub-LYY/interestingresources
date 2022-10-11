/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 707. 设计链表
** link: https://leetcode.cn/problems/design-linked-list/
** reference: 
*/

#include <iostream>

using namespace std;

class MyLinkedListOld {
public:
    // 定义链表节点
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x) : val(x), next(NULL) {}
    };

    MyLinkedListOld() {
        // 初始化链表
        _size = 0;
        _dummyHead = new LinkedNode(0);
    }

    int get(int index) {
        // 异常情况
        if (index < 0 || index >= _size) {
            return -1;
        }
        
        // 创建指针指向当前节点
        LinkedNode *cur = _dummyHead->next;
        
        // 循环遍历链表
        for (int i = 0; i < index; i++) {
            // 指针后移
            cur = cur->next;
        }
        
        return cur->val;
    }

    void addAtHead(int val) {
        // 创建新节点
        LinkedNode *newNode = new LinkedNode(val);
        
        // 新节点指向原链表的头节点
        newNode->next = _dummyHead->next;
        
        // 头节点指向新节点
        _dummyHead->next = newNode;
        
        // 更新链表大小
        _size++;
    }

    void addAtTail(int val) {
        // 创建新节点
        LinkedNode *newNode = new LinkedNode(val);
        
        // 循环遍历链表
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            // 指针后移
            cur = cur->next;
        }
        
        // cur此时是最后一个节点，在其后面添加新节点
        cur->next = newNode;
        
        // 更新链表大小
        _size++;
    }

    void addAtIndex(int index, int val) {
        // 异常情况
        if (index < 0 || index > _size) {
            return;
        }
        
        // 创建新节点
        LinkedNode *newNode = new LinkedNode(val);
        
        // 循环遍历链表
        LinkedNode *cur = _dummyHead;
        for (int i = 0; i < index; i++) {
            // 指针后移
            cur = cur->next;
        }
        
        // 新节点指向原链表的cur节点的下一个节点
        newNode->next = cur->next;
        
        // cur节点指向新节点
        cur->next = newNode;
        
        // 更新链表大小
        _size++;
    }

    void deleteAtIndex(int index) {
        // 异常情况
        if (index < 0 || index >= _size) {
            return;
        }
        
        // 循环遍历链表
        LinkedNode *cur = _dummyHead;
        for (int i = 0; i < index; i++) {
            // 指针后移
            cur = cur->next;
        }
        
        // cur节点指向cur节点的下一个节点
        cur->next = cur->next->next;
        
        // 更新链表大小
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

class MyLinkedList {
// 这是在自己不看答案的情况下写出的，有了自己的理解，看这个版本

public:
    // 定义链表节点结构体
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {} // 构造函数不要忘了
    };

    MyLinkedList() {
        dummyHead = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        // 索引越界了
        if (index < 0 || index >= size) {
            return -1;
        }

        // 定义指针遍历链表
        ListNode* cur = dummyHead;

        // 遍历链表
        while (index--) {
            // index--，此时的cur指向的是要的节点的前一个节点

            cur = cur->next;
        }

        return cur->next->val;
    }

    void addAtHead(int val) {
        // new出新的节点
        ListNode* newNode = new ListNode(val);

        // 新节点指向虚拟头节点的下一个节点
        newNode->next = dummyHead->next;

        // 虚拟头节点指向这个新的节点
        dummyHead->next = newNode;

        // 别忘了节点数量多了一个
        size++;

        return; // 写不写看个人习惯了
    }

    void addAtTail(int val) {
        // new出新的节点
        ListNode* newNode = new ListNode(val);

        // 定义指针遍历链表
        ListNode* cur = dummyHead;

        // 遍历链表到最后一个
        while (cur->next != nullptr) {
            // 结束后，cur指向的是最后一个节点

            cur = cur->next;
        }

        // 最后一个节点指向新的节点
        cur->next = newNode;

        // 不要忘了节点数量多了
        size++;

        return; // 写不写看个人习惯了
    }

    void addAtIndex(int index, int val) {
        // 这个函数根据题意写，前一版本carl的版本没有完全根据题意，即使也可以ac，看这个版本，自己的理解

        if (index < 0) {
            // 插入头部

            // 直接调用写好的函数
            addAtHead(val);
            return; // 不要忘了退出
        } else if (index == size) {
            // 插入尾部

            // 直接调用写好的函数
            addAtTail(val);
            return; // 不要忘了退出
        } else if (index > size) {
            // 不做事情

            return; // 直接退出
        } else {
            // 索引满足要求，插入要插入的地方

            // 定义指针遍历链表
            ListNode* cur = dummyHead;

            // 遍历链表
            while (index--) {
                cur = cur->next; // 最后的cur指向的是插入位置的前一个节点
            }

            // new出新的节点
            ListNode* newNode = new ListNode(val);

            // 新节点指向下一个节点
            newNode->next = cur->next;

            // 指向新的节点
            cur->next = newNode;

            // 不要忘了节点数量多了
            size++;

            return; // 写不写看个人习惯了
        }

        return;
    }

    void deleteAtIndex(int index) {
        // 索引越界
        if (index < 0 || index >= size) {
            return;
        }

        // 定义变量保存遍历的节点
        ListNode* cur = dummyHead;

        // 遍历链表
        while (index--) {
            cur = cur->next;
        }

        // 删除要删除的节点
        cur->next = cur->next->next; // 这没有delete释放内存，题目说了可以不用释放

        // 不要忘了节点数量减少了
        size--;

        return; // 写不写看个人习惯了
    }

private:
    ListNode* dummyHead;
    int size;
};

int main(int argc, char** argv) {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    cout << linkedList.get(1) << endl;
    linkedList.deleteAtIndex(1);
    cout << linkedList.get(1) << endl;

    return 0;
}