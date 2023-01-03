/*
** Author: Yangyang Liu
** Date: 2023-01-03
** Description: 633. 平方数之和
** link: https://leetcode.cn/problems/sum-of-square-numbers/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0; // 根据题目数值范围，使用long避免溢出
        long b = (int)sqrt(c); // int强制转换为整数赋值给b

        while (a <= b) { // a<b容易理解，a=b的例子考虑c=2
            long sum = a * a + b * b; // 求出两个数的平方和

            if (sum == c) { // 存在a和b两个整数满足平方和等于c
                return true;
            } else if (sum > c) {
                b--;
            } else if (sum < c) {
                a++;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    int c = 5;

    Solution s;
    bool res = s.judgeSquareSum(c);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}