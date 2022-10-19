/*
** Author: Yangyang Liu
** Date: 2022-10-19
** Description: 453. 最小操作次数使数组元素相等
** link: https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 第一次遍历求出最小值，也可以使用stl求出最小值
        int minValue = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minValue) {
                minValue = nums[i];
            }
        }

        // 定义变量保存结果
        int res = 0;

        // 第二次遍历数组，求出最小操作次数
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i] - minValue;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};

    Solution s;
    int res = s.minMoves(nums);

    cout << res << endl;

    return 0;
}