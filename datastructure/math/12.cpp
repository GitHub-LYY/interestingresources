/*
** Author: Yangyang Liu
** Date: 2022-11-23
** Description: 12. 整数转罗马数字
** link: https://leetcode.cn/problems/integer-to-roman/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    // 使用对组保存符号和数值的映射关系
    const pair<int, string> valueSymbol[13] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    string intToRoman(int num) {
        // 定义变量保存结果
        string res = "";

        // 遍历的是对组
        for (const auto& [value, symbol] : valueSymbol) {
            while (num >= value) {
                num -= value; // 不断减去value最大值
                res += symbol; // 插入
            }

            if (num == 0) {
                break; // 一旦num为0，立即退出循环
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 3;

    Solution s;
    string res = s.intToRoman(num);

    cout << res << endl;

    return 0;
}