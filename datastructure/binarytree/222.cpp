/*
** Author: Yangyang Liu
** Date: 2022-08-20, 2023-01-18
** Description: 222. 完全二叉树的节点个数
** link: https://leetcode.cn/problems/count-complete-tree-nodes/
** reference: 代码随想录
** 20230118，参考官方题解
*/

#include <iostream>
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
    int countNodesIteration(TreeNode* root) {
        // 二叉树的层序遍历

        queue<TreeNode*> que;

        int count = 0;

        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                count++;

                if (node->left != nullptr) {
                    que.push(node->left);
                }

                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return count;
    }

    int countNodesRecursive(TreeNode* root) {
        // 根据完全二叉树的特点

        // 如果根节点为空，则节点个数是0
        if (root == nullptr) {
            return 0;
        }

        // 定义变量保存左右节点
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // 定义变量保存左右子树的深度
        int leftDepth = 0;
        int rightDepth = 0;

        // 计算左子树的深度
        while (left != nullptr) {
            left = left->left;
            leftDepth++;
        }

        // 计算右子树的深度
        while (right != nullptr) {
            right = right->right; // 统计右的右是为了判断是不是慢二叉树，容易求节点个数
            rightDepth++;
        }

        if (leftDepth == rightDepth) {
            // 如果左右子树的深度相等，则是慢二叉树，节点个数是2^leftDepth - 1

            return (2 << leftDepth) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    bool exist(TreeNode* root, int level, int mid) {
        int bits = 1 << (level - 1); // 位运算要用
        TreeNode* node = root; // 哨兵节点

        while (node != nullptr && bits > 0) {
            if (!(bits & mid)) { // 当前位是0，表示要往左走
                node = node->left;
            } else { // 当前位是1，表示要往右走
                node = node->right;
            }
            bits >>= 1; // 一开始忘了，错的，每次bits要往右走一位
        }

        return node != nullptr; // 不是空，则意味着存在，是true
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) { // 空的树，节点个数是0
            return 0;
        }

        int level = 0; // 定义变量保存节点的深度，根节点是第0层
        TreeNode* node = root; // 定义哨兵节点遍历树
        while (node->left) { // 先一路走到叶子节点最左边节点方便求出个数的范围
            level++; // 每遍历一层，层数加一
            node = node->left; // 遍历
        }

        int low = 1 << level; // 相当于是2的level次方，这是节点个数范围的最小值
        int high = (1 << (level + 1)) - 1; // 相当于是2的level+1次方减去一，这是节点个数范围的最大值
        while (low < high) {
            int mid = (high - low + 1) / 2 + low; // 求出叶子节点层中间节点，再判断是否存在，方便缩小范围
            if (exist(root, level, mid)) { // 中间节点存在，则左边界往右走
                low = mid; 
            } else { // 中间节点不存在，则右边界往左右
                high = mid - 1; 
            }
        }

        return low; // 此时low=high
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution s;
    //int res = s.countNodesIteration(root);
    int res = s.countNodes(root);

    cout << "res: " << res << endl;

    return 0;
}