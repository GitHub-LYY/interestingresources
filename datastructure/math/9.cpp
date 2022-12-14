/*
** Author: Yangyang Liu
** Date: 2022-12-14
** Description: 9. 回文数
** link: https://leetcode.cn/problems/palindrome-number/
** reference: 题解区，官方题解，忍者算法，最终，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // 1、x是负数，false
        // 2、x是正数但是个位数是0，false
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        // 定义变量保存x的一半数字的翻转
        int reverseNum = 0;

        // 翻转一半数字
        while (x > reverseNum) {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return x == reverseNum || x == reverseNum / 10;
    }
};

int main(int argc, char** argv) {
    int x = 121;

    Solution s;
    bool res = s.isPalindrome(x);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}