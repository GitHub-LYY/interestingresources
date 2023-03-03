/*
** Author: Yangyang Liu
** Date: 2023-03-03
** Description: 133. 克隆图
** link: https://leetcode.cn/problems/clone-graph/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> node2node; // 节点-节点哈希表
public:
    Node* cloneGraph(Node* node) {
        if (!node) { // 节点是空
            return node;
        }

        if (node2node.count(node)) { // node在哈希表
            return node2node[node]; // 直接输出，不要重复克隆
        }

        Node* newNode = new Node(node->val); // 先克隆节点的值

        node2node[node] = newNode; // 插入哈希表

        for (auto neighbor : node->neighbors) { // 再克隆节点的邻居节点
            newNode->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};

int main(int argc, char** argv) {
    return 0;
}