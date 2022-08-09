/*
** Author: Yangyang Liu
** Date: 2022-08-08
** Description: 199. 二叉树的右视图
** link: https://leetcode.cn/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
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

            // 遍历当前层的节点
            for (int i = 0; i < size; i++) {
                // 获取队头元素
                TreeNode* node = que.front();
                // 获取节点后，队头节点出队
                que.pop();

                // 如果是当前层的最后一个节点，则保存这个节点的值
                if (i == size - 1) {
                    res.push_back(node->val);
                }

                // 如果左节点不为空，则入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 如果右节点不为空，则入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution s;
    vector<int> res = s.rightSideView(root);

    cout << "right side view:" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}