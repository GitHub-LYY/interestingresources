/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 98. 验证二叉搜索树
** link: https://leetcode.cn/problems/validate-binary-search-tree/
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