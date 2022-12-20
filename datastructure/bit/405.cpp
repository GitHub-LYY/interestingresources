/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 405. 数字转换为十六进制数
** link: https://leetcode.cn/problems/convert-a-number-to-hexadecimal/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        // 异常
        if (num == 0) {
            return "0";
        }

        // 定义变量保存结果
        string res;

        for (int i = 7; i >= 0; i--) {
            // 每4位一组，共8组，从左往右

            int val = (num >> (4 * i)) & 0xf;

            if (res.size() > 0 || val > 0) {
                // 第一个条件，结果已经有插入了，不用在意此时插入的是否是小于等于0了
                // 第二个条件，第一个条件不满足的时候，在一开始，保证val从不等于0的数开始

                char digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10); // 转换为16进制数

                res.push_back(digit); // 插入
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 26;

    Solution s;
    string res = s.toHex(num);

    cout << res << endl;
    
    return 0;
}