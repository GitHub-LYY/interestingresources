/*
** Author: Yangyang Liu
** Date: 2023-02-24
** Description: 401. 二进制手表
** link: https://leetcode.cn/problems/binary-watch/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res; // 定义变量保存结果

        for (int h = 0; h < 12; h++) { // 小时的遍历，0-11
            for (int m = 0; m < 60; m++) { // 分钟的遍历，0-59
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) { // 小时分钟的二进制中一的个数满足要求了
                    res.emplace_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int turnedOn = 1;

    Solution s;
    vector<string> res = s.readBinaryWatch(turnedOn);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}