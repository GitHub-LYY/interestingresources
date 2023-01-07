/*
** Author: Yangyang Liu
** Date: 2023-01-07
** Description: 594. 最长和谐子序列
** link: https://leetcode.cn/problems/longest-harmonious-subsequence/
** reference: https://www.bilibili.com/video/BV1C44y1q7Ny/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** B站，up，IT精品课程传送门，视频理解后去学官方题解，理解了，官方题解没有判断x-1的情况，简洁一些
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> num2num; // 数字-出现次数哈希表
        int res = 0; 

        for (auto num : nums) { // 遍历数组的数字填充哈希表
            num2num[num]++;
        }

        for (auto keyvalue : num2num) { //  遍历哈希表
            int key = keyvalue.first; // 取出数字
            int value = keyvalue.second; // 取出当前数字出现的次数
            if (num2num.count(key + 1) > 0) {
                res = max(res, value + num2num[key + 1]);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    Solution s;
    int res = s.findLHS(nums);

    cout << res << endl;

    return 0;
}