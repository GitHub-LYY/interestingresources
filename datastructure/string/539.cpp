/*
** Author: Yangyang Liu
** Date: 2022-11-20
** Description: 539. 最小时间差
** link: https://leetcode.cn/problems/minimum-time-difference/
** reference: 题解区，官方题解
** 在搜索视频的时候，有一个b站的up，账号是，我不是匠人，很好
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMinutes(string s) {
        return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0'); // 转换为分钟
    }
    int findMinDifference(vector<string>& timePoints) {
        // 先做排序
        sort(timePoints.begin(), timePoints.end());

        // 取出第一个时间
        int t0Minutes = getMinutes(timePoints[0]); // 把第一个时间转换为分钟

        // 定义变量保存前一个时间
        int preMinutes = 0;
        preMinutes = t0Minutes;

        // 定义变量保存结果
        int res = INT_MAX; // 保存为0出错，必须为INT_MAX

        // 遍历
        for (int i = 1; i < timePoints.size(); i++) {
            // 取出当前遍历到的时间的分钟数
            int curMinutes = getMinutes(timePoints[i]);

            // 求最小的时间差
            res = res > (curMinutes - preMinutes) ? (curMinutes - preMinutes) : res;

            // 别忘了preMinutes
            preMinutes = curMinutes;
        }

        res = res > (t0Minutes + 24 * 60 - preMinutes) ? (t0Minutes + 24 * 60 - preMinutes) : res;

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> timePoints = {"23:59", "00:00"};

    Solution s;
    int res = s.findMinDifference(timePoints);

    cout << res << endl;

    return 0;
}