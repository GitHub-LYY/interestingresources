/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 24. 两两交换链表中的节点
** link: https://leetcode.cn/problems/swap-nodes-in-pairs/
** reference: 
*/

#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 异常情况
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 创建虚拟头结点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        // 循环遍历链表
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;
            cur = cur->next->next;
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "before swap: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* newHead = s.swapPairs(head);

    cout << "after swap: ";
    cur = newHead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    
    return 0;
}