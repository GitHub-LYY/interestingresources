/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 129. 求根节点到叶节点数字之和
** link: https://leetcode.cn/problems/sum-root-to-leaf-numbers/
** reference: 题解区，官方题解
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
    int traversal(TreeNode* cur, int prevSum) {
        // 递归结束条件
        if (cur == nullptr) {
            return 0;
        }

        // 计算当前路径的值
        int sum = prevSum * 10 + cur->val;

        // 判断是叶子节点还是非叶子节点
        if (cur->left == nullptr && cur->right == nullptr) {
            // 叶子节点

            return sum;
        } else {
            // 非叶子节点

            return traversal(cur->left, sum) + traversal(cur->right, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        // 定义变量保存结果
        int res = 0;

        // 递归遍历
        res = traversal(root, 0);

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s;
    int res = s.sumNumbers(root);

    cout << "res = " << res << endl;
    
    return 0;
}