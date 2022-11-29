/*
** Author: Yangyang Liu
** Date: 2022-11-29
** Description: 522. 最长特殊序列 II
** link: https://leetcode.cn/problems/longest-uncommon-subsequence-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 判断是否是子序列的函数
    bool isSubseq(string pattern, string text) {
        // 判断pattern串是否是text的子序列

        // 定义指针指向pattern和text
        int i = 0;
        int j = 0; // 指向text

        // 判断子序列的经典循环
        while (i < pattern.size() && j < text.size()) {
            if (pattern[i] == text[j]) {
                i++;
            }

            // 无论字符是否相等，text要继续走一步
            j++;
        }

        return i == pattern.size() ? true : false; // i走到pattern的长度，则pattern是text的子序列
    }
    int findLUSlength(vector<string>& strs) {
        // 定义变量保存结果
        int res = -1; // 没有满足条件的最长特征序列，则直接输出这个初始值，巧妙

        // 遍历字符串数组的每一个字符串
        for (int i = 0; i < strs.size(); i++) {
            bool check = true; // 标记当前遍历的字符串不是剩下别的字符串的子序列

            // 遍历剩下的字符串
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && isSubseq(strs[i], strs[j])) {
                    // 巧妙，遍历剩下的字符串，当前i字符串是j字符串的子序列

                    check = false; // 标记当前遍历的i字符串是某个字符串的子序列，则不是特殊序列了

                    break; // 退出现在的内层循环，继续下一个i字符串
                }
            }

            // 来到这儿，则当前遍历的i字符串是满足条件的字符串，接下来继续判断它是不是最长的
            // 上边一行注释是错的，来到这儿，则要根据check来判断它是否满足子序列的条件

            //if (strs[i].size() > res) { 一开始没有用到check，是错的
            if (check) {
                // res代表的长度，因此直接比较res

                //res = max(res, strs[i].size()); // 求出最长的长度，报错
                res = max(res, static_cast<int>(strs[i].size())); // 求出最长的长度
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> strs = {"aba", "cdc", "eae"};

    Solution s;
    int res = s.findLUSlength(strs);

    cout << res << endl;

    return 0;
}