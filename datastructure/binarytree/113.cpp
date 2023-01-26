/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-01-26
** Description: 113. 路径总和 II
** link: https://leetcode.cn/problems/path-sum-ii/
** reference: 代码随想录
** 20230126，官方题解
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

class Solution {
public:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存路径的值
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) { // 如果当前遍历的节点是空的，则什么也不做
            return;
        }

        path.emplace_back(root->val); // 把当前遍历的节点插入路径
        sum -= root->val; // 把当前遍历节点的值从sum中去掉，遍历下一个节点了
        // 遍历下一个节点前，先判断一下是否是叶子节点且sum是0了
        if (!root->left && !root->right && sum == 0) {
            res.emplace_back(path); // 该收割结果了
        }
        dfs(root->left, sum); // 递归遍历左节点
        dfs(root->right, sum); // 递归遍历右节点
        path.pop_back(); // 不要忘了当前节点弹出路径
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
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