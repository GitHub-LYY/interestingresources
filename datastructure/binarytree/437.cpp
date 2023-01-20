/*
** Author: Yangyang Liu
** Date: 2023-01-19
** Description: 437. 路径总和 III
** link: https://leetcode.cn/problems/path-sum-iii/
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
    int rootSum(TreeNode* cur, long sum) {
        if (!cur) {
            return 0;
        }

        int res = 0;
        if (cur->val == sum) { // 从最下层的节点思考容易理解
            res++;
        }

        res += rootSum(cur->left, sum - cur->val);
        res += rootSum(cur->right, sum - cur->val);

        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) { // 根节点是空
            return 0;
        }

        int res = rootSum(root, targetSum);
        res += pathSum(root->left, targetSum); // 一开始写成rootSum了，错的
        res += pathSum(root->right, targetSum);

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2); // 定义节点一定顺序不能错了，例如这句和下句交换位置，报段错误
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);
    int targetSum = 8;

    Solution s;
    int res = s.pathSum(root, targetSum);

    cout << res << endl;

    return 0;
}