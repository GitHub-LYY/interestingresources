/*
** Author: Yangyang Liu
** Date: 2023-01-28
** Description: 589. N 叉树的前序遍历
** link: https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void helper(Node* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        res.push_back(root->val);
        for (auto ch : root->children) {
            helper(ch, res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res; // 定义变量保存结果
        helper(root, res); // 递归遍历
        return res;
    }
};

int main(int argc, char** argv) {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution s;
    vector<int> res = s.preorder(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}