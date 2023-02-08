/*
** Author: Yangyang Liu
** Date: 2023-02-08
** Description: 109. 有序链表转换二叉搜索树
** link: https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(right) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    ListNode* getMedian(ListNode* left, ListNode* right) { // 把right当做链表的最后的空节点来处理，容易理解 
        ListNode* slow = left;
        ListNode* fast = left; // 定义快指针

        while (fast != right && fast->next != right) {
            fast = fast->next->next; // 快指针走两步
            slow = slow->next; // 慢指针走一步
        }

        return slow; // 最后slow指的便是链表的中间节点
    }
    TreeNode* buildTree(ListNode* left, ListNode* right) {
        if (left == right) { // 左闭右开区间，如果相等，则区间不成立了
            return nullptr;
        }

        ListNode* median = getMedian(left, right); // 求出链表的中间节点作为根节点
        TreeNode* root = new TreeNode(median->val); // 求出根节点
        root->left = buildTree(left, median); // 左闭右开区间
        root->right = buildTree(median->next, right); // 左闭右开区间
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    Solution s;
    TreeNode* res = s.sortedListToBST(head);

    cout << res->val << endl;

    return 0;
}