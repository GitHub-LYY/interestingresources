/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 1009. 十进制整数的反码
** link: https://leetcode.cn/problems/complement-of-base-10-integer/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // 定义最高位的索引的位置
        int highbit = 0;

        for (int i = 0; i <= 30; i++) {
            if (n >= (1 << i)) {
                highbit = i;
            } else {
                break; // 求出最高位的索引了，退出
            }
        }

        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1); // 括号容易错

        return n ^ mask;
    }
};

int main(int argc, char** argv) {
    int n = 5;

    Solution s;
    int res = s.bitwiseComplement(n);

    cout << res << endl;

    return 0;
}