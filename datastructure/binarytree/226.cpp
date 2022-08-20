/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 226. 翻转二叉树
** link: https://leetcode.cn/problems/invert-binary-tree/
** reference: 代码随想录
*/

#include <iostream>
#include <queue>

using namespace std;

// 定义二叉树节点
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
    TreeNode* invertTreeRecursion(TreeNode* root) {
        // 直接使用此函数递归

        // 递归终止条件
        if (root == nullptr) {
            return root;
        }

        swap(root->left, root->right);
        invertTreeRecursion(root->left); // 没有使用变量接收返回值？
        invertTreeRecursion(root->right);
        return root;
    }

    TreeNode* invertTreeIteration(TreeNode* root) {
        // 层序遍历，每个节点的左右子节点翻转

        queue<TreeNode*> que; // 定义队列保存树节点

        if (root != nullptr) {
            // 如果根节点不为空，放入队列

            que.push(root);
        }

        // 循环
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                // 翻转左右子节点
                swap(node->left, node->right);

                // 左右子节点入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 左右子节点入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    //TreeNode* res = s.invertTreeRecursion(root);
    TreeNode* res = s.invertTreeIteration(root);

    cout <<"res: " << res->val << endl;

    return 0;
}