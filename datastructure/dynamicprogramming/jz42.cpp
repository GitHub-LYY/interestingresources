/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 剑指 Offer 42. 连续子数组的最大和
** link: https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/?favorite=xb9nqhhg
** reference: LeetCode53题，代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 定义dp数组
        vector<int> dp(nums.size());
        
        // dp数组初始化
        dp[0] = nums[0];

        // 定义变量保存结果
        int res = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);

            if (dp[i] > res) {
                res = dp[i];
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution s;
    int res = s.maxSubArray(nums);

    cout << res << endl;

    return 0;
}