/*
** Author: Yangyang Liu
** Date: 2022-08-26
** Description: 剑指 Offer 32 - II. 从上到下打印二叉树 II
** link: https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;

        vector<vector<int>> res;

        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;

            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                vec.push_back(node->val);

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }

            res.push_back(vec);
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right= new TreeNode(20);
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