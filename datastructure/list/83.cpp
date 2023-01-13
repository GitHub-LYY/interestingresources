/*
** Author: Yangyang Liu
** Date: 2023-01-13
** Description: 83. 删除排序链表中的重复元素
** link: https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head; // 定义指针用来遍历链表

        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next; // 去重
            } else {
                cur = cur->next; // 不重复，则直接往后走
            }
        }

        return head;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    Solution s;
    ListNode* res = s.deleteDuplicates(head);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}