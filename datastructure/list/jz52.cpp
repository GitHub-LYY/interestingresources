/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 52. 两个链表的第一个公共节点
** link: https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
** reference: 
*/

#include <iostream>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 异常情况
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        // 创建临时指针指向headA和headB
        ListNode* curA = headA;
        ListNode* curB = headB;
        // 创建遍历保存两个链表的长度
        int lenA = 0;
        int lenB = 0;

        // 循环遍历链表，计算长度
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        // 临时遍历归位
        curA = headA;
        curB = headB;

        // 如果B的长度更长，把A变为更长的
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 计算差值
        int gap = lenA - lenB;

        // A先走gap步，达到和B平齐
        while (gap--) {
            curA = curA->next;
        }

        // 循环遍历，直到相交
        while (curA != nullptr && curB != nullptr) {
            if (curA == curB) {
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
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    headB->next->next->next->next = headA->next->next->next;
    headB->next->next->next->next->next = headA->next->next->next->next;

    cout << "headA: ";
    ListNode* curA = headA;
    while (curA != nullptr) {
        cout << curA->val << " ";
        curA = curA->next;
    }
    cout << endl;

    cout << "headB: ";
    ListNode* curB = headB;
    while (curB != nullptr) {
        cout << curB->val << " ";
        curB = curB->next;
    }
    cout << endl;

    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);

    cout << "res: ";
    if (res != nullptr) {
        cout << res->val << " ";
    }

    return 0;
}