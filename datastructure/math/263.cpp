/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 263. 丑数
** link: https://leetcode.cn/problems/ugly-number/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // 如果n不是正数，则一定不是丑数
        if (n <= 0) {
            return false;
        }

        // 定义因子数组
        vector<int> factors = {2, 3, 5};

        for (int factor : factors) {
            while (n % factor == 0) {
                // 能除尽因子，则整除

                n /= factor;
            }
        }

        return n == 1;
    }
};

int main(int argc, char** argv) {
    int n = 6;

    Solution s;
    bool res = s.isUgly(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}