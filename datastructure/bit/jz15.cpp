/*
** Author: Yangyang Liu
** Date: 2022-09-06
** Description: 剑指 Offer 15. 二进制中1的个数
** link: https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1RW4y1m7xE?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 慕课教育up，极客时间
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeightFirstMethod(uint32_t n) {
        // 定义变量保存结果
        int count = 0;

        // 总共32位，循环32次，统计1的个数
        for (int i = 0; i < 32; i++) {
            count += n & 1;
            n >>= 1; // n每个循环右移一位
        }

        return count;
    }

    int hammingWeightSecondMethod(uint32_t n) {
        // 定义变量保存结果
        int count = 0;

        // 循环条件是n不为0
        while (n != 0) {
            count++;
            n &= n - 1; // 每次循环打掉n的最后一位1
        }

        return count;
    }
};

int main(int argc, char** argv) {
    int n = 11;

    Solution s;
    //int res = s.hammingWeightFirstMethod(n);
    int res = s.hammingWeightSecondMethod(n);

    cout << res << endl;

    return 0;
}