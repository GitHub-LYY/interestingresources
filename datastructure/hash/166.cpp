/*
** Author: Yangyang Liu
** Date: 2023-01-05
** Description: 166. 分数到小数
** link: https://leetcode.cn/problems/fraction-to-recurring-decimal/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator; // 为了防止溢出，转换为long
        long denominatorLong = denominator;

        if (numeratorLong % denominatorLong == 0) {
            return to_string(numeratorLong / denominatorLong); // 整除的情况
        } 

        string res;
        if (numeratorLong > 0 ^ denominatorLong > 0) { // 两个数一个是正数一个是负数，则结果一定是负数
            res += '-';
        }
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        res += to_string(numeratorLong / denominatorLong); // 整数部分
        res += '.'; // 小数点

        string fractionPart;
        unordered_map<long, int> remainderIndexMap; // 余数-小数位置索引
        int index = 0; // 小数部分索引
        long remainder = numeratorLong % denominator; // 先求出此时的余数部分
        while (remainder != 0 && !remainderIndexMap.count(remainder)) { // 余数不为0，且哈希表中没有余数，则是有限小数
            remainderIndexMap[remainder] = index; // 哈希表插入key-value对
            remainder *= 10; // 每次把余数乘10
            fractionPart += to_string(remainder / denominatorLong); // 余数乘10除以分母取整是小数部分
            remainder %= denominatorLong; // 更新此时的余数
            index++; // 小数部分索引往后走
        }
        if (remainder != 0) { // 上边第二个条件不成立了，则是无限循环小数
            int insertIndex = remainderIndexMap[remainder]; // 从哈希表中取出循环的第一个小数的位置索引
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex, index - insertIndex) + ')'; // 为循环的小数部分加上括号
        }
        res += fractionPart;

        return res;
    }
};

int main(int argc, char** argv) {
    int numerator = 1;
    int denominator = 2;

    Solution s;
    string res = s.fractionToDecimal(numerator, denominator);

    cout << res << endl;

    return 0;
}