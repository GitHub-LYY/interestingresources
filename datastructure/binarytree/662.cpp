/*
** Author: Yangyang Liu
** Date: 2022-08-19
** Description: 662. 二叉树最大宽度
** link: https://leetcode.cn/problems/maximum-width-of-binary-tree/
** reference: 题解区，官方题解讨论区，作者，zjh1443
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
    int widthOfBinaryTree(TreeNode* root) {
        // 定义变量保存结果
        int res = 0;

        // 定义队列
        queue<pair<TreeNode*, unsigned long long>> que; // 第二个参数是节点的编号

        // 将根节点入队
        if (root != nullptr) {
            que.push({root, 1});
        }

        // 遍历队列
        while (!que.empty()) {
            int size = que.size(); // 每一层节点数量

            // 定义变量保存每一层的最左节点编号和最右节点编号
            unsigned long long start = que.front().second; // 刚进来while循环，第一个一定是start
            unsigned long long end = 0;

            for (int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();
                if (i == size - 1) {
                    // 最后一个节点，保存一下end，到最后一层遍历完了，就可以计算宽度了
                    end = node.second;
                }

                if (node.first->left != nullptr) {
                    que.push({node.first->left, node.second * 2 - 1});
                }

                if (node.first->right != nullptr) {
                    que.push({node.first->right, node.second * 2});
                }
            }

            // 每一层结束后计算一下结果，最后一层计算完后，结果出来了
            // res = max(res, end - start + 1); // long类型的不能使用max函数
            if (res < (end - start + 1)) {
                res = end - start + 1;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution s;
    int res = s.widthOfBinaryTree(root);

    cout << "width of binary tree: " << res << endl;

    return 0;
}