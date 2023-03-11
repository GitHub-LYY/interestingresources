/*
** Author: Yangyang Liu
** Date: 2023-03-11
** Description: 436. 寻找右区间
** link: https://leetcode.cn/problems/find-right-interval/
** reference: 题解区，官方题解，先读的fuxuemingzhu的题解理解了题意，再去理解官方的题解，比较简洁一些
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals; // 每个区间的开始坐标及在intervals中的位置对组
        int len = intervals.size(); // 数组长度
        for (int i = 0; i < len; i++) { // 遍历数组求出需要的
            startIntervals.emplace_back(intervals[i][0], i); // 
        }

        vector<int> res(len, -1); // 结果数组初始化为-1
        sort(startIntervals.begin(), startIntervals.end()); // 二分搜索需要有序，而且已经保存位置索引了，所以排序没问题
        for (int i = 0; i < len; i++) { // 再次遍历数组
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
            if (it != startIntervals.end()) {
                res[i] = it->second; // 求出了第一个大于等于当前区间右端点的区间了，则保存这个区间的位置
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> intervals = {{1, 2}};

    Solution s;
    vector<int> res = s.findRightInterval(intervals);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}