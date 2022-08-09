/*
** Author: Yangyang Liu
** Date: 2022-08-08
** Description: 637. 二叉树的层平均值
** link: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
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
    vector<double> averageOfLevels(TreeNode* root) {
        // 定义队列，保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        vector<double> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，循环遍历
        while (!que.empty()) {
            // 获取队列的大小，即当前层的节点个数
            int size = que.size();
            // 定义变量保存当前层的节点值之和，不能使用int，使用double，平均值才为double
            double sumEachLevel = 0;

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 获取队头元素
                TreeNode* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 累加当前层的节点值之和
                sumEachLevel += node->val;

                // 如果左节点不为空，则入队
                if (node->left) {
                    que.push(node->left);
                }

                // 如果右节点不为空，则入队
                if (node->right) {
                    que.push(node->right);
                }
            }

            // 计算当前层的平均值
            double average = sumEachLevel / size;
            // 将当前层的平均值保存到结果中
            res.push_back(average);
        }

        return res;
    }
};

int main(int argc, char** argv) {
    // 创建树节点
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<double> res = s.averageOfLevels(root);

    cout << "average of levels:" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}