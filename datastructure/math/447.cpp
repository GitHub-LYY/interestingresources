/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 447. 回旋镖的数量
** link: https://leetcode.cn/problems/number-of-boomerangs/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for (auto p : points) {
            unordered_map<int, int> count;
            for (auto q : points) {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                count[dis]++;
            }
            for (auto keyvalue : count) {
                res += keyvalue.second * (keyvalue.second - 1);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};

    Solution s;
    int res = s.numberOfBoomerangs(points);

    cout << res << endl;

    return 0;
}