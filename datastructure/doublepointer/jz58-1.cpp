/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 58 - I. 翻转单词顺序
** link: https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
** reference: 151题
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 定义i，j指针指向s
        int i = 0;
        int j = 0;

        // 定义k指针指向新生成的字符串
        int k = 0;

        while (i < s.size()) {
            // 使用j指针把字符串前边的空格走完
            while (j < s.size() && s[j] == ' ') {
                j++;
            }

            // 一开始忘了，这儿必须有，否则LeetCode报错
            if (j >= s.size()) {
                break; // 保证下边不多产生一个空格
            }

            // j现在指向字符串第一个非空字符，把i指向这个位置，j继续走到空格，圈出一个单词，接下来翻转
            i = j;
            while (j < s.size() && s[j] != ' ') {
                // j指向的不是空格，一直往前走

                j++;
            }

            // 翻转i到j圈出的单词
            reverse(s.begin() + i, s.begin() + j);

            // 翻转完了，把这个单词放入k指向的位置
            if (k != 0) {
                s[k++] = ' '; // 每个单词之间有一个空格，第一个单词前边没有空格，所以是这个条件，k必须往后走，一开始忘了
            }

            while (i < j) {
                // 这儿把i走到j

                s[k++] = s[i++];
            }
        }

        // 到这儿，则现在k后边的所有元素是没有用的了，删除
        s.erase(s.begin() + k, s.end());

        // 最后整体翻转
        reverse(s.begin(), s.end());

        return s;
    }
};

int main(int argc, char** argv) {
    string str = "the sky is blue";

    Solution s;
    string res = s.reverseWords(str);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }

    return 0;
}