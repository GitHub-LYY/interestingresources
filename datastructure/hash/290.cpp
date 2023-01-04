/*
** Author: Yangyang Liu
** Date: 2023-01-04
** Description: 290. 单词规律
** link: https://leetcode.cn/problems/word-pattern/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ch2str; // 字符-字符串映射
        unordered_map<string, char> str2ch; // 字符串-字符映射

        int n = s.size(); // 字符串的长度
        int i = 0; // 遍历s的索引

        for (char ch : pattern) { // 遍历pattern的每个字符，判断s中的每个单词是否满足规律
            if (i >= n) { // pattern没遍历完，s遍历完了，一定不满足
                return false;
            }

            int j = i; // 使用j和i求出s中的一个单词字符串
            while (j < n && s[j] != ' ') { // 取出s中的一个单词字符串
                j++;
            }
            string word = s.substr(i, j - i); 

            if (ch2str.find(ch) != ch2str.end() && ch2str[ch] != word) { // 不满足字符-字符串的映射
                return false;
            }
            if (str2ch.find(word) != str2ch.end() && str2ch[word] != ch) { // 不满足字符串-字符的映射
                return false;
            }

            ch2str[ch] = word; // 保存字符-字符串映射
            str2ch[word] = ch; // 保存字符串-字符映射

            i = j + 1; // i指向下一个单词第一个字母，不能写成j++
        }

        return i >= n; // 相等则意味着规律完全一样的，是>=
    }
};

int main(int argc, char** argv) {
    string pattern = "abba";
    string s = "dog cat cat dog";

    Solution sol;
    bool res = sol.wordPattern(pattern, s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}