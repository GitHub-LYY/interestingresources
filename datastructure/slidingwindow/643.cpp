/*
** Author: Yangyang Liu
** Date: 2023-01-14
** Description: 643. 子数组最大平均数 I
** link: https://leetcode.cn/problems/maximum-average-subarray-i/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0; // 定义变量保存滑动窗口的和
        for (int i = 0; i < k; i++) {
            sum += nums[i]; // 求出开头四个数字之和作为初始值
        }

        int maxSum = sum; // 最大和的初始值

        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i]; // 去掉滑动窗口第一个数，滑动窗口，加入滑动窗口最后一个数
            maxSum = max(maxSum, sum); // 求最大和
        }

        return static_cast<double> (maxSum) / k;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    Solution s;
    double res = s.findMaxAverage(nums, k);

    cout << res << endl;

    return 0;
}