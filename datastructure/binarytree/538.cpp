/*
** Author: Yangyang Liu
** Date: 2023-02-03
** Description: 538. 把二叉搜索树转换为累加树
** link: https://leetcode.cn/problems/convert-bst-to-greater-tree/
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
public:
    int sum = 0; // 定义变量保存当前节点之前节点的和
    TreeNode* convertBST(TreeNode* root) {
        if (root) { // 节点不是空
            convertBST(root->right); // 先遍历右孩子，反中序遍历
            sum += root->val; // 累计当前节点之前节点的和
            root->val = sum; // 和赋值到当前节点上
            convertBST(root->left); // 最后遍历左孩子
        }
        return root; // 最后输出根节点
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution s;
    TreeNode* res = s.convertBST(root);

    cout << res->val << endl;

    return 0;
}