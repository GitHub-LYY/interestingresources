/*
** Author: Yangyang Liu
** Date: 2022-12-28
** Description: 507. 完美数
** link: https://leetcode.cn/problems/perfect-number/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        // 异常
        if (num == 1) {
            return false; // 1一定不满足
        }

        // 定义变量保存求和
        int sum = 1;

        // 从2开始遍历
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                // 因子判断条件

                sum += d; // 收割一

                if (d * d < num) {
                    sum += num / d; // 收割二
                }
            }
        }

        return sum == num;
    }
};

int main(int argc, char** argv) {
    int num = 28;

    Solution s;
    bool res = s.checkPerfectNumber(num);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}