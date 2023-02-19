/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-02-19
** Description: 501. 二叉搜索树中的众数
** link: https://leetcode.cn/problems/find-mode-in-binary-search-tree/
** reference: 代码随想录
** 20230219，官方题解
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
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    vector<int> res;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }

        traversal(cur->left);

        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }

        if (count == maxCount) {
            res.push_back(cur->val);
        }

        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }

        pre = cur;

        traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};

class Solution {
public:
    vector<int> res; // 定义变量保存结果
    int count;
    int maxCount; // 定义变量保存最大数量
    int base; // 定义变量保存当前遍历的数
    void update(int x) {
        if (x == base) { // 当前遍历的节点值等于base了
            count++;
        } else {
            count = 1; // 数量置1
            base = x; // base置为x
        }
        
        if (count == maxCount) { // 满足
            res.emplace_back(base);
        }

        if (count > maxCount) { // 比当前最大的数量大
            maxCount = count; // 赋值为当前的数量
            res = vector<int> {base}; // 置空，再插入base
        }
    }
    void dfs(TreeNode* root) {
        if (!root) { // 当前节点是空
            return;
        }

        dfs(root->left);
        update(root->val);
        dfs(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution s;
    vector<int> res = s.findMode(root);

    for (int i = 0; i < res.size(); i++) {
        cout << "res: " << res[i] << endl;
    }

    return 0;
}