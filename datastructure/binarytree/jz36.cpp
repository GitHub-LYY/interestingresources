/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 36. 二叉搜索树与双向链表
** link: https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
** reference: 题解区，搜索，二叉搜索树与双向链表 | 图解链表 | 最通俗易懂的题解【c++/java版本】，作者，林小鹿
*/

#include <iostream>

using namespace std;

// 树节点定义
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    // 定义前驱节点，头节点
    Node* pre = nullptr;
    Node* head = nullptr;
    void traversal(Node* cur) {
        if (cur == nullptr) {
            return;
        }

        traversal(cur->left);
        if (pre) {
            pre->right = cur;
        } else {
            // pre为空，则cur指向的是第一个节点

            head = cur;
        }
        cur->left = pre; // cur的left指向前驱
        pre = cur;
        traversal(cur->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        // 二叉搜索树使用中序遍历

        // 必须有，否则LeetCode报错
        if (root == nullptr) {
            return head;
        }

        traversal(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};

int main(int argc, char** argv) {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);

    Solution s;
    Node* res = s.treeToDoublyList(root);

    cout << "res:" << res->val << endl;

    return 0;
}