/*
** Author: Yangyang Liu
** Date: 2022-08-13
** Description: 236. 二叉树的最近公共祖先
** link: https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
** reference: 代码随想录
*/

#include <iostream>

using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        // 递归返回值
        if (cur == p || cur == q || cur == nullptr) {
            return cur;
        }

        // 递归左子树
        TreeNode* left = traversal(cur->left, p, q);

        // 递归右子树
        TreeNode* right = traversal(cur->right, p, q);

        // 后序遍历的中节点的处理逻辑
        if (left != nullptr && right != nullptr) {
            return cur;
        }

        if (left != nullptr && right == nullptr) {
            return left;
        } else if (left == nullptr && right != nullptr) {
            return right;
        } else {
            return nullptr;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = traversal(root, p, q);

        return node;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution s;
    TreeNode* res = s.lowestCommonAncestor(root, p, q);

    cout << "lowest common ancestor:" << res->val << endl;
    return 0;
}