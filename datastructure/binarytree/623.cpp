/*
** Author: Yangyang Liu
** Date: 2023-01-26
** Description: 623. 在二叉树中增加一行
** link: https://leetcode.cn/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) { // 在第一层加一层节点
            return new TreeNode(val, root, nullptr); // root节点作为val节点的左节点，先紧着左边
        }

        vector<TreeNode*> curLevel(1, root); // 一个root节点

        for (int i = 1; i < depth - 1; i++) {
            vector<TreeNode*> tmp; // 定义临时变量保存一层节点
            for (auto node : curLevel) { // 遍历当前层
                if (node->left) { // 当前层的左节点不是空
                    tmp.emplace_back(node->left);
                }
                if (node->right) { // 当前层的右节点不是空
                    tmp.emplace_back(node->right);
                }
            }
            curLevel = tmp; // 下一层
        }

        for (auto node : curLevel) { // 当前层是要插入的上一层了
            node->left = new TreeNode(val, node->left, nullptr); // 插入左
            node->right = new TreeNode(val, nullptr, node->right); // 插入右，先执行右边的，再赋值到左边，容易理解
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    int val = 1;
    int depth = 2;

    Solution s;
    TreeNode* res = s.addOneRow(root, val, depth);

    cout << res->val << endl;

    return 0;
}