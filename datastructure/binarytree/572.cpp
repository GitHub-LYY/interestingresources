/*
** Author: Yangyang Liu
** Date: 2023-01-20
** Description: 572. 另一棵树的子树
** link: https://leetcode.cn/problems/subtree-of-another-tree/
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
    bool check(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) {
            return true;
        }
        if ((node1 && !node2) || (!node1 && node2) || (node1->val != node2->val)) {
            return false;
        }

        return check(node1->left, node2->left) && check(node1->right, node2->right);
    }
    bool dfs(TreeNode* node1, TreeNode* node2) {
        if (!node1) {
            return false;
        }
        return check(node1, node2) || dfs(node1->left, node2) || dfs(node1->right, node2);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution s;
    bool res = s.isSubtree(root, subRoot);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}