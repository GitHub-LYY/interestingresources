/*
** Author: Yangyang Liu
** Date: 2022-09-11
** Description: 剑指 Offer 56 - I. 数组中数字出现的次数
** link: https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1yi4y1172m?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 定义变量保存x^y
        int xy = 0;

        for (int i = 0; i < nums.size(); i++) {
            xy ^= nums[i]; // 最终求出的是x^y
        }

        // 现在求x，y哪一位异或为1
        // 定义变量保存位置索引
        int index = 0;
        while ((xy & (1 << index)) == false) { // xy & (1 << index)操作必须加括号，否则不行，这个问题终于解决了，一直错
            // xy异或和1不断按位与，求出索引位置
            index++;
        }

        // 定义变量保存结果
        int x = 0;
        int y = 0;

        // 遍历数组，索引位置为0的分到x组，为1的分到y组
        for (int i = 0 ; i < nums.size(); i++) {
            if ((nums[i] & (1 << index))) { // 一开始这写多的是==true，这不能写，写了得不到正确答案，不是true
                // 索引位置为1，分到y组

                y ^= nums[i];
            } else {
                // 索引位置为0，分到x组

                x ^= nums[i];
            }
        }

        return vector<int>{x, y};
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 1, 4, 6};

    Solution s;
    vector<int> res = s.singleNumbers(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}