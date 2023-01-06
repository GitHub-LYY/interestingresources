/*
** Author: Yangyang Liu
** Date: 2023-01-06
** Description: 138. 复制带随机指针的链表
** link: https://leetcode.cn/problems/copy-list-with-random-pointer/
** reference: 题解区，剑指offer35题
*/

#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) { // 链表是空
            return head;
        }

        Node* cur = head; // cur用来遍历链表
        unordered_map<Node*, Node*> node2node; // 哈希表保存链表节点
        while (cur != nullptr) {
            node2node[cur] = new Node(cur->val); // 这个循环仅仅保存val
            cur = cur->next; // 这句和上句顺序不能调换，否则错误，一开始写错了
        }

        cur = head; // cur归位
        while (cur != nullptr) {
            node2node[cur]->next = node2node[cur->next];
            node2node[cur]->random = node2node[cur->random];
            cur = cur->next;
        }

        return node2node[head];
    }
};

int main(int argc, char** argv) {
    return 0;
}