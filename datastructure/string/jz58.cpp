/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 剑指 Offer 58 - II. 左旋转字符串
** link: https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
** reference: 
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        // 先全部翻转
        reverse(s.begin(), s.end());

        // 翻转前k个字符
        reverse(s.begin(), s.begin() + s.size() - k);

        // 翻转后面的字符
        reverse(s.begin() + s.size() - k, s.end());

        return s;
    }
};

int main(int argc, char** argv) {
    string s = "abcdefg";
    int k = 2;

    cout << "before reverse: " << s << endl;

    Solution sol;
    string res = sol.reverseLeftWords(s, k);

    cout << "after reverse: " << res << endl;
    
    return 0;
}