/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 24. 反转链表
** link: https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
** reference: 
*/

#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 异常情况
        if (head == nullptr) {
            return nullptr;
        }

        // 创建pre和cur指针
        ListNode *pre = nullptr;
        ListNode* cur = head;

        // 循环遍历链表
        while (cur != nullptr) {
            // 创建临时变量保存当前节点的下一个节点
            ListNode *tmp = cur->next;

            // 将当前节点的下一个节点指向pre
            cur->next = pre;

            // pre和cur后移
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "The original list is: ";
    cout << "1 -> 2 -> 3 -> 4 -> 5" << endl;

    Solution s;
    ListNode* res = s.reverseList(head);

    cout << "The reversed list is: ";
    while (res != nullptr) {
        if (res->next != nullptr) {
            cout << res->val << " -> ";
        } else {
            cout << res->val;
        }
        res = res->next;
    }
    
    return 0;
}