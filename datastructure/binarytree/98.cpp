/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-02-03
** Description: 98. 验证二叉搜索树
** link: https://leetcode.cn/problems/validate-binary-search-tree/
** reference: 代码随想录
** 20230203，官方题解不容易理解，自己理解后写的
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

class SolutionOld {
public:
    // 定义一个前驱节点用来比较和当前节点的大小
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        // 中序遍历
        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) {
            return false;
        }

        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

class Solution {
public:
    long pre = LONG_MIN; // 定义变量保存前驱节点的值
    bool isValidBST(TreeNode* root) {
        if (!root) { // 节点是空，一定是二叉搜索树
            return true;
        }

        bool left = isValidBST(root->left); // 保存左子树是否是二叉搜索树
        if (root->val <= pre) { // 不满足二叉搜索树的条件，则false
            return false;
        }
        pre = root->val; // 不要忘了修改前驱节点的值
        bool right = isValidBST(root->right); // 保存右子树是否是二叉搜索树

        return left && right; // 根节点已经在上边输出了，现在要输出的是左子树右子树是否是二叉搜索树
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    Solution s;
    bool res = s.isValidBST(root);

    cout << "res: " << res << endl;
    
    return 0;
}