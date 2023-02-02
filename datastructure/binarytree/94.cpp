/*
** Author: Yangyang Liu
** Date: 2022-08-07，2023-02-02
** Description: 94. 二叉树的中序遍历
** link: https://leetcode.cn/problems/binary-tree-inorder-traversal/
** reference: 20230202，官方题解
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 树节点定义
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
    void traversal(TreeNode* cur, vector<int>& res) {
        // 递归终止条件
        if (cur == nullptr) {
            return;
        }

        traversal(cur->left, res); // 左节点
        res.push_back(cur->val); // 父节点
        traversal(cur->right, res); // 右节点
    }

    vector<int> inorderTraversalRecursion(TreeNode* root) {
        // 定义变量保存结果
        vector<int> res;

        traversal(root, res);

        return res;
    }

    vector<int> inorderTraversalIteration(TreeNode* root) {
        // 定义变量保存结果
        vector<int> res;

        // 定义栈，保存树节点
        stack<TreeNode*> st;

        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) { // 指针来访问节点，访问到最底层
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

        return res;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; // 定义变量保存结果
        inorder(root, res);
        return res;
    }
};

int main(int argc, char** argv) {
    // 定义树节点
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    //vector<int> res = s.inorderTraversalRecursion(root);
    vector<int> res = s.inorderTraversalIteration(root);

    cout << "res: " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}