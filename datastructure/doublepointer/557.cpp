/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 557. 反转字符串中的单词 III
** link: https://leetcode.cn/problems/reverse-words-in-a-string-iii/
** reference: 题解区，151题的一部分
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 定义指针
        int i = 0;
        int j = 0;

        // 遍历字符串
        while (i < s.size()) {
            // 探索每个单词前边的空格
            while (j < s.size() && s[j] == ' ') {
                j++;
            }

            if (j == s.size()) {
                break;
            }

            // 把i指向单词开始位置
            i = j; // 此时的j是单词的开始位置

            // j继续奔波，探索单词的尾部
            while (j < s.size() && s[j] != ' ') {
                j++;
            }

            // j指向的是单词最后一个字符的下一个位置，使用stl的算法
            reverse(s.begin() + i, s.begin() + j); // 翻转每个单词
        }

        return s;
    }
};

int main(int argc, char** argv) {
    string s = "Let's take LeetCode contest";

    Solution sol;
    string res = sol.reverseWords(s);

    cout << res << endl;

    return 0;
}