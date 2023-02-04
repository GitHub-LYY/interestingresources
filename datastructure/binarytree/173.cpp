/*
** Author: Yangyang Liu
** Date: 2023-02-04
** Description: 173. 二叉搜索树迭代器
** link: https://leetcode.cn/problems/binary-search-tree-iterator/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x), val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) { // 节点是空
            return;
        }

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderBST(TreeNode* root) {
        vector<int> res; // 定义变量保存中序遍历数组
        inorder(root, res);
        return res;
    }
    vector<int> arr; // 定义变量保存二叉搜索树中序遍历数组
    int index; // 定义变量遍历中序数组
public:
    BSTIterator(TreeNode* root) : index(0), arr(inorderBST(root)) {

    }

    int next() {
        return arr[index++];
    }

    bool hasNext() {
        return (index < arr.size());
    }
};

int main(int argc, char** argv) {
    return 0;
}