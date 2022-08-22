/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 300. 最长递增子序列
** link: https://leetcode.cn/problems/longest-increasing-subsequence/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 如果数组有0个，1个元素
        if (nums.size() <= 1) {
            return nums.size();
        }

        // 定义dp数组
        vector<int> dp(nums.size(), 1);

        // 定义变量保存结果
        int maxLen = 0;

        // 遍历数组
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) { // 这儿必须有j从0到i-1
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution s;
    int res = s.lengthOfLIS(nums);

    cout << res << endl;

    return 0;
}