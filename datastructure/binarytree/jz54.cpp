/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 54. 二叉搜索树的第k大节点
** link: https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
** reference: 自己做的
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
private:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        vector<int> vec;
        traversal(root, vec);
        return vec[vec.size() - k];
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    int k = 1;

    Solution s;
    int res = s.kthLargest(root, k);

    cout << "k th largest value is : " << res << endl;

    return 0;
}