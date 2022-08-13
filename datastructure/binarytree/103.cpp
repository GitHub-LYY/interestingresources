/*
** Author: Yangyang Liu
** Date: 2022-08-13
** Description: 103. 二叉树的锯齿形层序遍历
** link: https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
** reference: 官方题解
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 定义队列保存节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        vector<vector<int>> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 定义指示器
        bool isFromLeft = true;

        // 队列不为空，则有节点没遍历完，继续循环
        while (!que.empty()) {
            // 定义deque变量保存每一层遍历的节点
            deque<int> deVec;

            // 定义变量保存每一层的节点个数
            int size = que.size();

            // 遍历每一层的节点
            for (int i = 0; i < size; i++) {
                // 取出队头元素
                TreeNode* node = que.front();
                que.pop();

                // 根据指示器判断是从左到右还是从右到左
                if (isFromLeft == true) {
                    deVec.push_back(node->val); // 从尾部插入
                } else {
                    deVec.push_front(node->val); // 从头部插入
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

            // 把deVec转换为vector类型插入res
            res.push_back(vector<int>(deVec.begin(), deVec.end()));

            // 指示器变换方向
            isFromLeft = !isFromLeft;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);

    cout << "zigzag level order:" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}