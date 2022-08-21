/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 106. 从中序与后序遍历序列构造二叉树
** link: https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderEnd == postorderBegin) {
            return nullptr;
        }

        // 后序遍历的最后一个节点是根节点
        int rootVal = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootVal);

        // 如果只有一个节点，则这个节点已经是根节点了
        if (postorderEnd - postorderBegin == 1) {
            return root;
        }

        // 在中序遍历数组求出左右子树分割点
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex <= inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootVal) {
                break;
            }
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd= inorderEnd;

        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderBegin = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main(int argc, char** argv) {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);

    cout << "root->val: " << root->val << endl;

    return 0;
}