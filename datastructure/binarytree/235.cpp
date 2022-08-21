/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 235. 二叉搜索树的最近公共祖先
** link: https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if (left != nullptr) {
                return left;
            }
        }

        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (right != nullptr) {
                return right;
            }
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution s;
    TreeNode* res = s.lowestCommonAncestor(root, p, q);

    cout << "res: " << res->val << endl;
    
    return 0;
}