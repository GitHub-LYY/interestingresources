/*
** Author: Yangyang Liu
** Date: 2022-08-26
** Description: 剑指 Offer 07. 重建二叉树
** link: https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/
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
private:
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
        // 如果没有元素，直接返回
        if (preorderEnd == preorderBegin) {
            return nullptr;
        }

        // 根节点是前序遍历序列的第一个元素
        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);

        // 如果前序遍历有一个元素，则当前节点是根节点了
        if (preorderEnd - preorderBegin == 1) {
            return root;
        }

        // 根据根节点分割中序遍历序列
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootVal) {
                break; // 此时break的索引用来分割左右子树
            }
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex; // 左闭右开
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderBegin = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderEnd = preorderEnd;

        // 递归构建左右子树
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

int main(int argc, char** argv) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    Solution s;
    TreeNode* res = s.buildTree(preorder, inorder);

    cout << "root is:" << res->val << endl;

    return 0;
}