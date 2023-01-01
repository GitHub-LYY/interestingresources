/*
** Author: Yangyang Liu
** Date: 2023-01-01
** Description: 237. 删除链表中的节点
** link: https://leetcode.cn/problems/delete-node-in-a-linked-list/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 第一步，修改要删除节点的值为它的下一个节点的值
        node->next = node->next->next; // 第二步，删除要删除节点的下一个节点
    }
};

int main(int argc, char **argv) {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    ListNode* node = head->next;

    Solution s;
    s.deleteNode(node);

    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}