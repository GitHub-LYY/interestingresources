/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 35. 复杂链表的复制
** link: https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/
** reference: 
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// 复杂链表节点定义
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 异常情况
        if (head == nullptr) {
            return nullptr;
        }

        // 创建一个指针指向当前节点
        Node *cur = head;

        // 创建哈希表进行链表节点的映射
        unordered_map<Node*, Node*> umap;
        while (cur != nullptr) {
            // 将当前节点的值放入数组
            umap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // cur指针归位
        cur = head;

        // 循环遍历哈希表进行next和random指针的复杂
        while (cur != nullptr) {
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }

        return umap[head];
    }
};

int main(int argc, char** argv) {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    cout << "The original list is: ";
    cout << "7 -> 13 -> 11 -> 10 -> 1" << endl;

    Solution s;
    Node* res = s.copyRandomList(head);

    cout << "The copied list is : ";
    while (res != nullptr) {
        if (res->next != nullptr) {
            cout << res->val << " -> ";
        } else {
            cout << res->val << endl;
        }
        res = res->next;
    }
    cout << endl;
    
    return 0;
}