/*
** Author: Yangyang Liu
** Date: 2022-11-02
** Description: 125. 验证回文串
** link: https://leetcode.cn/problems/valid-palindrome/
** reference: 官方题解，方法二，空间复杂度为O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 定义左，右指针
        int left = 0;
        int right = s.size() - 1;

        // 双指针经典循环
        while (left < right) {
            // 别急着走，先判断是否符合比较的条件，再去比较

            while (left < right && !isalnum(s[left])) {
                left++; // 没法比，往下一个位置走，直到满足比较的条件
            }

            while (left < right && !isalnum(s[right])) {
                right--; // 没法比，往下一个位置走，直到满足比较的条件
            }

            if (left < right) {
                // 必须有这个if条件，因为上边在走，这必须要判断

                if (tolower(s[left]) != tolower(s[right])) {
                    return false; // 左右小写不相等，则false
                }

                // 来到这儿，则左右小写相等，满足回文，继续移动左右指针往下一个位置走
                left++;
                right--;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    string s = "A man, a plan, a canal: Panama";

    Solution sol;
    bool res = sol.isPalindrome(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}