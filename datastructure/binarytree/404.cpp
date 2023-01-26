/*
** Author: Yangyang Liu
** Date: 2022-08-20，2023-01-26
** Description: 404. 左叶子之和
** link: https://leetcode.cn/problems/sum-of-left-leaves/
** reference: 代码随想录
** 20230126，官方题解，层序遍历
*/

#include <iostream>

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

class SolutionOld {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 递归结束条件
        if (root == nullptr) {
            return 0;
        }

        // 后序遍历
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        // 单层递归逻辑
        int midValue = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            midValue = root->left->val;
        }

        int sum = midValue + leftValue + rightValue;

        return sum;
    }
};

class Solution {
public:
    bool isLeaveNode(TreeNode* node) {
        return !node->left && !node->right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) { // 根节点是空，则左叶子节点的和一定是0
            return 0;
        }

        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root); // 根节点入队
        int res = 0; // 定义变量保存结果

        while (!que.empty()) {
            TreeNode* node = que.front(); // 取出队列队首
            que.pop();
            if (node->left) { // 左节点不是空
                if (isLeaveNode(node->left)) { // 左节点是叶子节点，收割
                    res += node->left->val;
                } else { // 左节点不是叶子节点，插入队列
                    que.push(node->left);
                }
            }
            if (node->right) { // 右节点不是空
                if (!isLeaveNode(node->right)) { // 右节点不是叶子节点才插入队列
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
    int res = s.sumOfLeftLeaves(root);

    cout << "left leaves sum: " << res << endl;
    
    return 0;
}