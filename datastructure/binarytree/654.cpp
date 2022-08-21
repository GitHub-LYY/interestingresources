/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 654. 最大二叉树
** link: https://leetcode.cn/problems/maximum-binary-tree/
** reference: 代码随想录
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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution s;
    TreeNode* root = s.constructMaximumBinaryTree(nums);

    cout << "root->val = " << root->val << endl;

    return 0;
}