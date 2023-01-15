/*
** Author: Yangyang Liu
** Date: 2023-01-15
** Description: 438. 找到字符串中所有字母异位词
** link: https://leetcode.cn/problems/find-all-anagrams-in-a-string/
** reference: 题解区，官方题解，方法一
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(); // 定义变量保存字符串s的长度
        int pLen = p.size(); // 定义变量保存字符串p的长度

        if (sLen < pLen) { // s的长度小于p，则一定是空
            return {};
        }

        vector<int> res; // 定义变量保存结果
        vector<int> sCount(26); // 定义长度为26的动态数组作为哈希表，字母-出现次数哈希表
        vector<int> pCount(26); // 同上

        for (int i = 0; i < pLen; i++) {
            pCount[p[i] - 'a']++; // 求i位置字母出现次数
            sCount[s[i] - 'a']++; // 求s中i位置字母出现次数，这儿仅仅统计了一个滑动窗口
        }
        if (sCount == pCount) { // 动态数组可以直接比较是否相等
            res.emplace_back(0); // 此时相等，是最开始的滑动窗口是p的字母异位词了，因此把0位置保存
        }

        for (int i = 0; i < sLen - pLen; i++) { // 不断滑动窗口，判断滑动窗口内的字符串是否是p的字母异位词
            sCount[s[i] - 'a']--; // 去掉滑动窗口左边缘，相当于在滑动窗口
            sCount[s[i + pLen] - 'a']++; // 把右边缘往右移一位

            if (sCount == pCount) { // 相等，则滑动窗口内的字符串是p的字母异位词了
                res.emplace_back(i + 1); // 保存i+1位置，是滑动后的左边缘的位置，这理解了for循环不能写等号的原因了
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "cbaebabacd";
    string p = "abc";

    Solution sol;
    vector<int> res = sol.findAnagrams(s, p);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}