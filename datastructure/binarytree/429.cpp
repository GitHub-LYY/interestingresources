/*
** Author: Yangyang Liu
** Date: 2022-08-08,2023-01-20
** Description: 429. N 叉树的层序遍历
** link: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
** reference: 代码随想录
** 20230120，官方题解
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N叉树节点定义
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
    vector<vector<int>> levelOrderOld(Node* root) {
        // 定义队列，保存树节点
        queue<Node*> que;

        // 定义变量保存结果
        vector<vector<int>> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，循环遍历
        while (!que.empty()) {
            // 获取队列的大小，即当前层的节点个数
            int size = que.size();
            // 定义变量保存每一层的结果，必须放在这儿，否则每一层有上一层的结果
            vector<int> vec;

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 获取队首元素
                Node* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 保存节点的值
                vec.push_back(node->val);

                // 遍历当前节点的子节点，如果子节点不为空，则入队
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i] != nullptr) {
                        que.push(node->children[i]);
                    }
                }
            }

            // 将当前层的结果保存到结果中
            res.push_back(vec);
        }

        return res;
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; // 定义变量保存结果
        if (!root) { // 根节点是空
            return res;
        }

        queue<Node*> que; // 定义队列保存节点
        que.push(root);

        while(!que.empty()) {
            int currentLevelSize = que.size(); // 求出当前层的节点数量
            vector<int> level; // 定义中间vector保存每一层的节点值
            for (int i = 0; i < currentLevelSize; i++) {
                Node* node = que.front(); // 取出节点
                que.pop();
                level.push_back(node->val); // 插入节点值
                for (Node* child : node->children) { // 遍历每个子节点
                    que.push(child);
                }
            }
            res.push_back(::move(level)); // 每一层的节点值插入结果
        }
        return res;
    }
};

int main(int argc, char** argv) {
    // 定义树节点
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution s;
    vector<vector<int>> res = s.levelOrder(root);

    cout << "level order: " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}