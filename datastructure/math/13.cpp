/*
** Author: Yangyang Liu
** Date: 2022-11-23
** Description: 13. 罗马数字转整数
** link: https://leetcode.cn/problems/roman-to-integer/
** reference: 题解区，官方题解，也有忍者算法，写的是官方的方法
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> symbolValue = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        // 定义变量保存结果
        int res = 0; // 初始值为0

        for (int i = 0; i < s.size(); i++) {
            int value = symbolValue[s[i]]; // 取出当前字符代表的值

            if (i < s.size() - 1 && value < symbolValue[s[i + 1]]) {
                // 当前字符的值比下一个小，则当前的字符要被减

                res -= value;
            } else {
                // 当前字符大于等于下一个，则一直做累加操作

                res += value;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "MCMXCIV";

    Solution sol;
    int res = sol.romanToInt(s);

    cout << res << endl;

    return 0;
}