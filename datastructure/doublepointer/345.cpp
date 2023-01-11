/*
** Author: Yangyang Liu
** Date: 2023-01-11
** Description: 345. 反转字符串中的元音字母
** link: https://leetcode.cn/problems/reverse-vowels-of-a-string/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiouAEIOU"; // 定义原因字母，包括大小写

        if (vowels.find(ch) == string::npos) {
            return false;
        } else {
            return true;
        }
    }
    string reverseVowels(string s) {
        int left = 0; // 头指针
        int right = s.size() - 1; // 尾指针

        while (left < right) { // left不能等于right，这是退出的标志
            while (left < s.size() && !isVowel(s[left])) { // 当前left位置的字符不是元音字母
                left++; // 不是元音，右移
            }
            while (right > 0 && !isVowel(s[right])) { // 当前right位置的字符不是元音字母
                right--; // 不是元音，左移
            }

            if (left < right) { // 来到这儿，则left位置和right位置的字符是元音，此时又满足left在right左边
                swap(s[left], s[right]); // 交换
                left++; // 到下一个位置
                right--; // 也到下一个位置
            }
        }

        return s;
    }
};

int main(int argc, char** argv) {
    //string s = "hello";
    string s = "a.b,.";

    Solution sol;
    string res = sol.reverseVowels(s);

    cout << res << endl;

    return 0;
}