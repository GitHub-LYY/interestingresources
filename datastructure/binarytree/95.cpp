/*
** Author: Yangyang Liu
** Date: 2023-02-08
** Description: 95. 不同的二叉搜索树 II
** link: https://leetcode.cn/problems/unique-binary-search-trees-ii/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

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
    vector<TreeNode*> generateTrees(int start, int end) { // 函数重载
        if (start > end) { // 不满足了
            return {nullptr};
        }

        vector<TreeNode*> allTrees; // 定义变量保存结果

        for (int i = start; i <= end; i++) { // i是每一个根节点
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1); // 求出i节点的左子树们
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end); // 求出i节点的右子树们

            for (auto & left : leftTrees) { // 遍历左子树们
                for (auto &right : rightTrees) { // 遍历右子树们
                    TreeNode* root = new TreeNode(i); // i是根节点的值
                    root->left = left; // 把左子树插在根节点
                    root->right = right; // 把右子树插在根节点
                    allTrees.emplace_back(root); // 插入结果
                }
            }
        }

        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) { // n是0
            return {nullptr};
        } else { // n不是0
            return generateTrees(1, n);
        }
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    vector<TreeNode*> res = s.generateTrees(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i]->val << " ";
    }

    return 0;
}