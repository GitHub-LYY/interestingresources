/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-02-18
** Description: 106. 从中序与后序遍历序列构造二叉树
** link: https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
** reference: 代码随想录
** 20230218，自己理解了105题的官方题解后，自己写的
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

class SolutionOld {
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

class Solution {
private:
    unordered_map<int, int> val2index; // 节点值-位置索引哈希表
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right) { // 越界了
            return nullptr;
        }

        int postorder_root = postorder_right; // 从后序数组求出根节点的位置
        int inorder_root = val2index[postorder[postorder_root]]; // 从中序数组求出根节点位置
        int size_right_subtree = inorder_right - inorder_root; // 求出中序的右子树的节点数量，不能求左子树节点数量

        TreeNode* root = new TreeNode(postorder[postorder_root]); // 求出根节点
        root->left = helper(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_right - size_right_subtree - 1);
        root->right = helper(inorder, postorder, inorder_root + 1, inorder_right, postorder_right - size_right_subtree, postorder_right - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) { // 遍历中序数组，填充哈希表
            val2index[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
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