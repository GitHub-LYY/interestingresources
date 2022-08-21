/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 513. 找树左下角的值
** link: https://leetcode.cn/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
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