/*
** Author: Yangyang Liu
** Date: 2023-03-08
** Description: 547. 省份数量
** link: https://leetcode.cn/problems/number-of-provinces/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = Find(parent, parent[i]);
        }

        return parent[i];
    }
    void Union(vector<int>& parent, int i, int j) {
        parent[Find(parent, i)] = Find(parent, j);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size(); // 城市数量
        vector<int> parent(cities); // 并查集的根节点数组
        for (int i = 0; i < cities; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < cities; i++) {
            for (int j = i + 1; j < cities; j++) {
                if (isConnected[i][j] == 1) { // 相连
                    Union(parent, i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < cities; i++) {
            if (parent[i] == i) {
                res++;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    Solution s;
    int res = s.findCircleNum(isConnected);

    cout << res << endl;

    return 0;
}