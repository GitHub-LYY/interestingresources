/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 面试题 02.07. 链表相交
** link: https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
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

        // 创建两个指针分别指向两个链表的头节点
        ListNode* curA = headA;
        ListNode* curB = headB;

        // 求两个链表的长度
        int lenA = 0;
        int lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        // 链表指针归位
        curA = headA;
        curB = headB;

        // 令a链表为最长的链表
        if (lenA < lenB) {
            swap(curA, curB);
            swap(lenA, lenB);
        }

        // 将长链表的长度减去短链表的长度
        int gap = lenA - lenB;

        // 将长链表的指针向后移动gap个节点
        while (gap--) {
            curA = curA->next;
        }

        // 循环比较两个链表的节点是否相同
        while (curA != nullptr && curB != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        // 如果两个链表的节点都遍历完了，说明没有相交的节点
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
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    cout << "two lists are:" << endl;
    ListNode* curA = headA;
    while (curA != nullptr) {
        cout << curA->val << " ";
        curA = curA->next;
    }
    cout << endl;
    ListNode* curB = headB;
    while (curB != nullptr) {
        cout << curB->val << " ";
        curB = curB->next;
    }
    cout << endl;

    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);

    cout << "the intersection node is:" << endl;
    if (res != nullptr) {
        cout << res->val << endl;
    } else {
        cout << "no intersection node" << endl;
    }

    return 0;
}