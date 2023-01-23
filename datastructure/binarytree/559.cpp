/*
** Author: Yangyang Liu
** Date: 2023-01-23
** Description: 559. N 叉树的最大深度
** link: https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/
** reference: 官方题解，层序遍历
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }
        queue<Node*> que; // 定义队列保存树节点
        que.push(root);

        while (!que.empty()) {
            int size = que.size(); // 求出队列节点的个数
            depth++; // 一个while是一层
            for (int i = 0; i < size; i++) {
                Node* node = que.front(); // 取出节点
                que.pop();
                vector<Node*> children = node->children; // 取出当前遍历节点的所有孩子节点
                for (auto child : children) { // 把每个子节点插入队列
                    que.push(child);
                }
            }
        }
        return depth;
    }
};

int main(int argc, char** argv) {
    Node* root = new Node(1);
    Node* root1 = new Node(3);
    Node* root2 = new Node(2);
    Node* root3 = new Node(4);
    Node* root4 = new Node(5);
    Node* root5 = new Node(6);
    root->children = {root1, root2, root3};
    root1->children = {root4, root5};

    Solution s;
    int res = s.maxDepth(root);

    cout << res << endl;

    return 0;
}