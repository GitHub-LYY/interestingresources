/*
** Author: Yangyang Liu
** Date: 2022-08-05
** Description: 143. 重排链表
** link: https://leetcode.cn/problems/reorder-list/
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
    ListNode* getMidNode(ListNode* head) {
        // 定义快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) { // fast不能指向空指针
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow指向中间节点
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        // 定义pre和cur指针
        ListNode* pre = nullptr;
        ListNode* cur = head;
        
        // 反转链表
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // 返回反转后的头节点
        return pre;
    }

    void mergeList(ListNode* head1, ListNode* head2) {
        // 定义两个指针指向两个链表的头节点
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;

        // 合并链表
        while (cur1 != nullptr && cur2 != nullptr) {
            // 保存下一个节点
            ListNode* tmp1 = cur1->next;
            ListNode* tmp2 = cur2->next;

            // 合并
            cur1->next = cur2;
            cur2->next = tmp1;

            // 更新指针
            cur1 = tmp1;
            cur2 = tmp2;
        }
    }

    void reorderList(ListNode* head) {
        // 异常情况
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 定位中间节点
        ListNode* mid = getMidNode(head);

        // 分离前后两个链表
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        
        // 断开两个链表
        mid->next = nullptr;

        // 反转后半部分链表
        list2 = reverseList(list2);

        // 合并两个链表
        mergeList(list1, list2);
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "before reorder:" << endl;
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution().reorderList(head);

    cout << "after reorder:" << endl;
    cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    
    return 0;
}