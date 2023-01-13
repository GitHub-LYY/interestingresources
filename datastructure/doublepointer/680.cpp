/*
** Author: Yangyang Liu
** Date: 2023-01-13
** Description: 680. 验证回文串 II
** link: https://leetcode.cn/problems/valid-palindrome-ii/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        for (int ii = i, jj = j; ii < jj; ii++, jj--) {
            if (s[ii] != s[jj]) { // 只要有一个位置的不相等，则一定不是回文串
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0; // 定义左指针
        int right = s.size() - 1; // 定义右指针

        while (left < right) { // 双指针经典循环
            if (s[left] == s[right]) { /// left和right位置的字符相等，则继续左移右移
                left++;
                right--;
            } else {
                return checkPalindrome(s, left + 1, right) | checkPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    string s = "aba";

    Solution sol;
    bool res = sol.validPalindrome(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}