/*
** Author: Yangyang Liu
** Date: 2022-08-24，2023-02-07
** Description: 429. N 叉树的层序遍历
** link: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
** reference: 代码随想录
** 20230207，官方题解
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

class SolutionOld {
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { // 当前节点是空，则输出空
            return nullptr;
        }

        if (root->val < key) { // 当前节点的值小于key，则删除右子树
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->val > key) { // 当前节点的值大于key，则删除左子树
            root->left = deleteNode(root->left, key);
            return root;
        }

        if (root->val == key) { // 当前节点的值等于key
            if (!root->left && !root->right) { // 当前节点是叶子节点，直接删除
                return nullptr;
            }
            if (!root->right) { // 当前节点仅有左子树
                return root->left;
            }
            if (!root->left) { // 当前节点仅有右子树
                return root->right;
            }
            // 来到这，则有左右子树
            TreeNode* successor = root->right; // 求出当前节点右子树中最左边的节点
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val); // 输出删除successor后的右子树
            successor->right = root->right; // 把当前节点的右子树赋值到successor
            successor->left = root->left; // 把当前节点的左子树赋值到successor
            return successor; // 输出这个节点
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