/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 504. 七进制数
** link: https://leetcode.cn/problems/base-7/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        // 如果num为0
        if (num == 0) {
            // 没有，则测试用例报错

            return "0";
        }
        
        // 定义变量保存结果
        string res;

        // 判断num正负号
        bool negative = num < 0;

        // 取绝对值来做
        num = abs(num);

        while (num) {
            // 核心

            res.push_back(num % 7 + '0'); // 转换为字符
            num /= 7;
        }

        if (negative) {
            res.push_back('-');
        } 

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 100;

    Solution s;
    string res = s.convertToBase7(num);

    cout << res << endl;

    return 0;
}