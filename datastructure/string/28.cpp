/*
** Author: Yangyang Liu
** Date: 2022-08-24
** Description: 28. 实现 strStr()
** link: https://leetcode.cn/problems/implement-strstr/
** reference: kmp
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> getNext(string pattern) {
        vector<int> next(pattern.size());

        // 定义变量i遍历pattern字符串
        int i = 0;

        // 定义变量iMax保存i能达到的最远位置
        int iMax = pattern.size() - 1;

        // 定义变量n用来求出i位置的next数组的值
        int n = -1;

        // next[0]初始化为-1，第一位初始化为-1
        next[0] = -1;

        // 遍历pattern字符串
        while (i < iMax) {
            if (n < 0 || pattern[i] == pattern[n]) {
                // 第一个条件是为了一开始的时候进来用的，后边n大了以后，使用第二个条件更新next[i]

                next[++i] = ++n; // 前置++符号
            } else {
                // 上边条件的等式不成立

                n = next[n]; // 循环更新n的值使得i能用其来不断更新next[i]
            }
        }

        return next;
    }
public:
    int strStrViolationOld(string haystack, string needle) {
        // 先写出暴力解法，在暴力基础上修改为kmp的

        int i = 0; // 文本串的索引
        int j = 0; // 模式串的索引

        while (i < haystack.size() || j < needle.size()) {
            // 其中一个大于了，如果是文本串出界了，则匹配失败了，如果模式串出界了，则匹配成功了

            if (j >= needle.size()) {
                break;
            }

            if (i >= haystack.size()) {
                break;
            }

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                // 不相等，则更新i和j

                i = i - j + 1;
                j = 0;
            }
        }

        if (i < haystack.size() && j >= needle.size()) {
            // 匹配成功了

            return i - j; // 匹配成功的位置
        }

        if (i >= haystack.size() && j < needle.size()) {
            // 匹配失败了

            return -1;
        }

        if (i >= haystack.size() && j >= needle.size()) {
            // 匹配成功了

            return i - j;
        }

        return -1;
    }

    int strStrViolation(string haystack, string needle) {
        // 定义变量保存文本串和模式串的长度
        int tlen = haystack.size();
        int plen = needle.size();

        // 如果文本串和模式串任意为空，则匹配一定失败
        if (tlen == 0 || plen == 0) {
            return -1;
        }

        // 如果模式串长度大于文本串长度，则一定匹配失败
        if (plen > tlen) {
            return -1;
        }

        // 以上是异常情况

        // 定义变量指向文本串和模式串
        int ti = 0;
        int pi = 0;

        while (ti < tlen && pi < plen) {
            if (haystack[ti] == needle[pi]) {
                // 当前字符匹配，索引往后走

                ti++;
                pi++;
            } else {
                // 当前字符不匹配

                ti = ti - pi + 1; // ti的下一次的位置
                pi = 0;
            }
        }

        // 来到这儿，则上边的条件变为三种中的一种，ti==len, pi==len,ti==len&&pi==len
        return pi == plen ? (ti - pi) : -1;
    }

    int strStrKMP(string haystack, string needle) {
        // 先写出暴力解法，在暴力基础上修改为kmp的

        // 定义变量保存文本串和模式串的长度
        int tlen = haystack.size();
        int plen = needle.size();

        // 如果文本串和模式串任意一个为空，则一定匹配失败
        if (tlen == 0 || plen == 0) {
            return -1;
        }

        // 如果模式串的长度大于文本串的长度，则一定匹配失败
        if (plen > tlen) {
            return -1;
        }

        // 以上的异常情况处理

        // 求出kmp算法的next表
        vector<int> next = getNext(needle);

        // 定义变量用来索引文本串和模式串
        int ti = 0;
        int pi = 0;

        while (ti < tlen && pi < plen) {
            if (pi < 0 || haystack[ti] == needle[pi]) { // 相比暴力方法，这儿多了pi < 0的判断，这是next表第一位是-1的秒用，这儿使用第一个字符不匹配来考虑
                // 当前字符匹配成功，则索引往后走

                ti++;
                pi++;
            } else {
                // 当前字符匹配失败，根据kmp算法的next表查出要去的位置

                // ti不用走
                pi = next[pi];
            }
        }

        // 来到这儿，有三种情况，ti==tlen,pi==plen,ti==tlen&&pi==plen
        return pi == plen ? (ti - pi) : -1;
    }
};

int main(int argc, char** argv) {
    string haystack = "hello";
    string needle = "ll";

    Solution s;
    //int res = s.strStrViolationOld(haystack, needle);
    //int res = s.strStrViolation(haystack, needle);
    int res = s.strStrKMP(haystack, needle);

    cout << "res:" << res << endl;

    return 0;
}