/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 25. 合并两个排序的链表
** link: https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
** reference: 
*/

#include <iostream>
#include <queue>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 定义堆使用的仿函数
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 异常情况，必须考虑，否则LeetCode会报错
        if (l1 == nullptr) {
            return l2;
        } 
        if (l2 == nullptr) {
            return l1;
        }

        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        // 创建小顶堆，把l1和l2的头节点放入小顶堆中
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pri_que;
        pri_que.push(l1);
        pri_que.push(l2);

        //循环遍历小顶堆，取出堆顶元素，且把其next节点加入堆
        while (!pri_que.empty()) {
            ListNode* node = pri_que.top();
            pri_que.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr) {
                pri_que.push(node->next);
            }
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    cout << "The original list is: " << endl;
    cout << "1 -> 2 -> 4" << endl;
    cout << "1 -> 3 -> 4" << endl;

    Solution s;
    ListNode* res = s.mergeTwoLists(l1, l2);

    cout << "The merged list is: ";
    while (res != nullptr) {
        if (res->next != nullptr) {
            cout << res->val << " -> ";
        } else {
            cout << res->val;
        }
        res = res->next;
    }
    cout << endl;

    return 0;
}