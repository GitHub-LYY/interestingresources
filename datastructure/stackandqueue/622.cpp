/*
** Author: Yangyang Liu
** Date: 2023-03-17
** Description: 622. 设计循环队列
** link: https://leetcode.cn/problems/design-circular-queue/
** reference: 题解区，官方题解，使用链表实现，比数组实现的简单容易理解
*/

#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class MyCircularQueue {
private:
    ListNode* head; // 头节点代表队列头
    ListNode* tail; // 尾节点代表队列尾
    int capacity; // 队列容量
    int size; // 队列中元素数量
public:
    MyCircularQueue(int k) {
        this->capacity = k; // 容量初始化
        this->size = 0; // 当前没有元素
        this->head = nullptr; // 头节点是空
        this->tail = nullptr; // 尾节点是空
    }

    bool enQueue(int value) {
        if (isFull()) { // 队列满了，则插入失败
            return false;
        }

        ListNode* newNode = new ListNode(value); // 生成链表节点准备入队
        if (!head) { // 队列是空的 
            head = newNode; // 产生的节点是头节点
            tail = newNode; // 头尾，一开始忘了
        } else { // 队列不是空的
            tail->next = newNode; // 在链表尾部插入节点
            tail = newNode; // 标记尾部节点
        }
        size++; // 元素数量多一
        return true; // 插入成功
    }

    bool deQueue() {
        if (isEmpty()) { // 队列是空的，则取出失败
            return false;
        }

        ListNode* node = head; // 队首是要出队的
        head = head->next; // 调整队头
        delete node; // 删除出队的
        size--; // 元素数量少一
        return true;
    }

    int Front() {
        if (isEmpty()) { // 空的，则没有头
            return -1;
        }

        return head->val;
    }

    int Rear() {
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