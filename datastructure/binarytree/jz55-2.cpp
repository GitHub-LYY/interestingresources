/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 55 - II. 平衡二叉树
** link: https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/
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
private:
    int getHeight(TreeNode* cur) {
        // 递归结束条件
        if (cur == nullptr) {
            return 0;
        }

        // 遍历左子树
        int leftHeight = getHeight(cur->left);
        if (leftHeight == -1) {
            return -1;
        }

        // 遍历右
        int rightHeight = getHeight(cur->right);
        if (rightHeight == -1) {
            return -1;
        }

        // 返回高度
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        // 根节点为空，一定是平衡的
        if (root == nullptr) {
            return true;
        }

        return getHeight(root) == -1 ? false : true;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    bool res = s.isBalanced(root);

    cout << "res :" << res << endl;
    
    return 0;
}