/*
** Author: Yangyang Liu
** Date: 2022-12-11
** Description: 686. 重复叠加字符串匹配
** link: https://leetcode.cn/problems/repeated-string-match/
** reference: https://www.bilibili.com/video/BV1kW411R7kt/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站，up，keyeechen，这个题说的不错，很好，容易理解，比官方题解和微扰理论的题解容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNext(string& pattern) {
        // 定义next表
        vector<int> next(pattern.size());

        // 定义索引
        int i = 0;
        int n = -1;

        // next第一个数一定是-1
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
        // 输出pattern字符串在text中第一次匹配的位置

        // 定义变量保存长度
        int m = text.size();
        int n = pattern.size();

        if (m < n) {
            // 模式串的长度更长，一定不匹配

            return -1;
        }

        if (m == 0 || n == 0) {
            // 空串，一定不匹配

            return -1;
        }

        // 定义索引遍历字符串
        int ti = 0;
        int pi = 0;

        // 求出next表
        vector<int> next = getNext(pattern);

        while (ti < m && pi < n) {
            if (pi < 0 || text[ti] == pattern[pi]) {
                // 匹配

                ti++;
                pi++;
            } else {
                // 不匹配

                pi = next[pi];
            }
        }

        return pi == n ? ti - pi : -1;
    }
    int repeatedStringMatch(string a, string b) {
        // 定义变量保存重复次数
        int count = 1; // 必须为1

        // 定义由a重复生成的字符串
        string s = a; // 初始值为a

        // 重复a
        while (s.size() < b.size()) {
            s += a;
            count++; // 次数
        }

        // 判断b是否是s的模式串
        if (strStr(s, b) != -1) {
            // strStr()函数不匹配则输出-1

            return count;
        }

        // 上边这个判断可能不足以满足测试用例，因为可能出现此时的s.size() == b.size()，
        // 而s再重复一次a，b才可以满足匹配

        // s再重复一次a，排除这种例子：a = "abcd", b = "cdabcdab"
        s += a;
        count++;

        if (strStr(s, b) != -1) {
            // b是s的子串

            return count;
        }

        // 以上没有走，则一定是不匹配
        return -1;
    }

    int repeatedStringMatchSTL(string a, string b) {
        // 定义变量保存重复次数
        int count = 1;

        // 定义由a重复生成的字符串
        string s = a; // 初始值为a

        // 重复a
        while (s.size() < b.size()) {
            s += a;
            count++; // 次数
        }

        // 判断b是否是s的模式串
        if (s.find(b) != string::npos) {
            // find不匹配则输出npos

            return count;
        }

        // 上边这个判断可能不足以满足测试用例，因为可能出现此时的s.size() == b.size()，
        // 而s再重复一次a，b才可以满足匹配

        // s再重复一次a，排除这种例子：a = "abcd", b = "cdabcdab"
        s += a;
        count++;

        if (s.find(b) != string::npos) {
            // b是s的子串

            return count;
        }

        // 以上没有走，则一定是不匹配
        return -1;
    }
};

int main(int argc, char** argv) {
    string a = "abcd";
    string b = "cdabcdab";
    
    Solution sol;
    //int res = sol.repeatedStringMatchSTL(a, b);
    int res = sol.repeatedStringMatch(a, b);

    cout << res << endl;

    return 0;
}