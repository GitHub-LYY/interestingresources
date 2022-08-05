/*
** Author: Yangyang Liu
** Date: 2022-08-05
** Description: 148. 排序链表
** link: https://leetcode.cn/problems/sort-list/
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
    class Cmp {
    public:
        // 小顶堆仿函数
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* sortList(ListNode* head) {
        // 异常情况
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 定义虚拟头节点指向排序后的链表
        ListNode* dummyHead = new ListNode(0);
        // 定义cur指针指向排序后链表
        ListNode* cur = dummyHead;

        // 定义小顶堆
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pri_que;

        // 链表元素入堆
        while (head != nullptr) {
            pri_que.push(head);
            head = head->next;
        }

        // 堆元素出堆
        while (!pri_que.empty()) {
            ListNode* node = pri_que.top();
            pri_que.pop();
            cur->next = node;
            cur = cur->next;
        }

        // 将链表尾节点指向空
        cur->next = nullptr; // 必须有，否则会出现环

        // 此时链表排好序
        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "before sort: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* res = s.sortList(head);

    cout << "after sort: ";
    cur = res;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}