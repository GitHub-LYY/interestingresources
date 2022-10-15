/*
** Author: Yangyang Liu
** Date: 2022-10-15
** Description: 442. 数组中重复的数据
** link: https://leetcode.cn/problems/find-all-duplicates-in-an-array/
** reference: https://www.bilibili.com/video/BV1oZ4y1h7PZ/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站，up，hithertothework

** 忍者算法的缺失的第一个正数，先把数字归位，再操作
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 定义变量保存结果
        vector<int> res;

        // 数字归位
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 再次遍历数组，收割结果
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                res.push_back(nums[i]); // 此时是结果
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution s;
    vector<int> res = s.findDuplicates(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}