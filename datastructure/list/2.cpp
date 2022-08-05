/*
** Author: Yangyang Liu
** Date: 2022-08-05
** Description: 2. 两数相加
** link: https://leetcode.cn/problems/add-two-numbers/
** reference: LeetCode题解区，账号chenlele，发布于20190510，两数相加，第二个解法
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 定义虚拟头节点指向新链表
        ListNode* dummyHead = new ListNode(0);
        // 定义移动指针指向新链表
        ListNode* cur = dummyHead;
        // 定义进位变量
        bool carry = false;
        // 定义和
        int sum = 0;

        // 遍历两个链表
        while (l1 != nullptr || l2 != nullptr) {
            // 每次进入循环，sum设置为0，sum是对应位的和，不能把多个位累加
            sum = 0;

            // 第一个链表不为空，则加和
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            // 第二个链表不为空，则加和
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            // 判断是否有进位
            if (carry == true) {
                sum++;
            }

            // 新链表移动指针指向此时求和的节点
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            // 如果本次加和有进位，则记录进位为true，方便下次进位加在sum中
            carry = sum >= 10 ? true : false;
        }

        // 如果最后一次加和有进位，则新链表移动指针指向进位节点
        if (carry == true) {
            cur->next = new ListNode(1);
        }

        // 返回新链表的头节点
        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "l1: ";
    ListNode* cur = l1;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cout << "l2: ";
    cur = l2;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* newNode = s.addTwoNumbers(l1, l2);

    cout << "newNode: ";
    cur = newNode;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}