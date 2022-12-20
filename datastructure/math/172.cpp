/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 172. 阶乘后的零
** link: https://leetcode.cn/problems/factorial-trailing-zeroes/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // 定义变量保存结果
        int res = 0;

        for (int i = 5; i <= n; i += 5) {
            // 以5位单位遍历

            for (int j = i; j % 5 == 0; j /= 5) {
                res++;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    int res = s.trailingZeroes(n);

    cout << res << endl;
    
    return 0;
}