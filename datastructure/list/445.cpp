/*
** Author: Yangyang Liu
** Date: 2023-01-02
** Description: 445. 两数相加 II
** link: https://leetcode.cn/problems/add-two-numbers-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 定义栈
        stack<int> s1;
        stack<int> s2;

        // 入栈
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        // 定义进位
        int carry = 0;

        // 定义变量保存结果
        ListNode* res = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top(); // 求出两个运算的数

            if (!s1.empty()) { // 取出栈顶的数了，要弹出栈
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }

            int cur = a + b + carry; // 求出和
            carry = cur / 10; // 取出进位
            cur %= 10; // 求出当前结果节点要保存的值
            ListNode* curNode = new ListNode(cur); // 求出要保存的节点
            curNode->next = res;
            res = curNode;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);

    ListNode* cur = res;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}