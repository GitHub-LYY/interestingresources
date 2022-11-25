/*
** Author: Yangyang Liu
** Date: 2022-11-25
** Description: 273. 整数转换英文表示
** link: https://leetcode.cn/problems/integer-to-english-words/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string toEnglish(int num) {
        // 输入是三位数字，转换为英文表示输出

        // 定义变量保存结果
        string res = "";

        // 取出百位的数字
        int hundredNum = num / 100; // 烂熟于心的写法了

        // 取出百位后，别忘了取出num的十位和个位
        num %= 100; // 也是烂熟于心的写法了

        if (hundredNum != 0) {
            // 百位数字不位0，才有处理的意义和必要

            res += singles[hundredNum] + " " + "Hundred" + " "; // 1-9的百，即100-900
        }

        // 取出十位的数字
        int tenNum = num / 10; // 也是烂熟于心的写法了
        // 这很重要，如果十位数字是2-9是一个处理逻辑，是1则另外的处理逻辑
        if (tenNum >= 2) {
            // 来到这儿，则是20,30，等等等

            res += tens[tenNum] + " "; // 这儿和上边的百位有点区别

            num %= 10; // 如果走这个逻辑了，要取出个位，巧妙
        }
        if (num >= 1 && num <= 9) {
            // 这个逻辑承接上边的十位是2以上的数字

            res += singles[num] + " ";
        } else if (num >= 10) {
            // 来到这，则十位是1，是十几的数字

            res += teens[num - 10] + " "; // 巧妙
        }

        return res;
    }
    string numberToWords(int num) {
        // 数值是0，输出zero
        if (num == 0) {
            return "Zero"; // 特殊情况
        }

        // 定义变量保存结果
        string res = "";

        // 每三个数字一组从做到右遍历
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            // 取出最左边三个一组的数字
            int curNum = num / unit;

            if (curNum != 0) {
                // 除以单位不是0，则有数值，要处理

                // 已经拿到最左边三个一组（不一定有三个数字）的数字了，要为下一轮做准备了
                num -= curNum * unit; // 巧妙

                res += toEnglish(curNum) + thousands[i] + " "; // 巧妙，函数输出三位数字的英文表示
            }
        }

        while (res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 1234567;

    Solution s;
    string res = s.numberToWords(num);

    cout << res << endl;

    return 0;
}