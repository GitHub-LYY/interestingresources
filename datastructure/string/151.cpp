/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 151. 颠倒字符串中的单词
** link: https://leetcode.cn/problems/reverse-words-in-a-string/
** reference: 
*/

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 创建字符串流
        istringstream sin(s);

        // 定义变量保存结果
        string res;

        // 创建中间变量接收字符串
        string ans, word;

        // 把每个字符串逆序拼接
        while (sin >> word) {
            ans = " " + word + ans;
        }

        // 开始位置有一个空格，删除，复制到res
        res = ans.substr(1, ans.size() - 1);

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "the sky is blue";

    cout << "before reverse: " << s << endl;

    Solution sol;
    string res = sol.reverseWords(s);

    cout << "after reverse: " << res << endl;

    return 0;
}