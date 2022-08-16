/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 8. 字符串转换整数 (atoi)
** link: https://leetcode.cn/problems/string-to-integer-atoi/
** reference: 题解区，搜索，【数据结构和算法】字符串转换整数 (atoi)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // 如果字符串为空，则返回0
        if (s.size() == 0) {
            return 0;
        }

        // 定义变量遍历字符串的当前位置
        int  index = 0; 

        // 定义long类型变量保存结果，防止溢出
        long res = 0;

        // 定义变量保存正负号，1表示正，-1表示负
        int sign = 1;

        // 跳过字符串前面的空格
        while (index < s.size() && s[index] == ' ') {
            index++;
        }

        // 如果全部是空格，则返回0      
        if (index == s.size()) {
            return 0;
        }

        // 接下来index指向的是第一个非空格字符，判断正负号
        if (s[index] == '+' || s[index] == '-') {
            sign = s[index] == '+' ? 1 : -1;
            index++;
        }

        // 接下来看看字符是不是数字
        for (; index < s.size(); index++) {
            int digit = s[index] - '0';
            if (digit < 0 || digit > 9) {
                // 来到这儿，则不是0-9的数字

                break;
            }

            // 来到这儿，则是0-9的数字
            res = res * 10 + digit; // 求出当前的结果

            // 判断是否溢出
            if (res * sign > INT_MAX) {
                return INT_MAX;
            }

            if (res * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return res * sign;
    }
};

int main(int argc, char** argv) {
    string s = "42";

    Solution sol;
    int res = sol.myAtoi(s);

    cout << "res = " << res << endl;

    return 0;
}