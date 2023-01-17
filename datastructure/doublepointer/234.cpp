/*
** Author: Yangyang Liu
** Date: 2023-01-17
** Description: 234. 回文链表
** link: https://leetcode.cn/problems/palindrome-linked-list/
** reference: 题解区，官方题解，方法三，快慢指针
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
    ListNode* get_first_half_end(ListNode* node) {
        ListNode* fast = node; // 定义快指针，每次走两步
        ListNode* slow = node; // 定义慢指针，每次走一步

        while (fast->next && fast->next->next) { // 保证快指针可以走两步
            fast = fast->next->next; // 快指针走两步
            slow = slow->next; // 慢指针走一步
        }

        return slow; // slow指的是链表的中间位置的节点了
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* pre = nullptr; // 定义前向空节点作为反转后链表最后节点指向的节点
        ListNode* cur = node; // 哨兵节点，不断往后走

        while (cur != nullptr) {
            ListNode* tmp = cur->next; // 保存当前节点的下一个节点
            cur->next = pre; // 当前节点下一个节点指向pre节点
            pre = cur; // pre往后走
            cur = tmp; // cur往后走
        }

        return pre; // Pre此时保存的是反转后链表的头节点
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) { // 如果是空链表，则一定是回文的
            return true;
        }

        ListNode* first_half_end = get_first_half_end(head); // 求出链表前半部分的尾部节点
        ListNode* second_half_head = reverseList(first_half_end->next); // 反转后半部分链表

        ListNode* p1 = head; // 定义前半部分链表的哨兵节点
        ListNode* p2 = second_half_head; // 定义后半部分链表的哨兵节点
        bool res = true;
        while (res && p2 != nullptr) {
            if (p1->val != p2->val) { // 有一个节点不相等，则一定不是回文的了
                res = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        first_half_end->next = reverseList(second_half_head); // 不写也行，这是使得调用完本函数后链表回到初始状态

        return res;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    bool res = s.isPalindrome(head);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}