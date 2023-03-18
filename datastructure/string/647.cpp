/*
** Author: Yangyang Liu
** Date: 2022-12-13，2023-03-18
** Description: 647. 回文子串
** link: https://leetcode.cn/problems/palindromic-substrings/
** reference: 题解区，官方题解，搜索，两道回文子串的解法（详解中心扩展法），两个题解理解了，最后官方题解
** 20230318，发现官方题解包括搜索的，不容易理解，要记忆公式，官方题解评论区的很容易理解，作者，泪雨潇虹
*/

#include <iostream>

using namespace std;

class SolutionOld {
public:
    int countSubstrings(string s) {
        // 定义变量保存字符串的字符个数
        int n = s.size();

        // 定义变量保存结果
        int res = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            // 求出l的索引，r的索引
            int left = i / 2;
            int right = i / 2 + i % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                // 没有越界，且left和right位置的字符相等

                res++;
                left--;
                right++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(); // 字符串长度
        int res = 0; // 回文子串数量

        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= 1; j++) { // j取0和1
                int left = i;
                int right = i + j; // right有两种情况，第一是等于i，第二是在i的右边

                while (left >= 0 && right < len && s[left] == s[right]) { // 没有越界，且相等
                    left--;
                    right++;
                    res++; // 回文子串数量多一
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "abc";

    Solution sol;
    int res = sol.countSubstrings(s);

    cout << res << endl;
    
    return 0;
}