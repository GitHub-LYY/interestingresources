/*
** Author: Yangyang Liu
** Date: 2023-03-15
** Description: 260. 只出现一次的数字 III
** link: https://leetcode.cn/problems/single-number-iii/
** reference: https://www.bilibili.com/video/BV1yi4y1172m?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0; // x^y，数组中两个不同数的异或结果
        int len = nums.size(); // 数组长度
        
        for (int i = 0; i < len; i++) { // 循环结束后求出的是x^y
            xy ^= nums[i]; 
        }

        int index = 0; // 求出x^y从右往左的第一个二进制位的1，用来进行分组
        while ((xy & (1 << index)) == 0) { // 二进制从右往左第一个1的索引
            index++;
        }

        int x = 0; // 保存两个数之一
        int y = 0; // 保存两个数之一
        for (int i = 0; i < len; i++) {
            if ((nums[i] & (1 << index)) == 0) { // 二进制index索引处是0，则分为一组
                x ^= nums[i];
            } else { // 二进制index索引处是1，则分为一组
                y ^= nums[i]; 
            }
        }

        return vector<int> {x, y};
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    Solution s;
    vector<int> res = s.singleNumber(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}