/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 06. 从尾到头打印链表
** link: https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
** reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public: 
    vector<int> reversePrint(ListNode* head) {
        // 创建一个数组保存结果
        vector<int> res;

        // 异常情况
        if (head == nullptr) {
            return res;
        }

        // 创建一个指针指向当前节点
        ListNode *cur = head;

        // 循环遍历链表
        while (cur != nullptr) {
            // 将当前节点的值放入数组
            res.push_back(cur->val);

            // 指针后移
            cur = cur->next;
        }

        // 对数组做reverse操作
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);

    cout << "The original list is: ";
    cout << "1 -> 3 -> 2" << endl;

    Solution s;
    vector<int> res = s.reversePrint(head);

    cout << "The reversed list is: ";
    for (int i = 0; i < res.size() - 1; i++) {
        cout << res[i] << " -> ";
    }
    cout << res[res.size() - 1] << endl;
    cout << endl;

    return 0;
}