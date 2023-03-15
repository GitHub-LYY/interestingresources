/*
** Author: Yangyang Liu
** Date: 2023-03-15
** Description: 268. 丢失的数字
** link: https://leetcode.cn/problems/missing-number/
** reference: 官方题解，位运算
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); // 数组长度
        int res = 0;

        for (int i = 0; i < n; i++) { // 前一部分异或
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) { // 后一部分异或
            res ^= i; // 异或的是i，不是nums[i]
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 0, 1};

    Solution s;
    int res = s.missingNumber(nums);

    cout << res << endl;

    return 0;
}