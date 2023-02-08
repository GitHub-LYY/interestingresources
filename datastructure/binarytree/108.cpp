/*
** Author: Yangyang Liu
** Date: 2023-02-08
** Description: 108. 将有序数组转换为二叉搜索树
** link: https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

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
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) { // 不满足了，输出空节点
            return nullptr;
        }

        int mid = left + (right - left) / 2; // 求出数组中间的数作为根节点

        TreeNode* root = new TreeNode(nums[mid]); // 求出根节点
        root->left = helper(nums, left, mid - 1); // 求出根节点左子树
        root->right = helper(nums, mid + 1, right); // 求出根节点右子树
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution s;
    TreeNode* res = s.sortedArrayToBST(nums);

    cout << res->val << endl;

    return 0;
}