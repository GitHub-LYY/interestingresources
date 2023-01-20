/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-01-20
** Description: 654. 最大二叉树
** link: https://leetcode.cn/problems/maximum-binary-tree/
** reference: 代码随想录
** 20230120，官方题解
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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nullptr;
        }

        // 找到最大值的下标
        int maxIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // 最大值是根节点
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // 递归构建左右子树
        root->left = traversal(nums, left, maxIndex);
        root->right = traversal(nums, maxIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTreeOld(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left > right) { // 这很重要
            return nullptr; 
        }

        int maxIndex = left; // 最大索引初始化为左边界
        for (int i = left + 1; i <= right; i++) { 
            if (nums[i] > nums[maxIndex]) { // 有比当前最大索引更大的数
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]); // 最大值索引的值生成根节点
        root->left = construct(nums, left, maxIndex - 1); // 递归左边数组
        root->right = construct(nums, maxIndex + 1, right); // 递归右数组

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution s;
    TreeNode* root = s.constructMaximumBinaryTree(nums);

    cout << "root->val = " << root->val << endl;

    return 0;
}