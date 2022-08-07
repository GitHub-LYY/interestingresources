/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 145. 二叉树的后序遍历
** link: https://leetcode.cn/problems/binary-tree-postorder-traversal/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

        traversal(cur->left, res); // 左节点
        traversal(cur->right, res); // 右节点
        res.push_back(cur->val); // 父节点
    }

    vector<int> postorderTraversalRecursion(TreeNode* root) {
        // 定义变量保存结果
        vector<int> res;

        traversal(root, res);

        return res;
    }

    vector<int> postorderTraversalIteration(TreeNode* root) {
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

        // 循环处理
        while (!st.empty()) {
            // 栈顶元素出栈
            TreeNode* cur = st.top();
            st.pop();

            // 根节点，先保存
            res.push_back(cur->val);

            // 前序遍历的中左右改为中右左
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
        }

        // 对中右左顺序的结果进行反转
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    // 定义树节点
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    //vector<int> res = s.postorderTraversalRecursion(root);
    vector<int> res = s.postorderTraversalIteration(root);

    cout << "res: " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}