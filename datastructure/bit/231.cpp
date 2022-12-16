/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 231. 2 的幂
** link: https://leetcode.cn/problems/power-of-two/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main(int argc, char** argv) {
    int n = 1;

    Solution s;
    bool res = s.isPowerOfTwo(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}