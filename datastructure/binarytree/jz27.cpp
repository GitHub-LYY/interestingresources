/*
** Author: Yangyang Liu
** Date: 2022-08-26
** Description: 剑指 Offer 27. 二叉树的镜像
** link: https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
** reference: 代码随想录，二叉树的翻转
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
    TreeNode* mirrorTree(TreeNode* root) {
        // 前序遍历，每一个节点做翻转操作

        // 递归结束条件
        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    TreeNode* res = s.mirrorTree(root);

    cout << "res:" << res->val << endl;

    return 0;
}