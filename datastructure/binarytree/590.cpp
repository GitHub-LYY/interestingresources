/*
** Author: Yangyang Liu
** Date: 2023-02-02
** Description: 590. N 叉树的后序遍历
** link: https://leetcode.cn/problems/n-ary-tree-postorder-traversal/
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
        if (!root) { // 节点是空
            return;
        }

        for (auto ch : root->children) { // 先遍历孩子节点
            helper(ch, res); 
        }

        res.push_back(root->val); // 最后遍历根节点
    }
    vector<int> postorder(Node* root) {
        vector<int> res; // 定义变量保存结果
        helper(root, res);
        return res;
    }
};

int main(int argc, char** argv) {
    Node* root = new Node(1);
    root->children.emplace_back(new Node(3));
    root->children.emplace_back(new Node(2));
    root->children.emplace_back(new Node(4));
    root->children[0]->children.emplace_back(new Node(5));
    root->children[0]->children.emplace_back(new Node(6));

    Solution s;
    vector<int> res = s.postorder(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}