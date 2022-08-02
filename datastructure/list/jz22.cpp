/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 22. 链表中倒数第k个节点
** link: https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
** reference: https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html#%E6%80%9D%E8%B7%AF
*/

#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 异常情况
        if (head == nullptr || k <= 0) {
            return nullptr;
        }

        // 创建快慢指针
        ListNode* fast = head;
        ListNode* slow = head;

        // 快指针先走k步
        while (k--) {
            fast = fast->next;
        }

        // 快慢指针同时走
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "The original list is: ";
    cout << "1 -> 2 -> 3 -> 4 -> 5" << endl;

    Solution s;
    int k = 2;
    ListNode* res = s.getKthFromEnd(head, k);

    cout << "The " << k << "th from end is: ";
    for (int i = 0; i < k - 1; i++) {
        cout << res->val << " -> ";
        res = res->next;
    }
    cout << res->val << endl;
    cout << endl;

    return 0;
}