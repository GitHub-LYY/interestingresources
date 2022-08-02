/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 18. 删除链表的节点
** link: https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
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
    ListNode* deleteNode(ListNode* head, int val) {
        // 异常情况
        if (head == nullptr) {
            return head;
        }

        // 创建虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        // 定义cur指针指向虚拟头结点
        ListNode *cur = dummyHead;

        // 循环遍历链表
        while (cur->next != nullptr) {
            // 如果当前节点的值等于val，则删除当前节点
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                // 指针后移
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    int val = 5;

    cout << "The original list is: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        if (cur->next != nullptr) {
            cout << cur->val << " -> ";
        } else {
            cout << cur->val << endl;
        }
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* res = s.deleteNode(head, val);

    cout << "The list after deleting is: ";
    cur = res;
    while (cur != nullptr) {
        if (cur->next != nullptr) {
            cout << cur->val << " -> ";
        } else {
            cout << cur->val << endl;
        }
        cur = cur->next;
    }
    cout << endl;
    
    return 0;
}