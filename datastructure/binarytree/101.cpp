/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 101. 对称二叉树
** link: https://leetcode.cn/problems/symmetric-tree/
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
    bool traversal(TreeNode* left, TreeNode* right) {
        // 左空右不空，左不空右空，左不空右不空值不相等，一定不对称
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            // 左右都不为空

            return false;
        }

        // 来到这儿，则左右不为空，值相等，接下来判断内测外侧是否相等

        bool outside = traversal(left->left, right->right);
        bool inside = traversal(left->right, right->left);
        bool isSame = outside && inside;

        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return traversal(root->left, root->right);
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    bool res = s.isSymmetric(root);

    cout << "is symmetric: " << res << endl;

    return 0;
}