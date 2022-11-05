/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 8. 字符串转换整数 (atoi)
** link: https://leetcode.cn/problems/string-to-integer-atoi/
** reference: 题解区，搜索，【数据结构和算法】字符串转换整数 (atoi)
** 20221105，自己再次做，有了自己的理解，又写了一个版本
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoiOld(string s) {
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

    int myAtoi(string s) {
        // 定义变量保存索引用来遍历字符串
        int i = 0;

        // 定义变量保存正负数标记，使用1标记正数，-1标记负数，方便后边直接与数相乘求着个数
        int sign = 1;

        // 遍历前边的空格
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // 字符串的题不要忘了判断索引是否越界
        if (i == s.size()) {
            return 0;
        }

        // 判断正负号，条件中使用 或 运算，内部的写法很巧妙
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+' ? 1 : -1); // 巧妙
            i++;
        }

        // 定义变量保存结果
        long num = 0;

        // 遍历数字区间
        while (i < s.size() && isdigit(s[i])) {
            num *= 10;
            num += s[i] - '0';

            // 这儿不要忘了每个循环要判断当前是否越界，越界了要及时退出
            if (num * sign > INT_MAX) {
                return INT_MAX;
            }

            if (num * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return num * sign; // 这可以解决测试用例"-+50"
    }
};

int main(int argc, char** argv) {
    string s = "42";

    Solution sol;
    int res = sol.myAtoi(s);

    cout << "res = " << res << endl;

    return 0;
}