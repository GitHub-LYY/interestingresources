/*
** Author: Yangyang Liu
** Date: 2022-08-08
** Description: 104. 二叉树的最大深度
** link: https://leetcode.cn/problems/maximum-depth-of-binary-tree/
** reference: 代码随想录
*/

#include <iostream>
#include <queue>

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
    int maxDepth(TreeNode* root) {
        // 定义队列，保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        int depth = 0;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，循环遍历
        while (!que.empty()) {
            // 获取队列的大小，即当前层的节点个数
            int size = que.size();
            // 每一层树的深度加一
            depth++;

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 获取队首元素
                TreeNode* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 如果左节点不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return depth;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    int depth = s.maxDepth(root);

    cout << "max depth: " << depth << endl;

    return 0;
}