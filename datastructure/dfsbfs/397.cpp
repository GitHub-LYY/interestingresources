/*
** Author: Yangyang Liu
** Date: 2023-02-22
** Description: 397. 整数替换
** link: https://leetcode.cn/problems/integer-replacement/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) { // 1，满足了，替换的次数是0次
            return 0;
        }

        if (n % 2 == 0) { // 偶数
            return 1 + integerReplacement(n / 2); // 偶数每次除以2
        }

        // 来到这儿，则是奇数
        return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)); // 奇数往上往下
    }
};

int main(int argc, char** argv) {
    int n = 8;

    Solution s;
    int res = s.integerReplacement(n);

    cout << res << endl;
    
    return 0;
}