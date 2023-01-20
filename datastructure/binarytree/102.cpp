/*
** Author: Yangyang Liu
** Date: 2022-08-08,2023-01-20
** Description: 102. 二叉树的层序遍历
** link: https://leetcode.cn/problems/binary-tree-level-order-traversal/
** reference: 代码随想录
** 20230120，官方题解
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderOld(TreeNode* root) {
        // 定义队列，保存树节点
        queue<TreeNode*> que;

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
                TreeNode* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 保存节点的值
                vec.push_back(node->val);

                // 如果左节点不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

            // 将当前层的结果保存到结果中
            res.push_back(vec);
        }

        return res;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // 定义变量保存结果
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> que; // 定义队列保存每一层的树节点
        que.push(root); // 执行到这儿，则意味着root不是空的，能插入

        while (!que.empty()) {
            int currentLevelSize = que.size(); // 求出当前层的节点的数量用来遍历
            res.push_back(vector<int> ()); // 直接先插入一个空的vector用来保存本层节点的值
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode* node = que.front(); // 取出节点
                que.pop();
                res.back().push_back(node->val); // 当前节点值插入vector中
                if (node->left) { // 下一层的节点
                    que.push(node->left);
                }
                if (node->right) { // 下一层的节点
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    // 定义树节点
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.levelOrder(root);

    cout <<"level order:" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}