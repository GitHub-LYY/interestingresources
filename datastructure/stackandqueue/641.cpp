/*
** Author: Yangyang Liu
** Date: 2023-03-17
** Description: 641. 设计循环双端队列
** link: https://leetcode.cn/problems/design-circular-deque/
** reference: 题解区，官方题解，使用链表实现，双向链表，链表头的prev指向空，尾的next指向空
*/

#include <iostream>

using namespace std;

class DLinkListNode {
public:
    int val;
    DLinkListNode* prev;
    DLinkListNode* next;
    DLinkListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
    DLinkListNode* head;
    DLinkListNode* tail;
    int capacity; // 队列容量
    int size; // 队列元素数量
public:
    MyCircularDeque(int k) {
        capacity = k; // 容量初始化
        size = 0; // 初始化元素数量
        head = nullptr; // 初始化队头
        tail = nullptr; // 初始化队尾
    }

    bool insertFront(int value) {
        if (isFull()) { // 满了
            return false;
        }

        DLinkListNode* node = new DLinkListNode(value); // 生成节点
        if (size == 0) { // 空的
            head = tail = node;
        } else { // 头不是空的，队列有元素了
            node->next = head;
            head->prev = node; // 原来头指向新的头
            head = node; // 头
            // 头的prev指针是空的，不用再设置了
        }
        size++; // 队列元素数量多一
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) { // 队列满了
            return false;
        }

        DLinkListNode* node = new DLinkListNode(value); // 生成节点
        if (size == 0) { // 队列是空的
            head = tail = node;
        } else { // 队列不是空的，正常插入
            tail->next = node; // 原来尾部的next指向node
            node->prev = tail; // 插入节点的prev节点指向原来的tail
            tail = node; // 尾
        }
        size++; // 队列元素数量多一
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) { // 队列是空的
            return false;
        }

        DLinkListNode* node = head; // 一会删除
        head = head->next; // 头往下一个节点走
        if (head) { // 当前头不是空的
            head->prev = nullptr; // 不要忘了
        }
        delete node;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) { // 队列是空的
            return false;
        }

        DLinkListNode* node = tail; // 一会删除
        tail = tail->prev; // 尾往前走
        if (tail) { // 尾部是空
            tail->next = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) { // 空的
            return -1;
        }

        return head->val;
    }

    int getRear() {
        if (isEmpty()) { // 空的
            return -1;
        }

        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main(int argc, char** argv) {
    return 0;
}