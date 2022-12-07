/*
** Author: Yangyang Liu
** Date: 2022-12-07
** Description: 6. Z 字形变换
** link: https://leetcode.cn/problems/zigzag-conversion/
** reference: 题解区，搜索，【【忍者算法】超清晰易懂白板图解+代码编写
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // 异常处理
        if (numRows == 1) {
            return s; // 一开始没有异常处理，测试用例报错了
        }

        // 定义字符串数组
        vector<string> strVec(numRows); // 一开始忘记写numRows了，报错，segmentation fault

        // 求出每一个组的字符的个数
        int period = numRows * 2 - 2;

        // 遍历s
        for (int i = 0; i < s.size(); i++) {
            int mod = i % period; // 取模
            if (mod < numRows) {
                strVec[mod] += s[i];
            } else {
                strVec[period - mod] += s[i];
            }
        }

        // 定义变量保存结果
        string res;
        // 遍历字符串数组，求出结果
        for (auto str : strVec) {
            res += str;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution sol;
    string res = sol.convert(s, numRows);

    cout << res << endl;

    return 0;
}