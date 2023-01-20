/*
** Author: Yangyang Liu
** Date: 2023-01-20
** Description: 563. 二叉树的坡度
** link: https://leetcode.cn/problems/binary-tree-tilt/
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
    int res = 0; // 定义变量保存结果，定义为全局变量
    int dfs(TreeNode* root) {
        if (!root) { // 节点是空的
            return 0; // 空节点的和是0
        }

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right); // 求出右子数的和

        res += abs(leftSum - rightSum); // 这是副产品，在递归函数中顺便求出了结果坡度

        return (leftSum + rightSum + root->val); // 这是求出当前数的和
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s;
    int res = s.findTilt(root);

    cout << res << endl;
    
    return 0;
}