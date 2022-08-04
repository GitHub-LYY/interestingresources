/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 21. 合并两个有序链表
** link: https://leetcode.cn/problems/merge-two-sorted-lists/
** reference: 
*/

#include <iostream>
#include <queue>

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
    // 定义仿函数设计小顶堆
    class Cmp {
    public:
        bool operator()(ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        }
    };
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 异常情况
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        // 定义小顶堆
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pri_que;

        // 把两个链表的投节点分别入堆
        pri_que.push(list1);
        pri_que.push(list2);

        // 取出堆顶节点，放入新链表
        while(!pri_que.empty()) {
            // 取出堆顶节点
            ListNode* node = pri_que.top();
            pri_que.pop();

            // 放入新链表
            cur->next = node;
            cur = cur->next;

            // 如果堆顶节点的下一个节点不为空，则入堆
            if (node->next != nullptr) {
                pri_que.push(node->next);
            }
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    // 定义第一个链表
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // 定义第二个链表
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // 输出两个链表
    cout << "before merge: " << endl;
    ListNode* cur = list1;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = list2;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 合并两个链表
    Solution s;
    ListNode* mergedList = s.mergeTwoLists(list1, list2);

    // 输出合并后的链表
    cout << "after merge: " << endl;
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}