/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 5. 最长回文子串
** link: https://leetcode.cn/problems/longest-palindromic-substring/
** reference: 题解区，搜索，【忍者算法】超级清晰易懂的白板题解+代码！
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 定义变量保存长度
        int maxLen = 0;

        // 定义变量保存开始位置
        int start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;

            // 定义变量保存长度
            int len = 1;

            while (left >= 0 && s[left] == s[i]) {
                left--;
                len++;
            }

            while (right < s.size() && s[right] == s[i]) {
                right++;
                len++;
            }

            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
                len += 2;
            }

            if (len > maxLen) {
                start = left + 1; // 开始的位置是left加一的位置，因为left的位置不满足
                maxLen = len; // 更新最长长度
            }
        }

        return s.substr(start, maxLen);
    }
};

int main(int argc, char** argv) {
    string s = "babad";

    Solution sol;
    string res = sol.longestPalindrome(s);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }

    return 0;
}