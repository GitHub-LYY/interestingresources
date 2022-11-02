/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 541. 反转字符串 II
** link: https://leetcode.cn/problems/reverse-string-ii/
** reference: 代码随想录
** 20221102，自己隔了几个月再次做，自己解决了bug，也有了自己的理解，写了现在的版本
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Soluton {
public:
    string reverseStrOld(string s, int k) {
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

    string reverseStr(string s, int k) {
        // 每次走2k个字符
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) {
                // i + k没有越界，则翻转i到i+k

                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // i + k越界了，则翻转i到末尾

                reverse(s.begin() + i, s.end());
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