/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 110. 平衡二叉树
** link: https://leetcode.cn/problems/balanced-binary-tree/
** reference: 代码随想录
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
    int getHeight(TreeNode* root) {
        // 递归结束条件
        if (root == nullptr) {
            // 空节点的高度是0

            return 0;
        }

        // 后序遍历

        int leftHeight = getHeight(root->left); // 左子树的高度
        if (leftHeight == -1) {
            // 如果左子树不是平衡二叉树，则直接返回-1
            return -1;
        }

        int rightHeight = getHeight(root->right); // 右子树的高度
        if (rightHeight == -1) {
            // 如果右子树不是平衡二叉树，则直接返回-1
            return -1;
        }

        // 单层递归逻辑
        int heightDiff = 0;
        if (abs(leftHeight - rightHeight) > 1) {
            heightDiff = -1;
        } else {
            heightDiff = max(leftHeight, rightHeight) + 1;
        }

        return heightDiff;
    }

    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        return height == -1 ? false : true;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    bool res = s.isBalanced(root);

    cout << "is balanced: " << res << endl;
    
    return 0;
}