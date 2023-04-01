/*
** Author: Yangyang Liu
** Date: 2023-04-01
** Description: 147. 对链表进行插入排序
** link: https://leetcode.cn/problems/insertion-sort-list/
** reference: 官方题解
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* dummyHead = new ListNode(0); // 虚拟头节点
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode* prev = dummyHead;
                while (prev->next->val <= cur->val) {
                    prev = prev->next;
                }

                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode* res = s.insertionSortList(head);

    cout << res->val << endl;

    return 0;
}