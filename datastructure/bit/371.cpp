/*
** Author: Yangyang Liu
** Date: 2023-03-15
** Description: 371. 两整数之和
** link: https://leetcode.cn/problems/sum-of-two-integers/
** reference: 官方题解不理解，先记忆
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

int main(int argc, char** argv) {
    int a = 1;
    int b = 2;

    Solution s;
    int res = s.getSum(a, b);

    cout << res << endl;

    return 0;
}