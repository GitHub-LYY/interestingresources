/*
** Author: Yangyang Liu
** Date: 2022-07-26
** Description: 23.合并k个排序链表
** link: https://leetcode.cn/problems/merge-k-sorted-lists/submissions/
** reference: https://blog.csdn.net/wenningker/article/details/124468136
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 定义优先级队列使用的仿函数
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // 小的优先级高
        }
    };

    // 核心代码
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义虚拟头结点
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        // 定义优先级队列，把lists中的每个链表的头结点入队
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pri_que;
        for (auto node : lists) {
            if (node != nullptr) {
                pri_que.push(node);
            }
        }

        // 循环遍历优先级队列，每次取出的是最小的链表的头结点，放入cur的后面，并将其的下一个结点入队
        // 循环结束后，所有节点全部合并完毕
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
    // 测试用例
    vector<ListNode*> lists;

    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(5);

    ListNode* node2 = new ListNode(1);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);

    ListNode* node3 = new ListNode(2);
    node3->next = new ListNode(6);

    lists.push_back(node1);
    lists.push_back(node2);
    lists.push_back(node3);

    // 输出测试用例
    cout << "Before merge:" << endl;
    cout << "list1:";
    while (node1 != nullptr) {
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;

    cout << "list2:";
    while (node2 != nullptr) {
        cout << node2->val << " ";
        node2 = node2->next;
    }
    cout << endl;

    cout << "list3:";
    while (node3 != nullptr) {
        cout << node3->val << " ";
        node3 = node3->next;
    }
    cout << endl;

    // 执行测试用例
    Solution s;
    s.mergeKLists(lists);

    // 输出结果
    cout << "After merge:" << endl;
    ListNode* cur = lists[0];
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}