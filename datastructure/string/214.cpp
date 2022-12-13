/*
** Author: Yangyang Liu
** Date: 2022-12-13
** Description: 214. 最短回文串
** link: https://leetcode.cn/problems/shortest-palindrome/
** reference: 题解区，搜索，「手画图解」从简单的暴力法想到 KMP，评论区，账号，未来的代码大神，提供了C++的KMP版本
** 写的版本和我写的类似，容易理解，但是写的有点小问题，我进行了优化，在我的题解中
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getNext(string& pattern) {
        // 定义next表
        vector<int> next(pattern.size());

        // 定义索引
        int i = 0;
        int n = -1;

        // next表第一个数一定是-1
        next[0] = -1;

        while (i < pattern.size() - 1) {
            if (n < 0 || pattern[i] == pattern[n]) {
                next[++i] = ++n; // 一开始写成==了，错的，这个地方容易写错，不要写错了
            } else {
                n = next[n];
            }
        }

        return next;
    }
    string shortestPalindrome(string s) {
        // 定义变量保存s的副本用来reverse
        string sCopy = s;

        // 对s的副本进行reverse
        reverse(sCopy.begin(), sCopy.end());

        // 定义变量保存s及reverse的拼接
        string t = s + "#" + sCopy + "#"; // 最后的#很关键，有了，容易理解，写的也优雅

        // 定义next表
        vector<int> next = getNext(t);
        // 取出next表的最后一个数
        int j = next[t.size() - 1]; // 这是t的最后#的前边的最长公共前后缀，也是s的最长回文前缀

        // 拼接
        return sCopy + s.substr(j, s.size() - j); // 拼接进行了转换
    }
};

int main(int argc, char** argv) {
    string s = "aacecaaa";

    Solution sol;
    string res = sol.shortestPalindrome(s);

    cout << res << endl;

    return 0;
}