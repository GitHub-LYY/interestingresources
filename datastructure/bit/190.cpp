/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 190. 颠倒二进制位
** link: https://leetcode.cn/problems/reverse-bits/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 定义变量保存结果
        uint32_t res = 0; // 被按位或

        for (int i = 0; i < 32 && n > 0; i++) {
            // 别忘了第二个条件

            res |= (n & 1) << (31 - i); // 核心

            n >>= 1; // 右移一位，一开始忘写=了，错的
        }

        return res;
    }
};

int main(int argc, char** argv) {
    uint32_t n = 43261596;

    Solution s;
    uint32_t res = s.reverseBits(n);

    cout << res << endl;

    return 0;
}