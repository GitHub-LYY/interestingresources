/*
** Author: Yangyang Liu
** Date: 2022-08-08，2023-01-24
** Description: 107. 二叉树的层序遍历 II
** link: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
** reference: 代码随想录
** 20230124，官方题解
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
                // 获取队头元素
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

            // 每一层遍历完后，将结果保存到结果集中
            res.push_back(vec);
        }
        
        // 反转结果集
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    // 创建树节点
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.levelOrderBottom(root);

    cout << "level order bottom: " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}