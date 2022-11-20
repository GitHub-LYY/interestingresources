/*
** Author: Yangyang Liu
** Date: 2022-11-20
** Description: 553. 最优除法
** link: https://leetcode.cn/problems/optimal-division/
** reference: 题解区，官方题解，方法二，数学方法
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // 数组size为1
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }

        // 数组size为2
        if (nums.size() == 2) {
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        }

        // 定义变量保存结果
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);

        // 数组size大于等于3
        for (int i = 2; i < nums.size(); i++) {
            res += '/' + to_string(nums[i]); // 不断拼接
        }

        res += ')';

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1000, 100, 10, 2};

    Solution s;
    string res = s.optimalDivision(nums);

    cout << res << endl;

    return 0;
}