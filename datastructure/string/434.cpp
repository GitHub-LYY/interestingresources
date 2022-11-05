/*
** Author: Yangyang Liu
** Date: 2022-11-05
** Description: 434. 字符串中的单词数
** link: https://leetcode.cn/problems/number-of-segments-in-a-string/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        // 如果字符串是空的，则单词数量是0
        if (s.size() == 0) {
            return 0;
        }

        // 定义变量保存单词的数量
        int count = 0;

        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                // 第一个条件是为了处理第一位和后边的每一位
                // 第二个条件是当前字符不空

                count++;
            }
        }

        return count;
    }
};

int main(int argc, char** argv) {
    string  s = "Hello, my name is John";

    Solution sol;
    int res = sol.countSegments(s);

    cout << res << endl;

    return 0;
}