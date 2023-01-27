/*
** Author: Yangyang Liu
** Date: 2023-01-27
** Description: 655. 输出二叉树
** link: https://leetcode.cn/problems/print-binary-tree/
** reference: 官方题解，层序遍历
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

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
    int getHeight(TreeNode* root) {
        int depth = 0; // 定义变量保存深度
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root); // 根节点入队

        while (!que.empty()) {
            int size = que.size(); // 当前层的节点数量
            depth++; // 深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front(); // 取出队首节点
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        depth--; // height是depth-1

        return depth; // 此时的depth是height了
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int m = height + 1; // 矩阵的行数
        int n = (1 << (height + 1)) - 1; // 矩阵的列数
        vector<vector<string>> res(m, vector<string>(n, "")); // 定义m行n列的矩阵保存树
        queue<tuple<TreeNode*, int, int>> que; // 定义队列保存树节点
        que.push({root, 0, (n - 1) / 2}); // 插入根节点

        while (!que.empty()) {
            auto tp = que.front(); // 取出队首节点
            que.pop();
            
            int row = get<1>(tp); // 当前遍历节点的横坐标
            int col = get<2>(tp); // 当前遍历节点的纵坐标

            res[row][col] = to_string(get<0>(tp)->val); // 当前遍历节点的值放入矩阵

            if (get<0>(tp)->left) { // 记忆这个放入矩阵的位置
                que.push({get<0>(tp)->left, row + 1, col - (1 << (height - row -1))}); 
            }
            if (get<0>(tp)->right) {
                que.push({get<0>(tp)->right, row + 1, col + (1 << (height - row - 1))}); 
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution s;
    vector<vector<string>> res = s.printTree(root);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}