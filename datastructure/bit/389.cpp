/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 389. 找不同
** link: https://leetcode.cn/problems/find-the-difference/
** reference: 题解区，官方题解方法三位运算，但是官方写的不够容易理解，评论区，账号，未有之梦，写的容易理解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // 拼接两个字符串
        string st = s + t;

        // 定义变量保存结果
        char res = 0;

        // 遍历字符串，使用异或求出结果
        for (char ch : st) {
            res ^= ch; // 最后求出是结果
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "abcd";
    string t = "abcde";

    Solution sol;
    char res = sol.findTheDifference(s, t);

    cout << res << endl;

    return 0;
}