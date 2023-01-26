/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-01-26
** Description: 112. 路径总和
** link: https://leetcode.cn/problems/path-sum/
** reference: 代码随想录
** 20230126，官方题解
*/

#include <iostream>

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
    bool traversal(TreeNode* cur, int count) {
        // 如果当前节点是叶子节点，且计数器为0，则有一条路径
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            return true;
        }
        
        // 如果当前节点是叶子节点，且计数器不为0，则这条路径不满足要求
        if (cur->left == nullptr && cur->right == nullptr) {
            return false;
        }

        // 如果当前节点不是叶子节点，则继续遍历
        if (cur->left != nullptr) {
            count = count - cur->left->val;
            if (traversal(cur->left, count)) {
                return true;
            }
            count = count + cur->left->val;
        }

        // 如果当前节点不是叶子节点，则继续遍历
        if (cur->right != nullptr) {
            count = count - cur->right->val;
            if (traversal(cur->right, count)) {
                return true;
            }
            count = count + cur->right->val;
        }

        // 如果上边不满足，则false
        return false;
    }

    bool hasPathSumOld(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return traversal(root, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) { // 当前节点是空，则一定是false
            return false;
        }

        if (!root->left && !root->right) { // 当前节点是叶子节点
            return targetSum == root->val;
        }

        // 当前节点不是叶子节点
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;

    Solution s;
    bool res = s.hasPathSum(root, targetSum);

    cout << "has path sum: " << res << endl;

    return 0;
}