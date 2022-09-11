/*
** Author: Yangyang Liu
** Date: 2022-09-11
** Description: 剑指 Offer 61. 扑克牌中的顺子
** link: https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
** reference: https://www.bilibili.com/video/BV1PZ4y1o7UF?spm_id_from=333.999.0.0&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 定义哈希set保存数字
        unordered_set<int> uset;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            if (uset.find(nums[i]) == uset.end()) {
                // 当前数字不在uset中，则插入uset

                uset.insert(nums[i]);
            } else if (nums[i] != 0) {
                // 来到这儿，则当前数字在哈希set中，如果当前数字不是0，则是不行的，一定不是顺子

                return false;
            } else {
                // 当前数字在哈希set中，且是0

                // 使用的是哈希set，因此不用加一，直接不用做操作即可
                continue;
            }
        }

        // 第二类情况

        // 对数组排序
        sort(nums.begin(), nums.end());

        // 定义变量保存最小值
        int minVal = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 求出最小值，最大值不用求，直接是数组的最后一个了

            if (nums[i] != 0) {
                // 不为0，则一定是最小值了

                minVal = nums[i];

                // 保存了，不用继续往后了，直接退出循环
                break;
            }
        }

        bool res = false;
        if ((nums[nums.size() - 1] - minVal) < 5) {
            // 差值小于最大值，则是顺子

            res = true;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    //vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {4, 7, 5, 9, 2};

    Solution s;
    bool res = s.isStraight(nums);

    if (res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}