/*
** Author: Yangyang Liu
** Date: 2022-08-19
** Description: 61. 旋转链表
** link: https://leetcode.cn/problems/rotate-list/
** reference: 题解区，搜索，旋转链表 | 图解链表 | 最清晰易懂的题解 【c++/java版本】，作者，林小鹿
*/

#include <iostream>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 头节点为空，或者k为0，则不用旋转
        if (head == nullptr || k == 0) {
            return head;
        }

        // 定义变量保存链表长度
        int len = 0;

        // 定义变量保存链表尾部节点
        ListNode* tail; // 初始化为nullptr，LeetCode编译器会报错

        // 求出链表长度和尾部节点
        ListNode* cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
            if (cur != nullptr && cur->next == nullptr) {
                tail = cur;
            }
        }

        // k对len取余，是最后的旋转次数
        int rotate = k % len;

        // 第二次遍历链表，遍历长度是n-roate
        int count = len - rotate - 1; // 减去一
        cur = head;
        while (count--) {
            cur = cur->next;
        }

        // cur指向的节点是新的尾节点，cur->next是新的头节点

        // 进行旋转
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;

    Solution s;
    ListNode* newHead = s.rotateRight(head, k);

    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}