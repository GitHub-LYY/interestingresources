/*
** Author: Yangyang Liu
** Date: 2022-08-08
** Description: 117. 填充每个节点的下一个右侧节点指针 II
** link: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
** reference: 代码随想录
*/

#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点定义
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // 定义队列，保存树节点
        queue<Node*> que;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，循环遍历
        while (!que.empty()) {
            // 获取队列的大小，即当前层的节点个数
            int size = que.size();

            // 定义变量保存每一层第一个节点和非第一个个节点
            Node* nodePre = nullptr;
            Node* node = nullptr;

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 队头元素和非队头元素的处理方式不一样
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre; // 这儿是为了使子节点入队操作一致，这儿也赋值
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = node;
                }

                // 如果当前节点的左子节点不为空，则入队 
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                
                // 如果当前节点的右子节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

            // 遍历完当前层的节点，将最后一个节点的next指针置为空
            nodePre->next = nullptr;
        }

        return root;
    }
};

int main(int argc, char** argv) {
    // 创建二叉树
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution s;
    Node* result = s.connect(root);

    return 0;
}