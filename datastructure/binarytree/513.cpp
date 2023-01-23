/*
** Author: Yangyang Liu
** Date: 2022-08-21,2023-01-23
** Description: 513. 找树左下角的值
** link: https://leetcode.cn/problems/find-bottom-left-tree-value/
** reference: 代码随想录
** 20230123，自己理解的写的
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
    int findBottomLeftValueOld(TreeNode* root) {
        // 定义队列保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        int res = 0;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 遍历队列
        while (!que.empty()) {
            // 获取队列大小
            int size = que.size();

            // 遍历队列
            for (int i = 0; i < size; i++) {
                // 获取队头元素
                TreeNode* node = que.front();
                que.pop();

                // 如果是第一个元素，则保存结果
                if (i == 0) {
                    res = node->val;
                }

                // 如果左子树不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右子树不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return res;
    }

    int findBottomLeftValue(TreeNode* root) {
        int res = 0; // 定义变量保存结果
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root);

        while (!que.empty()) {
            int size = que.size(); // 求出当前层节点数量
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front(); // 取出节点
                que.pop();
                if (i == 0) { // 是当前层第一个节点
                    res = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution s;
    int res = s.findBottomLeftValue(root);

    cout << "bottom left value: " << res << endl;

    return 0;
}