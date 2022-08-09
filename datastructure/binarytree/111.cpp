/*
** Author: Yangyang Liu
** Date: 2022-08-09
** Description: 111. 二叉树的最小深度
** link: https://leetcode.cn/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        // 队列定义，保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        int depth = 0;

        // 如果数节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，则循环
        while (!que.empty()) {
            // 定义变量记录每一层的节点数
            int size = que.size();

            // 每一个while都是一层，因此深度+1
            depth++;

            // 遍历每一层的节点
            for (int i = 0; i < size; i++) {
                // 取出队头节点
                TreeNode* node = que.front();
                // 队头节点出队
                que.pop();

                // 如果遍历到子节点，则返回结果
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }

                // 如果左子节点不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右子节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return depth;
    }
};

int main(int argc, char** argv) {
    // 创建二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    int depth = s.minDepth(root);

    cout << "min depth: " << depth << endl;
    
    return 0;
}