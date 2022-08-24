/*
** Author: Yangyang Liu
** Date: 2022-08-24
** Description: 429. N 叉树的层序遍历
** link: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 第一种情况，要删除的节点为空
        if (root == nullptr) {
            return nullptr;
        }

        // 第二种情况，要删除的节点不为空
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr && root->right != nullptr) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            } else if (root->left != nullptr && root->right == nullptr) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            } else {
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right = new TreeNode(7);
    int key = 3;

    Solution s;
    TreeNode* res = s.deleteNode(root, key);

    cout << "res" << res->val << endl;
    
    return 0;
}