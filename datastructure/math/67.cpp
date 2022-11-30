/*
** Author: Yangyang Liu
** Date: 2022-11-30
** Description: 67. 二进制求和
** link: https://leetcode.cn/problems/add-binary/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // 定义变量保存结果
        string res;

        // a，b字符串做逆序操作
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // 定义进位
        int carry = 0;

        // 一开始忘了，必须要遍历最长的字符串
        int maxSize = max(a.size(), b.size());

        // 遍历任一字符串
        for (int i = 0; i < maxSize; i++) {
            carry += i < a.size() ? (a[i] == '1') : 0;
            carry += i < b.size() ? (b[i] == '1') : 0; // 巧妙

            res.push_back(carry % 2 ? '1' : '0'); // 模2仅仅有1或者0，是1则插入1，是0则插入0

            carry = carry / 2; // 取出进位，下一轮继续求和
        }

        // 遍历完，carry是1，则有进位，继续插入一个进位1
        if (carry) {
            // carry是1

            res.push_back('1'); // 最后插入1
        }

        // 逆序操作
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    string a = "11";
    string b = "1";

    Solution s;
    string res = s.addBinary(a, b);

    cout << res << endl;

    return 0;
}