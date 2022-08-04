/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 142. 环形链表 II
** link: https://leetcode.cn/problems/linked-list-cycle-ii/
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
    ListNode* detectCycle(ListNode* head) {
        // 异常情况
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // 创建两个指针分别指向两个链表的头节点
        ListNode* slow = head;
        ListNode* fast = head;

        // 循环
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            // 如果两个指针相遇，则说明链表有环
            if (fast == slow) {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }

        // 如果没有环，则返回nullptr
        return nullptr;
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
    ListNode* intersectionNode = s.detectCycle(head);

    if (intersectionNode != nullptr) {
        cout << "intersection node: " << intersectionNode->val << endl;
    } else {
        cout << "no cycle" << endl;
    }
    
    return 0;
}