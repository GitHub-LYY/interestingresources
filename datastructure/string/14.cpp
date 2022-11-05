/*
** Author: Yangyang Liu
** Date: 2022-11-05
** Description: 14. 最长公共前缀
** link: https://leetcode.cn/problems/longest-common-prefix/
** reference: 题解区，官方题解，方法二
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 如果字符串数组是空的，则前缀一定也是空的
        if (strs.size() == 0) {
            return "";
        }

        // 定义变量保存字符串数组的字符串的数量
        int numStrs = strs.size();

        // 定义变量保存第一个基准字符串的字符数量
        int len = strs[0].size();

        // 外循环遍历基准字符串的每一个字符，内循环遍历后边的所有的字符串
        for (int i = 0; i < len; i++) {
            // 取出基准字符串的当前字符
            char c = strs[0][i];

            for (int j = 1; j < numStrs; j++) { // 这儿的j从1开始
                if (strs[j][i] != c || strs[j].size() == i) {
                    // 第一个条件是当前的字符串的长度没有到头，则判断是否相等，如果不等，则此时取前缀了
                    // 第二个条件是当前的字符串的长度已经到头了，则后边的也没有遍历的必要了，该取前缀了

                    return strs[0].substr(0, i); // 0-i，不包含i，很巧妙
                }
            }
        }

        // 到这，则后边的字符串的长度是大于等于基准字符串的，即使后边的字符串更长，也没有必要继续判断了，基准字符串的长度是最长的前缀了
        return strs[0];
    }
};

int main(int argc, char** argv) {
    vector<string> strs = {"flower", "flow", "flight"};

    Solution s;
    string res = s.longestCommonPrefix(strs);

    cout << res << endl;

    return 0;
}