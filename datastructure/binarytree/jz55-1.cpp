/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 55 - I. 二叉树的深度
** link: https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/
** reference: 代码随想录
*/

#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点定义
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;

        int depth = 0;

        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        return depth;
    }
};

int main(int argc, char** argv) {
    // 定义树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    int res = s.maxDepth(root);

    cout << "max depth is :" << res << endl;

    return 0;
}