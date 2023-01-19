/*
** Author: Yangyang Liu
** Date: 2022-08-20，2023-01-19
** Description: 101. 对称二叉树
** link: https://leetcode.cn/problems/symmetric-tree/
** reference: 代码随想录
** 20230119，官方题解，方法二，迭代
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
    bool traversal(TreeNode* left, TreeNode* right) {
        // 左空右不空，左不空右空，左不空右不空值不相等，一定不对称
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            // 左右都不为空

            return false;
        }

        // 来到这儿，则左右不为空，值相等，接下来判断内测外侧是否相等

        bool outside = traversal(left->left, right->right);
        bool inside = traversal(left->right, right->left);
        bool isSame = outside && inside;

        return isSame;
    }

    bool isSymmetricOld(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return traversal(root->left, root->right);
    }

    bool check(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que; // 定义队列保存树节点
        que.push(p); // 树节点入队
        que.push(q); // 树节点入队

        while (!que.empty()) {
            p = que.front(); // 拿出队列中的树节点，这不能定义node1使用，必须是p来接收，仔细思考，巧妙
            que.pop();
            q = que.front(); // 拿出队列中的树节点
            que.pop();

            if (p == nullptr && q == nullptr) { // 两个节点都是空
                continue; // 一开始写成return true了，错的
            }
            if ((p == nullptr || q == nullptr) || (p->val != q->val)) { // 一个是空，一个是非空，或，值不相等
                return false;
            }

            que.push(p->left); // 左的左
            que.push(q->right); // 右的右
            que.push(p->right); // 左的右
            que.push(q->left); // 右的左
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root); // 参数是两个节点
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    bool res = s.isSymmetric(root);

    cout << "is symmetric: " << res << endl;

    return 0;
}