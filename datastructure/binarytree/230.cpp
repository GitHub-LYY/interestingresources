/*
** Author: Yangyang Liu
** Date: 2022-08-19，2023-02-03
** Description: 230. 二叉搜索树中第K小的元素
** link: https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
** reference: 20230203，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点定义
struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SolutionOld {
public:
    vector<int> res;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }

        traversal(cur->left);
        res.push_back(cur->val);
        traversal(cur->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        traversal(root);
        return res[k - 1];
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) { // 节点是空
            return;
        }

        inorder(root->left, res);
        res.emplace_back(root->val);
        inorder(root->right, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res; // 定义变量保存中序遍历的数组
        inorder(root, res); // 中序遍历
        return res[k - 1]; // 输出第k小的数
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;

    Solution s;
    int res = s.kthSmallest(root, k);

    cout << res << endl;

    return 0;
}