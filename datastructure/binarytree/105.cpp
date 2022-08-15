/*
** Author: Yangyang Liu
** Date: 2022-08-15
** Description: 105. 从前序与中序遍历序列构造二叉树
** link: https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

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
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
        if (preorderBegin == preorderEnd) {
            // 递归终止条件

            return nullptr;
        }

        // 前序遍历的第一个元素是根节点
        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);

        // 如果只有一个元素，则它便是根节点了
        if (preorderEnd - preorderBegin == 1) {
            return root;
        }

        // 走到这儿，则不只有一个节点了

        // 在中序数组中找到根节点的位置作为分割点
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorder.size(); delimiterIndex++) {
            // 遍历中序数组

            if (inorder[delimiterIndex] == rootVal) {
                // 找到了根节点

                break; // 这儿的索引便是分割点了
            }
        }

        // 中序数组使用索引分为左右两个数组
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 前序数组使用索引分为左右两个数组
        int leftPreorderBegin = preorderBegin + 1; // 第一个是头节点，要剔除
        int leftPreorderEnd = preorderBegin + delimiterIndex + 1 - inorderBegin;
        int rightPreorderBegin = preorderBegin + delimiterIndex + 1 - inorderBegin;
        int rightPreorderEnd = preorderEnd;

        // 递归构造左右子树
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }
};

int main(int argc, char** argv) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

    cout << "root value:" << root->val << endl;

    return 0;
}