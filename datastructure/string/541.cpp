/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 541. 反转字符串 II
** link: https://leetcode.cn/problems/reverse-string-ii/
** reference: 
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Soluton {
public:
    string reverseStr(string s, int k) {
        // 每隔2k个字符，去判断是否翻转
        for (int i = 0; i < s.size(); i += 2 * k) {
            // 1、每隔2k个字符，翻转
            // 2、剩下字符在[k, 2k]之间，翻转
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else { // 3、剩下字符小于k个，剩下的字符全部翻转
                reverse(s.begin() + i, s.begin() + s.size());
            }
        }
        
        return s;
    }
};

int main(int argc, char** argv) {
    string s = "abcdefg";
    int k = 2;

    cout << "before reverse: " << s << endl;

    Soluton sol;
    string res = sol.reverseStr(s, k);

    cout << "after reverse: " << res << endl;

    return 0;
}