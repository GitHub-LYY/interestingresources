/*
** Author: Yangyang Liu
** Date: 2022-12-23
** Description: 29. 两数相除
** link: https://leetcode.cn/problems/divide-two-integers/
** reference: 题解区，搜索，简单易懂Java/C++ /Python/js/go - 两数相除，账号，老汤
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        // 越界
        if (a == INT_MIN && b == -1) {
            return INT_MAX; // 根据题意
        }

        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1; // 结果为负的
        }

        if (a > 0) {
            a = -a; // 转为负数来求
        }
        if (b > 0) {
            b = -b; // 转为负数来求
        }

        // 定义变量保存结果
        int res = 0;

        while (a <= b) {
            int value = b;
            int k = 1; // k代表有几个b

            while (value >= 0xc0000000 && a <= value + value) {
                // 放置value越界

                value += value;

                if (k > INT_MAX / 2) {
                    return INT_MIN;
                }
                k += k;
            }

            a -= value;
            res += k;
        }

        return sign == 1 ? res : -res;
    }
};

int main(int argc, char** argv) {
    int a = 10;
    int b = 3;

    Solution s;
    int res = s.divide(a, b);

    cout << res << endl;

    return 0;
}