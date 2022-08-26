/*
** Author: Yangyang Liu
** Date: 2022-08-26
** Description: 剑指 Offer 32 - I. 从上到下打印二叉树
** link: https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
** reference: 代码随想录
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
    vector<int> levelOrder(TreeNode* root) {
        // 层序遍历

        // 定义队列保存节点
        queue<TreeNode*> que;

        // 定义变量保存结果
        vector<int> res;

        // 如果根节点不为空，则入队
        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                res.push_back(node->val);

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
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<int> res = s.levelOrder(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}