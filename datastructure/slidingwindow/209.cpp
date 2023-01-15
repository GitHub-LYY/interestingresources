/*
** Author: Yangyang Liu
** Date: 2023-01-15
** Description: 209. 长度最小的子数组
** link: https://leetcode.cn/problems/minimum-size-subarray-sum/
** reference: 题解区，官方题解，方法三，滑动窗口
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(); // 定义变量保存数组长度
        if (len == 0) {
            return len;
        }
        int start = 0; // 定义滑动窗口开始位置
        int end = 0; // 定义滑动窗口结束位置，开始的时候，start和end在第一个数字位置
        int sum = 0; // 定义变量保存滑动窗口中的数字之和
        int res = INT_MAX; // 定义变量保存结果

        while (end < len) { // 遍历数组
            sum += nums[end]; // 滑动窗口求和

            while (sum >= target) { // 滑动窗口之和大于等于target了
                res = min(res, end - start + 1); // 更新滑动窗口长度
                sum -= nums[start]; // 大于了，左边缘要收缩了
                start++; // 大于了，左边缘要收缩了
            }

            end++; // 窗口右边缘右移
        }

        return res == INT_MAX ? 0 : res; // 必须，直接输出res，这种情况报错，11,[1,1,1,1,1,1,1]
    }
};

int main(int argc, char** argv) {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    Solution s;
    int res = s.minSubArrayLen(target, nums);

    cout << res << endl;

    return 0;
}