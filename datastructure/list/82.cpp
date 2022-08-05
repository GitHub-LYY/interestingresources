/*
** Author: Yangyang Liu
** Date: 2022-08-05
** Description: 82. 删除排序链表中的重复元素 II
** link: https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 异常情况
        if (head == nullptr) {
            return head;
        }

        // 定义虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        // 定义移动指针
        ListNode* cur = dummyHead;

        // 遍历链表
        while (cur->next != nullptr && cur->next->next != nullptr) {
            // 如果下个节点和下下个节点的值相等
            if (cur->next->val == cur->next->next->val) {
                // 定义重复值
                int val = cur->next->val;
                // 遍历链表，删除所有重复值，这儿的删除是把重复值的节点跳过
                while (cur->next != nullptr && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "before delete duplicates: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* res = s.deleteDuplicates(head);

    cout << "after delete duplicates: ";
    cur = res;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}