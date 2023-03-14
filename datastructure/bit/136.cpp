/*
** Author: Yangyang Liu
** Date: 2023-03-14
** Description: 136. 只出现一次的数字
** link: https://leetcode.cn/problems/single-number/
** reference: 题解区，官方题解，直接读代码，不用读题解文字
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (auto num : nums) {
            res ^= num; // 使用异或抵消掉相同的数，剩下是出现一次的
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 2, 1};

    Solution s;
    int res = s.singleNumber(nums);

    cout << res << endl;

    return 0;
}