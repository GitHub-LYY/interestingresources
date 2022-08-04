/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 19. 删除链表的倒数第 N 个结点
** link: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建虚拟头结点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 创建快慢指针
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        // 快指针先走n+1步
        while (n-- && fast->next != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;

        // 快慢指针同时走
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 令slow指针指向下下个节点
        slow->next = slow->next->next;

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;

    cout << "before remove: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* newHead = s.removeNthFromEnd(head, n);

    cout << "after remove: ";
    cur = newHead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    
    return 0;
}