/*
** Author: Yangyang Liu
** Date: 2022-08-26
** Description: 剑指 Offer 26. 树的子结构
** link: https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
** reference: 题解区，搜索，C/C++ 查找可能的头节点 再匹配
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
private:
    bool traversalOld(TreeNode* curA, TreeNode* curB) {
        // 递归结束条件
        //if (curA->left == nullptr && curA->right == nullptr && curB->left == nullptr && curB->right == nullptr) {
            // 如果当前节点是叶子节点，且值相等

        //    return true;
        //}
        if (curB == nullptr) {
            return true;
        }
        if (curA == nullptr || curA->val != curB->val) {
            return false;
        }

        // 使用前序遍历，因为curA和curB已经判断相等了，所以中间节点不用继续做判断了，省略了

        // 递归判断左子树是否相等，右子树是否相等
        bool isSameLeft = traversal(curA->left, curB->left);
        bool isSameRight = traversal(curA->right, curB->right);

        // 仅仅用判断左右子树是否完全一致便可以得出是否一致的结论了
        bool res = isSameLeft && isSameRight;

        return res;
    }

    bool traversal(TreeNode* curA, TreeNode* curB) {
        // 共有四种情况，空空，不空不空，空不空，不空空

        if (curA == nullptr && curB == nullptr) {
            return true; // 这儿为true，一开始写错了
        }

        if (curA == nullptr && curB != nullptr) {
            return false;
        }

        if (curA != nullptr && curB == nullptr) {
            return true; // 这儿为true，一开始写错了
        }

        if (curA->val != curB->val) {
            return false;
        }

        if (curA->val == curB->val) {
            return traversal(curA->left, curB->left) && traversal(curA->right, curB->right);
        }

        return false;
    }
public:
    bool isSubStructureOld(TreeNode* A, TreeNode* B) {
        // 层序遍历遍历每一个节点

        // 定义队列保存树节点
        queue<TreeNode*> que;

        // 如果A的根节点不为空，则入栈
        if (A != nullptr) {
            que.push(A);
        }

        while (!que.empty()) {
            int size = que.size(); // 每一层的节点个数

            for (int i = 0; i < size; i++) {
                // 遍历每一层的节点

                TreeNode* node = que.front();
                que.pop();

                if (node->val == B->val) {
                    // 当前遍历到的A的节点与B的根节点相等，则递归遍历他们的所有节点看是否完全相等

                    bool isSame = traversal(node, B);

                    // 如果true则直接返回true，如果false则继续遍历a的下一个节点
                    if (isSame == true) {
                        return isSame;
                    } else {
                        continue;
                    }
                }

                // 当前节点的左节点入栈
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 当前节点的右节点入栈
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        // 如果上边没有返回true，则a和b没有相同的结构
        return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        if (A->val == B->val) {
            if (traversal(A, B) == true) {
                return true;
            }
        }

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

int main(int argc, char** argv) {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);

    TreeNode* B = new TreeNode(3);
    B->left = new TreeNode(1);

    Solution s;
    //bool res = s.isSubStructureOld(A, B);
    bool res = s.isSubStructure(A, B);

    cout << "Is B A's substructure?" << endl;
    cout << res << endl;

    return 0;
}