/*
** Author: Yangyang Liu
** Date: 2022-08-11
** Description: 124. 二叉树中的最大路径和
** link: https://leetcode.cn/problems/binary-tree-maximum-path-sum/
** reference: 官方题解
*/

#include <iostream> 

using namespace std;

// 二叉树节点的定义
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
    int maxSum = INT32_MIN;
    int maxGain(TreeNode* cur) {
        // 后序遍历，先求叶子节点的贡献度

        if (cur == nullptr) {
            // 递归结束条件，遍历到空节点了，则返回0

            return 0;
        }

        // 求左右子节点的贡献度
        int leftGain = max(maxGain(cur->left), 0);
        int rightGain = max(maxGain(cur->right), 0);

        // 求最大路径和，最大路径和 = 当前节点的值 + 左子节点的贡献度 + 右子节点的贡献度
        int newPathSum = cur->val + leftGain + rightGain;

        // 更新最大路径和
        maxSum = max(maxSum, newPathSum);

        // 返回当前节点的贡献度，当前节点的贡献度 = 当前节点的值 + 左右子节点中贡献度较大的那个
        return cur->val + max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "max path sum:" << sol.maxPathSum(root) << endl;

    return 0;
}