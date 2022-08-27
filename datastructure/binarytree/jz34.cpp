/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 34. 二叉树中和为某一值的路径
** link: https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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
        //path.push_back(cur->val); // 不能写在这儿，这不能回溯，答案错误

        // 如果是叶子节点，且此时的count为0，则收集路径
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            res.push_back(path);
            return;
        }

        // 保证进入递归的节点一定不为空
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }

        if (cur->right) {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        res.clear();
        path.clear();
        if (root == nullptr) {
            return res;
        }
        path.push_back(root->val); // 这儿先把根节点插入
        traversal(root, target - root->val);
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int target = 22;

    Solution s;
    vector<vector<int>> res = s.pathSum(root, target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}