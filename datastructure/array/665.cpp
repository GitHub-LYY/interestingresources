/*
** Author: Yangyang Liu
** Date: 2022-10-20
** Description: 665. 非递减数列
** link: https://leetcode.cn/problems/non-decreasing-array/
** reference: 官方题解，方法一，容易理解
** key point: 使用is_sorted(nums.begin(), nums.end())判断是否是非递减的
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // 遍历数组
        for (int i = 0; i < nums.size() - 1; i++) {
            // 遍历到倒数第二个数即可

            // 定义变量保存当前遍历的两个相邻的数
            int x = nums[i];
            int y = nums[i + 1];

            if (x > y) {
                // 出现了递减的情况，相邻的

                // 优先修改nums[i]为nums[i + 1]
                nums[i] = y;

                // 判断是否是非递减的，因为至多有一次修改次数
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }

                // 来到这儿，则意味着是[3, 4, 1, 2]->[3, 1, 1, 2]，此时要修改nums[i + 1]为nums[i]了
                nums[i] = x; // 还原
                nums[i + 1] = nums[i]; // 优先的不行，接着这的修改

                //if (is_sorted(nums.begin(), nums.end())) {
                //    return true;
                //} else {
                //    false;
                //}
                // 不要这种写法
                return is_sorted(nums.begin(), nums.end());
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 4, 1, 2};

    Solution s;
    bool res = s.checkPossibility(nums);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}