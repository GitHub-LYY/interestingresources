/*
** Author: Yangyang Liu
** Date: 2023-02-03
** Description: 783. 二叉搜索树节点最小距离
** link: https://leetcode.cn/problems/minimum-distance-between-bst-nodes/
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
    /*
     * 作用：中序遍历二叉搜索树
     * root：节点
     * res：结果，最小的距离
     * pre：每个节点的前驱节点的值，遍历每个节点的时候计算最小的距离
     */
    void dfs(TreeNode* root, int& res, int& pre) {
        if (!root) { // 当前节点是空的
            return;
        }

        dfs(root->left, res, pre); // 遍历左孩子
        if (pre == -1) { // 当前节点是第一个节点    
            pre = root->val; // 修改前驱节点的值
        } else { // 当前节点不是第一个节点
            res = min(res, root->val - pre); // 不断计算最小距离，一定在相邻节点中产生
            pre = root->val; // 不要忘了修改前驱节点的值
        }
        dfs(root->right, res, pre); // 遍历右孩子
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX; // 定义变量保存结果
        int pre = -1; // 定义变量保存前驱节点的值，第一个节点的前驱节点的值是-1
        dfs(root, res, pre); // 中序遍历二叉搜索树
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);

    Solution s;
    int res = s.minDiffInBST(root);

    cout << res << endl;
    
    return 0;
}