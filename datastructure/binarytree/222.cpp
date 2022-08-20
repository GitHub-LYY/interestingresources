/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 222. 完全二叉树的节点个数
** link: https://leetcode.cn/problems/count-complete-tree-nodes/
** reference: 代码随想录
*/

#include <iostream>
#include <queue>

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
    int countNodesIteration(TreeNode* root) {
        // 二叉树的层序遍历

        queue<TreeNode*> que;

        int count = 0;

        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                count++;

                if (node->left != nullptr) {
                    que.push(node->left);
                }

                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return count;
    }

    int countNodes(TreeNode* root) {
        // 根据完全二叉树的特点

        // 如果根节点为空，则节点个数是0
        if (root == nullptr) {
            return 0;
        }

        // 定义变量保存左右节点
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // 定义变量保存左右子树的深度
        int leftDepth = 0;
        int rightDepth = 0;

        // 计算左子树的深度
        while (left != nullptr) {
            left = left->left;
            leftDepth++;
        }

        // 计算右子树的深度
        while (right != nullptr) {
            right = right->right; // 统计右的右是为了判断是不是慢二叉树，容易求节点个数
            rightDepth++;
        }

        if (leftDepth == rightDepth) {
            // 如果左右子树的深度相等，则是慢二叉树，节点个数是2^leftDepth - 1

            return (2 << leftDepth) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution s;
    //int res = s.countNodesIteration(root);
    int res = s.countNodes(root);

    cout << "res: " << res << endl;

    return 0;
}