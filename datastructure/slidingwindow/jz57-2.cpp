/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 57 - II. 和为s的连续正数序列
** link: https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/?favorite=xb9nqhhg
** reference: 题解区，搜索，什么是滑动窗口，以及如何用滑动窗口解这道题（C++/Java/Python）
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 定义变量保存结果
        vector<vector<int>> res;

        // 定义左右边界
        int left = 1;
        int right = 1; // 一开始为0

        // 定义变量保存窗口元素的和
        int sum = 0;

        while (right < target) {
            if (sum < target) {
                sum += right;
                right++; // 窗口扩大
            } else if (sum > target) {
                // 窗口要收缩了

                sum -= left; // 减去左边界
                left++; // 窗口收缩
            } else {
                // sum==target，则满足要求了

                // 定义中间变量保存满足要求的一个序列
                vector<int> vec;
                for (int i = left; i < right; i++) { // i不能等于right，否则错误
                    vec.push_back(i);
                }
                res.push_back(vec); // 收割结果

                // 别忘了窗口收缩
                sum -= left;
                left++;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int target = 9;

    Solution s;
    vector<vector<int>> res = s.findContinuousSequence(target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}