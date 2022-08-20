/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 404. 左叶子之和
** link: https://leetcode.cn/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        // 递归结束条件
        if (root == nullptr) {
            return 0;
        }

        // 后序遍历
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        // 单层递归逻辑
        int midValue = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            midValue = root->left->val;
        }

        int sum = midValue + leftValue + rightValue;

        return sum;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    int res = s.sumOfLeftLeaves(root);

    cout << "left leaves sum: " << res << endl;
    
    return 0;
}