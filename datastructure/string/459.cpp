/*
** Author: Yangyang Liu
** Date: 2022-12-12
** Description: 459. 重复的子字符串
** link: https://leetcode.cn/problems/repeated-substring-pattern/
** reference: 题解区，官方题解，方法二，代码随想录，两个理解了，代码随想录的比官方的容易理解
** 理解后，使用find函数实现，再使用字符串匹配实现
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNext(string& pattern) {
        // 定义变量保存结果
        vector<int> next(pattern.size());

        // 定义索引
        int i = 0;
        int n = -1;

        // 初始化next第一个
        next[0] = -1;

        while (i < pattern.size() - 1) {
            if (n < 0 || pattern[i] == pattern[n]) {
                next[++i] = ++n;
            } else {
                n = next[n];
            }
        }

        return next;
    }
    int strStr(string& text, string& pattern) {
        // 定义变量保存两个字符串的长度
        int m = text.size();
        int n = pattern.size();

        if (m < n) {
            return -1;
        }

        if (m == 0 || n == 0) {
            return -1;
        }

        // 定义索引
        int ti = 0;
        int pi = 0;

        // 求出next表
        vector<int> next = getNext(pattern);

        while (ti < m && pi < n) {
            if (pi < 0 || text[ti] == pattern[pi]) {
                ti++;
                pi++;
            } else {
                pi = next[pi];
            }
        }

        return pi == n ? ti - pi : -1;
    }
    bool repeatedSubstringPattern(string s) {
        // 定义s+s字符串
        string t = s + s;

        // 掐头去尾
        t.erase(t.begin());
        t.erase(t.end() - 1);

        // 判断s是否出现在此时掐头去尾的t中
        if (strStr(t, s) != -1) {
            return true;
        }

        return false;
    }
    bool repeatedSubstringPatternFind(string s) {
        // 定义s+s字符串
        string t = s + s;

        // 掐头去尾
        t.erase(t.begin()); // 一开始写错了，s，是t
        t.erase(t.end() - 1);

        // 判断s是否出现在此时掐头去尾的t中
        if (t.find(s) != string::npos) {
            return true;
        }

        return false;
    }
};

int main(int argc, char** argv) {
    string s = "abab";

    Solution sol;
    //bool res = sol.repeatedSubstringPatternFind(s);
    bool res = sol.repeatedSubstringPattern(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}