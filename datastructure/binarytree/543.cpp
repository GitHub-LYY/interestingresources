/*
** Author: Yangyang Liu
** Date: 2023-01-20
** Description: 543. 二叉树的直径
** link: https://leetcode.cn/problems/diameter-of-binary-tree/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int res;
public:
    int depth(TreeNode* root) {
        if (root == nullptr) { // 遍历到空节点了，深度是0
            return 0;
        }

        int leftDepth = depth(root->left); // 递归左子树
        int rightDepth = depth(root->right); // 递归右子树

        res = max(res, leftDepth + rightDepth + 1); // 副产品，求出节点数量

        return max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        depth(root);
        return res - 1;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    Solution s;
    int res = s.diameterOfBinaryTree(root);

    cout << res << endl;

    return 0;
}