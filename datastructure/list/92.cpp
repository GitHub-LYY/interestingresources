/*
** Author: Yangyang Liu
** Date: 2022-08-05
** Description: 92. 反转链表 II
** link: https://leetcode.cn/problems/reverse-linked-list-ii/
** reference: 
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
    ListNode* reverse(ListNode* head) {
        // 传进来的节点不存在异常情况

        // 定义pre、cur
        ListNode* pre = nullptr;
        ListNode* cur = head;
        
        // 遍历链表
        while (cur != nullptr) {
            // 保存下一个节点
            ListNode* tmp = cur->next;

            // 反转
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 定义虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 定义cur指针
        ListNode* cur = dummyHead;

        // 定义pre、start、end、next指针
        ListNode* pre = cur;
        ListNode* start = cur;
        ListNode* end = cur;
        ListNode* next = cur;

        // 定义变量使得pre指向该指向的位置
        int idxForPre = left - 1;

        // pre走到该走的位置
        while (idxForPre--) {
            pre = pre->next;
        }

        // start、end、next初始化
        start = pre->next;
        end = start;
        next = start;

        // end走到该走的位置
        int idxForEnd = right - left;
        for (int i = 0; i < idxForEnd; i++) {
            end = end->next;
        }

        // next指向end的下一个节点
        next = end->next;

        // 断开链表，反转链表
        end->next = nullptr;
        end = start;
        start = reverse(start);
        
        // 把翻转后的链表串起来
        pre->next = start;
        end->next = next;

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2;
    int right = 4;

    cout << "Input: head = [1, 2, 3, 4, 5], left = 2, right = 4" << endl;

    Solution s;
    ListNode* res = s.reverseBetween(head, left, right);

    cout << "After reverse:" << endl;
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    
    return 0;
}