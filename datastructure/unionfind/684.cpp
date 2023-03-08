/*
** Author: Yangyang Liu
** Date: 2023-03-08
** Description: 684. 冗余连接
** link: https://leetcode.cn/problems/redundant-connection/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }
    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numNodes = edges.size(); // 节点数量
        vector<int> parent(numNodes + 1); // 并查集数组
        for (int i = 1; i <= numNodes; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }

        return vector<int> {};
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

    Solution s;
    vector<int> res = s.findRedundantConnection(edges);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}