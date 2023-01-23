/*
** Author: Yangyang Liu
** Date: 2022-08-08,2023-01-23
** Description: 515. 在每个树行中找最大值
** link: https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
** reference: 代码随想录
** 20230123，自己理解写的
*/

#include <iostream>
#include <vector>
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
    vector<int> largestValuesOld(TreeNode* root) {
        // 定义队列，保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        vector<int> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 队列不为空，循环遍历
        while (!que.empty()) {
            // 获取队列的大小，即当前层的节点个数
            int size = que.size();
            // 定义变量保存每层的最大值
            int maxValue = INT32_MIN;

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 获取队头元素
                TreeNode* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 保存每层的最大值
                maxValue = maxValue > node->val ? maxValue : node->val;

                // 如果左节点不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

            // 将每层的最大值保存到结果中
            res.push_back(maxValue);
        }

        return res;
    }

    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> res; // 定义变量保存结果
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root);

        while (!que.empty()) {
            int size = que.size(); // 求出每一层节点数量
            int maxValue = INT_MIN; // 定义变量保存每一层最大值
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front(); // 取出节点
                que.pop();
                if (node->val > maxValue) { // 求出最大值
                    maxValue = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(maxValue); // 插入每一层最大值
        }

        return res;
    }
};

int main(int argc, char** argv) {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // 创建对象
    Solution s;
    vector<int> res = s.largestValues(root);

    cout << "largest values:" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}