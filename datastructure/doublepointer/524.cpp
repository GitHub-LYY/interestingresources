/*
** Author: Yangyang Liu
** Date: 2022-11-28
** Description: 524. 通过删除字母匹配到字典里最长单词
** link: https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/
** reference: 题解区，先阅读的微扰的题解，后来又阅读了官方题解，发现官方的写的更好理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 定义变量保存结果
        string res;

        // 遍历dictionary数组的字符串
        for (auto str : dictionary) {
            // 子序列的题，定义两个指针指向文本串和模式串
            int i = 0; // 指针指向文本串
            int j = 0; // 指针指向模式串

            // 子序列经典循环
            while (i < s.size() && j < str.size()) {
                if (s[i] == str[j]) {
                    // 相等，则模式串指针走一步

                    j++;
                }

                // 不论哪种情况，文本串的指针都需要走一步
                i++;
            }

            // 循环结束，该第二步了，判断长度是否更长，或者长度相等但是字典序更小
            if (j == str.size()) {
                // 相等，则是一个子序列

                if (str.size() > res.size() || (str.size() == res.size() && str < res)) {
                    // 两个条件任一满足，则是符合条件的结果

                    res = str;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "abpcplea";
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};

    Solution sol;
    string res = sol.findLongestWord(s, dictionary);

    cout << res << endl;

    return 0;
}