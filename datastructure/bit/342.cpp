/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 342. 4的幂
** link: https://leetcode.cn/problems/power-of-four/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};

int main(int argc, char** argv) {
    int n = 16;

    Solution s;
    bool res = s.isPowerOfFour(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}