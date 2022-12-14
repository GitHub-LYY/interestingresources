/*
** Author: Yangyang Liu
** Date: 2022-12-14
** Description: 7. 整数反转
** link: https://leetcode.cn/problems/reverse-integer/
** reference: 题解区，官方题解，忍者算法，最终，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // 定义变量保存结果
        int res = 0;

        while (x != 0) {
            // 判断条件放在这儿，否则报错
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }

            // 取出x最后一位数字
            int lastDigit = x % 10; // 惯用手法

            // 判断是否溢出
            //if (res * 10 + lastDigit < INT_MIN / 10 || res * 10 + lastDigit > INT_MAX / 10) {
            //    return 0;
            //}

            // 求出翻转后的数值
            res = res * 10 + lastDigit; // 溢出判断必须在这行的前边

            // 取出除x最后一位的x
            x /= 10;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int x = 123;

    Solution s;
    int res = s.reverse(x);

    cout << res << endl;

    return 0;
}