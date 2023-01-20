/*
** Author: Yangyang Liu
** Date: 2023-01-20
** Description: 687. 最长同值路径
** link: https://leetcode.cn/problems/longest-univalue-path/
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
private:
    int res;
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) { // 节点是空，则路径是0
            return 0;
        }

        int left = dfs(root->left); // 求出左子树的最大路径
        int right = dfs(root->right); // 求出右子树的最大路径

        int left1 = 0; // 根节点是否相等来求最大路径
        int right1 = 0;
        if (root->left && root->val == root->left->val) { // 根节点和左节点值相等
            left1 = left + 1;
        }
        if (root->right && root->val == root->right->val) { // 根节点和右节点值相等
            right1 = right + 1;
        }

        res = max(res, left1 + right1);

        return max(left1, right1);
    }
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(5);

    Solution s;
    int res = s.longestUnivaluePath(root); 

    cout << res << endl;

    return 0;
}