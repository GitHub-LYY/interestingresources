/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 113. 路径总和 II
** link: https://leetcode.cn/problems/path-sum-ii/
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
private:
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* cur, int count) {
        // 如果当前节点是叶子节点，且计数器为0，则有一条路径
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            // 满足，收割结果

            res.push_back(path);
            return;
        }

        if (cur->left != nullptr) {
            // 左节点不为空，递归左节点

            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }

        if (cur->right != nullptr) {
            // 右节点不为空，递归右节点

            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        if (root == nullptr) {
            return res;
        }
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;

    Solution s;
    vector<vector<int>> res = s.pathSum(root, targetSum);

    for (vector<int> vec : res) {
        for (int a : vec) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}