/*
** Author: Yangyang Liu
** Date: 2022-12-19
** Description: 693. 交替位二进制数
** link: https://leetcode.cn/problems/binary-number-with-alternating-bits/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1); // a是long
        return (a & (a + 1)) == 0; // 括号必须有
    }
};

int main(int argc, char** argv) {
    int n = 5;

    Solution s;
    bool res = s.hasAlternatingBits(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}