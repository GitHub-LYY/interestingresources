/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 258. 各位相加
** link: https://leetcode.cn/problems/add-digits/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // 定义变量保存结果
        int res = num;

        while (res >= 10) {
            // 不是一位数

            int sum = 0;
            while (res > 0) {
                // 有位没有取完

                sum += res % 10; // 取最后一位数

                res /= 10;
            }

            res = sum;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 38;

    Solution s;
    int res = s.addDigits(num);

    cout << res << endl;
    
    return 0;
}