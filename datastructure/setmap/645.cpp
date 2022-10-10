/*
** Author: Yangyang Liu
** Date: 2022-10-10
** Description: 645. 错误的集合
** link: https://leetcode.cn/problems/set-mismatch/
** reference: https://www.bilibili.com/video/BV1m5411T7qg/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站视频，up，IT精品课程传送门，本题用哈希数组
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 定义数组表示哈希表
        int hash[10001] = {0};

        // 定义变量保存重复的值
        int same = 0;

        // 定义变量保存出现次数为0的数字
        int lost = 0;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++; // 数字出现次数

            if (hash[nums[i]] == 2) {
                // 出现2次，则重复了，记录

                same = nums[i];
            }
        }

        // 第二次遍历数组求lost
        for (int i = 1; 1; i++) {
            if (hash[i] == 0) {
                // 出现0次，则是lost

                lost = i;
                break;
            }
        }

        return vector<int>({same, lost});
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 2, 4};
    
    Solution s;
    vector<int> res = s.findErrorNums(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}