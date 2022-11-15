/*
** Author: Yangyang Liu
** Date: 2022-11-15
** Description: 551. 学生出勤记录 I
** link: https://leetcode.cn/problems/student-attendance-record-i/
** reference: 自己的理解写的，错了，参考官方题解评论区，账号，Ziggy8n24
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        // 定义变量保存A和L的次数
        int numA = 0;
        int numL = 0;

        // 遍历字符串
        for (char c : s) {
            if (c == 'A') {
                numA++;
            }

            if (c == 'L') {
                numL++;
            } else {
                // 非常重要，不连续则置零，必须有

                numL = 0; // 这个求出连续的L的次数的重要的一步
            }

            if (numA > 1 || numL >= 3) {
                return false; // 不满足，则提前退出
            }
        }

        return true; // 来到这儿，则一定满足
    }
};

int main(int argc, char** argv) {
    string s = "PPALLP";

    Solution sol;
    bool res = sol.checkRecord(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}