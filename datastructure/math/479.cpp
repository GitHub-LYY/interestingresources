/*
** Author: Yangyang Liu
** Date: 2022-12-14
** Description: 479. 最大回文数乘积
** link: https://leetcode.cn/problems/largest-palindrome-product/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        // n为1要单独处理
        if (n == 1) {
            return 9;
        }

        // 定义n位数的最大数
        int upper = pow(10, n) - 1;

        for (int x = upper; ; x--) {
            // 定义要求的回文数
            long p = x;
            // 接下来求出p
            // 定义变量保存左边部分
            //for (int y = x; y > 0; y /= 10) {
            //    p = p * 10 + y % 10;
            //}
            int y = x;
            while (y > 0) {
                int digit = y % 10;
                p = p * 10 + digit;
                y /= 10;
            }
            // 至此，求出回文数

            // 判断回文数是否被整除
            for (long z = upper; z * z >= p; z--) {
                if (p % z == 0) {
                    return p % 1337;
                }
            }
            //long z = upper;
            //while (true) {
            //    if (p % z == 0) {
            //        return p % 1337;
            //    }
            //    z--;
            //}
        }
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    int res = s.largestPalindrome(n);

    cout << res << endl;

    return 0;
}