/*
** Author: Yangyang Liu
** Date: 2022-08-15，2023-02-16
** Description: 105. 从前序与中序遍历序列构造二叉树
** link: https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
** reference: 代码随想录
** 2023-02-16，官方题解
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

class Solution {
private:
    unordered_map<int, int> val2index; // 节点值-索引哈希表
public:
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) { // 不满足了
            return nullptr;
        }

        int preorder_root = preorder_left; // 从前序数组求出根节点的位置
        int inorder_root = val2index[preorder[preorder_root]]; // 利用哈希表求出中序数组根节点的位置
        int size_left_subtree = inorder_root - inorder_left; // 从中序根节点的位置求出左子树的节点数量

        TreeNode* root = new TreeNode(preorder[preorder_root]); // 求出根节点
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1); // 递归求左子树
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right); // 递归求右子树

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size(); // 求出树的节点个数

        for (int i = 0; i < inorder.size(); i++) { // 把中序遍历数组填充哈希表
            val2index[inorder[i]] = i;
        }
        
        return myBuildTree(preorder, inorder, 0, len - 1, 0, len - 1);
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