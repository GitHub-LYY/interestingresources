/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 151. 颠倒字符串中的单词
** link: https://leetcode.cn/problems/reverse-words-in-a-string/
** reference: 题解区，搜索，翻转字符串里的单词 | 图解双指针 | 超清晰易懂的题解 【c++版】，作者，林小鹿
** 20221103，隔了几个月再次做，有了自己的理解，for循环改为了while循环容易理解
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWordsOld(string s) {
        int k = 0; // 指向生成字符串的位置

        int i = 0;
        int j;

        for (i; i < s.size(); i++) {
            j = i;

            while (j < s.size() && s[j] == ' ') {
                // j负责为i开路

                j++;
            }
            
            if (j == s.size()) {
                // 防止最后一个字符是空格，下边把k的索引加一后，空格在最终字符串显示在最开始的位置

                break;
            }

            i = j;

            while (j < s.size() && s[j] != ' ') {
                // j负责为i开路

                j++;
            }

            reverse(s.begin() + i, s.begin() + j);

            if (k != 0) {
                // 单词之间用空格隔开

                s[k++] = ' ';
            }

            while (i < j) {
                s[k++] = s[i++]; // 生成最终的字符串的一部分
            }
        }

        // 把k后边的擦除
        s.erase(s.begin() + k, s.end());

        // 翻转整个字符串
        reverse(s.begin(), s.end());

        return s;
    }

    string reverseWords(string s) {
        int k = 0; // 指向生成字符串的位置

        int i = 0;
        int j;

        while (i < s.size()) {
            j = i;

            while (j < s.size() && s[j] == ' ') {
                // j负责为i开路

                j++;
            }
            
            if (j == s.size()) {
                // 防止最后一个字符是空格，下边把k的索引加一后，空格在最终字符串显示在最开始的位置

                break;
            }

            i = j;

            while (j < s.size() && s[j] != ' ') {
                // j负责为i开路

                j++;
            }

            reverse(s.begin() + i, s.begin() + j);

            if (k != 0) {
                // 单词之间用空格隔开

                s[k++] = ' ';
            }

            while (i < j) {
                s[k++] = s[i++]; // 生成最终的字符串的一部分
            }
        }

        // 把k后边的擦除
        s.erase(s.begin() + k, s.end());

        // 翻转整个字符串
        reverse(s.begin(), s.end());

        return s;
    }
};

int main(int argc, char** argv) {
    string s = "  hello world!  ";

    Solution sol;
    string res = sol.reverseWords(s);

    cout << res << endl;

    return 0;
}