/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 257. 二叉树的所有路径
** link: https://leetcode.cn/problems/binary-tree-paths/
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
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        // 一开始把当前节点传入path
        path.push_back(cur->val);

        // 递归结束条件
        if (cur->left == nullptr && cur->right == nullptr) {
            // 当前节点是叶子节点，把path加入res

            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                // 最后一个先不在循环中加入，因为后边有箭头

                sPath += to_string(path[i]) + "->";
            }
            sPath += to_string(path[path.size() - 1]); // 把最后一个加入

            res.push_back(sPath); // 把path加入res
        }

        // 单层递归逻辑
        if (cur->left != nullptr) {
            // 空节点不进入递归

            traversal(cur->left, path, res);
            path.pop_back(); // 回溯
        }

        if (cur->right != nullptr) {
            traversal(cur->right, path, res);
            path.pop_back(); // 回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<string> res = s.binaryTreePaths(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}