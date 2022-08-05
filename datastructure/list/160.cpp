/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 160. 相交链表
** link: https://leetcode.cn/problems/intersection-of-two-linked-lists/
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 异常情况
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        // 定义指针指向两个链表的头节点
        ListNode* curA = headA;
        ListNode* curB = headB;

        // 定义两个链表的长度
        int lenA = 0;
        int lenB = 0;
        // 计算两个链表的长度
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        // 两个指针归位
        curA = headA;
        curB = headB;

        // 令a链表为最长的
        if (lenA < lenB) {
            swap(curA, curB);
            swap(lenA, lenB);
        }

        // 长度差
        int gap = lenA - lenB;

        // 让a链表先走长度差步
        while (gap--) {
            curA = curA->next;
        }

        // 两个指针同时走，直到相遇
        while (curA != nullptr && curB != nullptr) {
            if (curA == curB) { // 不能使用val比较，LeetCode上会出错，必须使用节点自己进行比较
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};

int main(int argc, char** argv) {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    cout << "before detect intersection: " << endl;
    ListNode* cur = headA;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cur = headB;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* intersection = s.getIntersectionNode(headA, headB);

    cout << "after detect intersection: " << endl;
    cur = intersection;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}