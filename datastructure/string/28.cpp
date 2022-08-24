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
    int strStrViolation(string haystack, string needle) {
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

    int strStrKMP(string haystack, string needle) {
        // 先写出暴力解法，在暴力基础上修改为kmp的

        int i = 0; // 文本串的索引
        int j = 0; // 模式串的索引

        // 求出needle的next表
        vector<int> next = getNext(needle);

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
                // 不相等，则更新i和j，这体现出和暴力解法的区别了

                // i不用动，只用更新j的索引
                j = next[j]; // 跳到next[j]指向的位置
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
};

int main(int argc, char** argv) {
    string haystack = "hello";
    string needle = "ll";

    Solution s;
    //int res = s.strStrViolation(haystack, needle);
    int res = s.strStrKMP(haystack, needle);

    cout << "res:" << res << endl;

    return 0;
}