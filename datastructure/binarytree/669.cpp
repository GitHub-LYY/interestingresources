/*
** Author: Yangyang Liu
** Date: 2023-02-07
** Description: 669. 修剪二叉搜索树
** link: https://leetcode.cn/problems/trim-a-binary-search-tree/
** reference: 题解区，官方题解
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) { // 节点是空，则输出空
            return nullptr;
        }

        if (root->val < low) { // 当前节点及左子树全部小于low，这是二叉搜索树
            return trimBST(root->right, low, high); // 直接递归右子树
        } else if (root->val > high) { // 当前节点及右子树全部大于high
            return trimBST(root->left, low, high); // 直接递归左子树
        } else { // 当前节点大于low，小于high，继续递归左右子树
            root->left = trimBST(root->left, low, high); // 当前节点的left接收
            root->right = trimBST(root->right, low, high); // 当前节点的right接收
            return root;
        }
    } 
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    int low = 1;
    int high = 2;

    Solution s;
    TreeNode* res = s.trimBST(root, low, high);

    cout << res->val << endl;
    
    return 0;
}