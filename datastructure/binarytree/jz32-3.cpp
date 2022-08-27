/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 32 - III. 从上到下打印二叉树 III
** link: https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
** reference: 题解区，自己之前做的题
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 定义队列保存树节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        vector<vector<int>> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        // 定义变量指定遍历的顺序是从左到右还是从右到左
        bool isFromLeftToRight = true;

        while (!que.empty()) {
            int size = que.size();

            // 这儿不用vector了，使用deque，从头从尾交替插入节点
            deque<int> dque;

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (isFromLeftToRight) {
                    dque.push_back(node->val);
                } else {
                    dque.push_front(node->val);
                }

                // 左节点不为空
                if (node->left) {
                    que.push(node->left);
                }

                // 右节点不为空
                if (node->right) {
                    que.push(node->right);
                }
            }

            res.push_back(vector<int>(dque.begin(), dque.end()));

            // 更新交替的变量
            isFromLeftToRight = !isFromLeftToRight;
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
    vector<vector<int>> res = s.levelOrder(root);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}