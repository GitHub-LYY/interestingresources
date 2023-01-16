/*
** Author: Yangyang Liu
** Date: 2023-01-16
** Description: 86. 分隔链表
** link: https://leetcode.cn/problems/partition-list/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0); // 定义小链表的哨兵
        ListNode* smallHead = small; // 定义小链表的虚拟头节点
        ListNode* big = new ListNode(0); // 定义大链表的哨兵
        ListNode* bigHead = big; // 定义大链表的虚拟头节点

        while (head != nullptr) {
            if (head->val < x) { // 当前遍历节点的值小于x
                small->next = head; // 把当前节点插入小链表
                small = small->next; // 小链表哨兵往后走
            } else { // 当前遍历节点的值大于等于x
                big->next = head; // 把当前节点插入大链表
                big = big->next; // 大链表哨兵往后走
            }

            head = head->next; // 遍历当前节点
        }

        big->next = nullptr; // 大链表尾部指向空
        small->next = bigHead->next; // 小链表尾部指向大链表头部
        return smallHead->next; // 小链表头部是拼接后的链表的开始的节点
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    int x = 3;

    Solution s;
    ListNode* res = s.partition(head, x);

    cout << res->val << endl;

    return 0;
}