/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 530. 二叉搜索树的最小绝对差
** link: https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
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
    // 定义一个前驱节点用来比较和当前节点的大小
    TreeNode* pre = nullptr;
    int minDiff = INT_MAX;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }

        traversal(cur->left);

        if (pre != nullptr) {
            minDiff = min(minDiff, cur->val - pre->val);
        }

        pre = cur;

        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minDiff;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);

    Solution s;
    int res = s.getMinimumDifference(root);

    cout << "res: " << res << endl;

    return 0;
}