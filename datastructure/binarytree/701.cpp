/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 701. 二叉搜索树中的插入操作
** link: https://leetcode.cn/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }

        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    int val = 5;

    Solution s;
    TreeNode* res = s.insertIntoBST(root, val);

    cout << "res: " << res->val << endl;
    
    return 0;
}