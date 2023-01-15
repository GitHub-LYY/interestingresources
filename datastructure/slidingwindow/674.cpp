/*
** Author: Yangyang Liu
** Date: 2023-01-15
** Description: 674. 最长连续递增序列
** link: https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0; // 定义变量保存结果
        int start = 0; // 定义滑动窗口的开始位置
        int len = nums.size(); // 定义变量保存数组长度

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) { // 不满足上升了，则把当前数字位置设为滑动窗口开始位置
                start = i;
            }

            res = max(res, i - start + 1); // 减去后要+1才是长度
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, 5, 4, 7};

    Solution s;
    int res = s.findLengthOfLCIS(nums);

    cout << res << endl;

    return 0;
}