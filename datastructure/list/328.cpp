/*
** Author: Yangyang Liu
** Date: 2022-08-19
** Description: 328. 奇偶链表
** link: https://leetcode.cn/problems/odd-even-linked-list/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 头节点为空
        if (head == nullptr) {
            return head;
        }

        ListNode* odd = head; // 奇数节点索引
        ListNode* evenHead = head->next;
        ListNode* even = evenHead; // 偶数节点索引

        // 遍历链表
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // 奇数节点尾部指向偶数节点头部
        odd->next = evenHead;

        return head;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* newHead = s.oddEvenList(head);

    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    
    return 0;
}