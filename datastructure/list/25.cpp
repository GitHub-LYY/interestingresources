/*
** Author: Yangyang Liu
** Date: 2022-08-04
** Description: 25. K 个一组翻转链表
** link: https://leetcode.cn/problems/reverse-nodes-in-k-group/
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
        // 能进来则没有异常情况

        //创建pre和cur指针
        ListNode* pre = nullptr;
        ListNode* cur = head;

        //循环
        while (cur != nullptr) {
            //保存cur的下一个节点
            ListNode* tmp = cur->next;

            //将cur的下一个节点指向pre
            cur->next = pre;

            //将pre和cur同时向后移动
            pre = cur;
            cur = tmp;
        }

        //返回pre，即新的链表头节点
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 异常情况
        if (head == nullptr || head->next == nullptr || k < 2) {
            return head;
        }

        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 定义pre、start、end、next指针，其中start-end是k个节点的区间
        ListNode* pre = dummyHead;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* next = head;

        // 循环，直到end指针为空，end为空，则最后不够k个节点了
        while (end != nullptr) { // start、end、next进入到这儿，是在一个位置，这的end改为其他两个也行
            // 先移动end指针，把end指针归位，
            // 中间&&后边括号的是必须的，while进来的end不为空只能保证在进来的时候不为空，但是end是一直往后走的，所以这儿必须有
            for (int i = 0; (i < k - 1) && (end != nullptr); i++) { 
                end = end->next;
            }
            
            // end指针为空，处理
            if(end == nullptr) { // 这儿已经有end为空的处理了，所以while循环中判断next
                break;
            }

            // end指针不为空，则next指针归位
            next = end->next;

            // 反转区间
            end->next = nullptr;
            end = start;
            // reverse知道翻转多长的原因：之前一直不理解，现在理解了，是因为把end指向了空，空是链表的末尾
            start = reverse(start);
            // 把翻转的区间串起来
            pre->next = start;
            end->next = next;

            // 重置四个指针，next已经在他该在的位置了，不用重置了
            pre = end;
            start = next;
            end = start;
        }

        return dummyHead->next;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;

    cout << "Before reverse:" << endl;
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution s;
    ListNode* newHead = s.reverseKGroup(head, k);

    cout << "After reverse:" << endl;
    cur = newHead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}