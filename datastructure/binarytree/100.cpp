/*
** Author: Yangyang Liu
** Date: 2023-01-18
** Description: 100. 相同的树
** link: https://leetcode.cn/problems/same-tree/
** reference: 官方题解，方法一，深度优先搜索
*/

#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) { // 从两个为空，到一个是空，到两个非空
            return true;
        } else if (p == nullptr || q == nullptr) { // 一个是空，一个是非空，承接上个条件
            return false;
        } else if (p->val != q->val) { // 两个非空，值不等
            return false;
        } else { // 两个根节点值相等，则继续判断他们的左右子节点是否相等
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
        }
    }
};

int main(int argc, char** argv) {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution s;
    bool res = s.isSameTree(p, q);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}