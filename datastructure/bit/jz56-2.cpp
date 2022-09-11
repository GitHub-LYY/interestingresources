/*
** Author: Yangyang Liu
** Date: 2022-09-11
** Description: 剑指 Offer 56 - II. 数组中数字出现的次数 II
** link: https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1VR4y1L7gu?spm_id_from=333.337.search-card.all.click
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 定义变量保存求和的二进制
        vector<int> binarySumVec(32, 0);

        for (int i = 0 ; i < nums.size(); i++) {
            // 遍历每个数字

            for (int j = 0; j < 32; j++) {
                // 遍历每个数字的时候求二进制求和

                if (nums[i] & (1 << j)) {
                    // 如果j位为1，则二进制的位要加一

                    binarySumVec[j]++;
                }
            }
        }

        // 二进制位求和完毕
        // 二进制位%3
        // %3和转换十进制融合了

        // 定义变量保存结果
        int res = 0;
        for (int i = 0; i < 32; i++) {
            binarySumVec[i] = binarySumVec[i] % 3; // 求出%3的二进制位
            res |= binarySumVec[i] << i; // 转换十进制使用或操作
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 4, 3, 3};

    Solution s;
    int res = s.singleNumber(nums);

    cout << res << endl;

    return 0;
}