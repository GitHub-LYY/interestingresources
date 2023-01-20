/*
** Author: Yangyang Liu
** Date: 2022-08-21,2023-01-20
** Description: 617. 合并二叉树
** link: https://leetcode.cn/problems/merge-two-binary-trees/
** reference: 代码随想录
** 20230120，官方题解
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
    TreeNode* mergeTreesOld(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }

        if (root2 == nullptr) {
            return root1;
        }

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) { // 1节点是空，输出2节点
            return root2;
        }
        if (root2 == nullptr) { // 2节点是空，输出1节点
            return root1;
        }

        TreeNode* merge = new TreeNode(root1->val + root2->val); // 合并两个不是空的节点
        merge->left = mergeTrees(root1->left, root2->left); // 左孩子
        merge->right = mergeTrees(root1->right, root2->right); // 右孩子

        return merge;
    }
};

int main(int argc, char** argv) {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);

    Solution s;
    TreeNode* root = s.mergeTrees(root1, root2);

    cout << "root->val = " << root->val << endl;

    return 0;
}