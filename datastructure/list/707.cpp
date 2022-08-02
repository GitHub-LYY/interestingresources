/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 707. 设计链表
** link: https://leetcode.cn/problems/design-linked-list/
** reference: 
*/

#include <iostream>

using namespace std;

class MyLinkedList {
public:
    // 定义链表节点
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x) : val(x), next(NULL) {}
    };

    MyLinkedList() {
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