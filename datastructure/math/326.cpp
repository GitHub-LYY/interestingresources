/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 326. 3 的幂
** link: https://leetcode.cn/problems/power-of-three/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

int main(int argc, char** argv) {
    int n = 27;

    Solution s;
    bool res = s.isPowerOfThree(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}