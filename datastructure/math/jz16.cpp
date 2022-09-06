/*
** Author: Yangyang Liu
** Date: 2022-09-06
** Description: 剑指 Offer 16. 数值的整数次方
** link: https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
private:
    double quickMul(double x, long long N) {
        // 定义变量保存结果
        double res = 1.0;

        // 定义x的贡献，它不断做x的平方操作
        double xContri = x;
        
        // N每个循环右移一位，移到最后为0
        while (N > 0) {
            if (N % 2 == 1) {
                // N % 2 == 1意思从位运算角度，是代表N的最后一个二进制位位1

                // 这一位是1，则到了收割的时候了
                res *= xContri;
            }

            // 平时不到收割的时候一直做平方操作
            xContri *= xContri;

            // 每次循环N右移一位
            N /= 2; // 也能写位N >>= 1;
        }

        return res;
    }
public:
    double myPow(double x, int n) {
        // 使用long long再保存一次n
        long long N = n;

        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N); // n有正负
    }
};

int main(int argc, char** argv) {
    double x = 2.0;
    int n = 10;

    Solution s;
    double res = s.myPow(x, n);

    cout << res << endl;
    
    return 0;
}