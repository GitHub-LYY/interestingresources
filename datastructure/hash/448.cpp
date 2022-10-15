/*
** Author: Yangyang Liu
** Date: 2022-10-14
** Description: 448. 找到所有数组中消失的数字
** link: https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
** reference: https://www.bilibili.com/video/BV1FX4y1A7cz/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站，up，IT精品课程传送门，说的特别好

** 第二个版本，是忍者算法的缺失的第一个正数的方式，先把数字归位，再操作
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 定义变量保存结果
        vector<int> res;

        // 遍历数组，用下标进行负数标记
        for (int i = 0; i < nums.size(); i++) {
            int index = nums[i] >= 0 ? nums[i] : -nums[i]; // 正数则不变，负数则取正数

            if (nums[index - 1] > 0) {
                nums[index - 1] = -nums[index - 1]; // 正数变负数
            }
        }

        // 到这儿，已经标记完成

        // 第二次遍历数组，正数的下标+1是结果
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }

    vector<int> findDisappearedNumbersSecondEdition(vector<int>& nums) {
        // 定义变量保存结果
        vector<int> res;

        // 数字归位
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 遍历数组求出消失的数字
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution s;
    vector<int> res = s.findDisappearedNumbers(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}