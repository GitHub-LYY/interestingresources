/*
** Author: Yangyang Liu
** Date: 2023-01-26
** Description: 653. 两数之和 IV - 输入二叉搜索树
** link: https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/
** reference: 官方题解，方法二，层序遍历
*/

#include <iostream>
#include <unordered_set>
#include <queue>

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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> uset; // 保存每个遍历的节点的值
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front(); // 取出队首节点
            que.pop();

            if (uset.count(k - node->val)) { // node和另外一个节点的值的和是k
                return true;
            }
            uset.insert(node->val); // 遍历一个节点，把一个节点的值放入set
            
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int k = 9;

    Solution s;
    bool res = s.findTarget(root, k);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}