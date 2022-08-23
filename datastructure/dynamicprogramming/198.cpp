/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 198. 打家劫舍
** link: https://leetcode.cn/problems/house-robber/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);

        // dp数组初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 1};

    Solution s;
    int res = s.rob(nums);

    cout << "res:" << res << endl;

    return 0;
}