/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 28. 对称的二叉树
** link: https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/
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
private:
    bool traversal(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        } else {
            bool inside = traversal(left->right, right->left);
            bool outside = traversal(left->left, right->right);
            return inside && outside;
        }
    }
public:
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

    cout << "is symmetric?" << res << endl;
    
    return 0;
}