/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 700. 二叉搜索树中的搜索
** link: https://leetcode.cn/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }

        return nullptr;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    Solution s;
    TreeNode* res = s.searchBST(root, 2);

    cout << "res: " << res->val << endl;
    
    return 0;
}