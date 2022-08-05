/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 141. 环形链表
** link: https://leetcode.cn/problems/linked-list-cycle/
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
    bool hasCycle(ListNode* head) {
        // 异常情况
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // 定义快慢指针
        ListNode* fast = head;
        ListNode* slow = head;

        // 快指针每次走两步，慢指针每次走一步，如果相遇，则有环
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(3);  
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << "before detect cycle: ";
    cout << head->val << " ";
    cout << head->next->val << " ";
    cout << head->next->next->val << " ";
    cout << head->next->next->next->val << " ";
    cout << endl;

    Solution s;
    bool result = s.hasCycle(head);

    cout << "after detect cycle: ";
    cout << "Is there a cycle? " << result << endl;
    
    return 0;
}