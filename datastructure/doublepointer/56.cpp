/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 56. 合并区间
** link: https://leetcode.cn/problems/merge-intervals/
** reference: 题解区，搜索，合并区间 | 图解排序 + 双指针算法 | 代码清晰易懂 【C++/Java版本】，作者，林小鹿
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 定义变量保存结果
        vector<vector<int>> res;

        // 对区间进行左对齐排序
        sort(intervals.begin(), intervals.end());

        // 定义双指针
        int left = intervals[0][0]; // 先指向第一个区间的左边界
        int right = intervals[0][1]; // 先执行第二个区间的右边界

        // 遍历区间
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > right) {
                // 当前区间的左边界大于上一个区间的右边界，两个区间不相交，把上一个区间放入结果中

                res.push_back({left, right});
                left = intervals[i][0]; // 更新左边界
                right = intervals[i][1]; // 更新右边界
            } else {
                // 当前区间的左边界小于等于上一个区间的右边界，两个区间相交，更新右边界
                right = max(right, intervals[i][1]);
            }
        }

        // 把最后的区间放入结果
        res.push_back({left, right});

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    Solution s;
    vector<vector<int>> res = s.merge(intervals);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}