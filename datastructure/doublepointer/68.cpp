/*
** Author: Yangyang Liu
** Date: 2022-12-11
** Description: 68. 文本左右对齐
** link: https://leetcode.cn/problems/text-justification/
** reference: 题解区，官方题解，仔细思考
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string join(vector<string>& words, int left, int right, string sToInsert) {
        // 定义变量保存left位置的字符串方便后边做拼接
        string res = words[left];

        for (int i = left + 1; i < right; i++) {
            // 不包括right

            res += sToInsert + words[i]; // 单词之间是sToInsert字符串
        }

        return res;
    }

    string blank(int num) {
        // 生成多少个空格

        return string(num, ' ');
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 定义变量保存结果
        vector<string> res;

        // 定义right指针，往右走
        int right = 0;

        // 定义words的字符串的个数，后边不用写的很长
        int n = words.size();

        // 无限循环
        while (true) {
            // 定义左指针，右指针开始走了
            int left = right;

            // 定义变量保存遍历的单词的长度之和
            int sumLen = 0;

            while (right < n && sumLen + words[right].size() + right - left <= maxWidth) {
                // 两个条件
                // 一，right没有越界
                // 二，单词长度和之间的空格（最少一个空格）没有超出长度

                sumLen += words[right++].size(); // ++ 很重要
            }

            // 是否越界了
            if (right == n) {
                // 到了边界了
                // 这个条件是说到了words中的最后一个单词了

                string sTmp = join(words, left, n, " "); // 单词之间空一个空格
                sTmp += blank(maxWidth - sTmp.size()); // 后边填充空格，一开始写为了-sumLen，错的
                res.push_back(sTmp); // 最后一个字符串插入结果
                return res; // 这是最后一个了，因此在这儿输出
            }

            // 来到这儿，则没有越界，是第二个条件打破了
            // 求出单词数量
            int numWords = right - left; // 左闭右开
            // 求出有多少个空格
            int numSpaces = maxWidth - sumLen; // sumLen有用了

            // 当前行仅仅有一个单词
            if (numWords == 1) {
                // 单词左对齐，剩下填充空格

                string sTmp = words[left]; // 一个单词一定是left位置的
                sTmp += blank(numSpaces); // 后边全部是空格，一开始写的是相减，而已经这个变量了
                res.push_back(sTmp);
                continue; // 一开始忘写了，错的
            }

            // 当前行有多个单词
            int avgSpaces = numSpaces / (numWords - 1); // 仔细思考，单词之间平均的空格数量
            int extraSpaces = numSpaces % (numWords - 1); // 多出来的空格数量
            string sTmp1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1)); // 这些单词之间比平均空格数量多一
            string sTmp2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces)); // 后边的插入平均空格数量
            string sTmp = sTmp1 + blank(avgSpaces) + sTmp2;
            res.push_back(sTmp);
        }
    }
};

int main(int argc, char** argv) {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    Solution sol;
    vector<string> res = sol.fullJustify(words, maxWidth);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}