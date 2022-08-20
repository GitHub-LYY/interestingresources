/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 114. 二叉树展开为链表
** link: https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
** reference: 题解区，搜索，二叉树展开为链表 | 图解树的遍历 | 代码简洁易懂 【C++/Java版本】，作者，林小鹿
*/

#include <iostream>
#include <vector>

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
    void traversal(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) {
            return;
        }

        res.push_back(cur->val);
        traversal(cur->left, res);
        traversal(cur->right, res);
    }

    TreeNode* toList(vector<int>& res) {
        TreeNode* root = new TreeNode(res[0]);
        TreeNode* cur = root;
        
        // 定义变量保存res的长度
        int len = res.size();

        // 使用for循环比使用while循环方便，因为涉及当前节点下一个节点的索引
        for (int i = 1; i < len; i++) {
            cur->right = new TreeNode(res[i]);
            cur = cur->right;
        }

        return root;
    }

    void flattenTraversal(TreeNode* root) {
        // 定义变量保存前序遍历数组
        vector<int> res;

        // 前序遍历
        traversal(root, res);

        // 把res数组的元素变为链表
        root = toList(res);
    }

    void flatten(TreeNode* root) {
        while (root != nullptr) {
            // root的左边一直赋值空，所以一直往右边走

            // 先走到root的左节点
            TreeNode* p = root->left;

            // 如果root的左节点不为空
            if (p != nullptr) {
                // 找到root的左节点的最右节点
                while (p->right != nullptr) {
                    p = p->right;
                }

                // 三部曲
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            // root往右边走
            root = root->right;
        }
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution s;
    //s.flattenTraversal(root); // 这个方法错了
    s.flatten(root);

    TreeNode* cur = root;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->right;
    }
    cout << endl;

    return 0;
}