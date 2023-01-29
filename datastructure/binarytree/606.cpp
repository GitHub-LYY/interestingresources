/*
** Author: Yangyang Liu
** Date: 2023-01-29
** Description: 606. 根据二叉树创建字符串
** link: https://leetcode.cn/problems/construct-string-from-binary-tree/
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
    string tree2str(TreeNode* root) {
        if (!root) { // 当前节点是空的，则输出空字符串
            return "";
        }

        if (!root->left && !root->right) { // 第一种情况，当前节点左右孩子是空
            return to_string(root->val); // 左右孩子是()()，省略了
        }

        if (!root->right) { // 第二种情况，当前节点仅仅有左孩子
            return to_string(root->val) + '(' + tree2str(root->left) + ')'; // 右孩子是()，省略了
        }

        // 到这儿，是第三种情况和第四种情况
        // 第三种情况，当前节点有左右孩子
        // 第四种情况，当前节点仅仅有右孩子
        return to_string(root->val) + '(' + tree2str(root->left) + ")(" + tree2str(root->right) + ')'; // (1)(2)，()(2)
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);

    Solution s;
    string res = s.tree2str(root);

    cout << res << endl;

    return 0;
}