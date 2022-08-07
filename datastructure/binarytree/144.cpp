/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 144. 二叉树的前序遍历
** link: https://leetcode.cn/problems/binary-tree-preorder-traversal/
** reference: 代码随想录
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

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& res) {
        // 递归终止条件
        if (cur == nullptr) {
            return;
        }

        res.push_back(cur->val); // 父节点
        traversal(cur->left, res); // 左节点
        traversal(cur->right, res); // 右节点
    }

    vector<int> preorderTraversalRecursion(TreeNode* root) {
        // 定义变量保存结果
        vector<int> res;

        traversal(root, res);

        return res;
    }

    vector<int> preorderTraversalIteration(TreeNode* root) {
        // 定义变量保存结果
        vector<int> res;

        // 定义栈，保存树节点
        stack<TreeNode*> st;

        // 异常情况
        if (root == nullptr) {
            return res;
        }

        // 处理完异常情况，根节点入栈
        st.push(root);

        // 栈不为空，循环处理
        while (!st.empty()) {
            // 考虑三个节点的树，栈顶一开始是根节点，出栈
            TreeNode* cur = st.top();
            st.pop();

            // 前序遍历先保存根节点
            res.push_back(cur->val);

            // 栈是先进后出，所以先右节点入栈，再左节点入栈
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    // 创建树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 前序遍历
    Solution s;
    //vector<int> res = s.preorderTraversalRecursion(root);
    vector<int> res = s.preorderTraversalIteration(root);

    // 打印结果
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}