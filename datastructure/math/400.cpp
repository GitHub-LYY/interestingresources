/*
** Author: Yangyang Liu
** Date: 2022-12-21
** Description: 400. 第 N 位数字
** link: https://leetcode.cn/problems/nth-digit/
** reference: 题解区，搜索，【微扰理论】模拟题 先计算该位数字对应的是几位数；再算具体是哪个数字，账号，微扰理论
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // 定义变量保存位数
        int digit = 1;

        // 定义变量保存digit位数有多少数字
        int border = 9;

        while (n > (long) digit * border) {
            // 第一大步，求出在几位数中

            n -= digit * border;

            digit++;
            border *= 10; // 每次以10倍成长
        }

        // 此时的n是剩下的位的数量了

        int offset = (n - 1) / digit; // 求出在digit位的数中的偏移量

        int begin = 1; // 求digit位数的开始的数
        for (int i = 0; i < digit - 1; i++) {
            begin *= 10;
        }

        // 求具体的那个数
        string obj = to_string(begin + offset); // 转换为字符串容易求解

        // 求具体数中的第几位
        int mod = (n - 1) % digit;

        return obj[mod] - '0';
    }
};

int main(int argc, char** argv) {
    int n = 11;

    Solution s;
    int res = s.findNthDigit(n);

    cout << res << endl;

    return 0;
}