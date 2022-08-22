/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 718. 最长重复子数组
** link: https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                if (dp[i][j] > res) {
                    res = dp[i][j];
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    Solution s;
    int res = s.findLength(nums1, nums2);

    cout << res << endl;

    return 0;
}