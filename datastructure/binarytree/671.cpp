/*
** Author: Yangyang Liu
** Date: 2023-01-23
** Description: 671. 二叉树中第二小的节点
** link: https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/
** reference: 自己理解写的
*/

#include <iostream>
#include <set>
#include <queue>

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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> ss; // 定义set保存树节点值
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root); // 根节点入队
        
        while (!que.empty()) {
            int size = que.size(); // 求出当前层的大小
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front(); // 取出节点
                que.pop();
                ss.insert(node->val); // 插入set
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        if (ss.size() == 1) { // 2,2,2
            return -1;
        }
        auto it = ++ss.begin();
        int res = *it;
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution s;
    int res = s.findSecondMinimumValue(root);

    cout << res << endl;

    return 0;
}