/*
** Author: Yangyang Liu
** Date: 2022-09-07
** Description: 剑指 Offer 20. 表示数值的字符串
** link: https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
** reference: https://www.bilibili.com/video/BV1bi4y1G7dz?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
*/

#include <iostream>

using namespace std;

class Solution {
private:
    void trim(string& s) {
        if (s.empty()) {
            return;
        }

        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
public:
    bool isNumber(string s) {
        // .之前不能出现.或者e
        // e之前不能出现e，且必须出现数字
        // +-出现在0位置或者e/E的后边第一个位置才是合法的

        bool seeNum = false;
        bool seeDot = false;
        bool seeE = false;

        trim(s);

        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            char c = s[i]; // 当前遍历的字符

            if (c >= '0' && c <= '9') {
                // 当前字符是数字

                seeNum = true;
            } else if (c == '.') {
                // 当前字符是.

                if (seeDot == true || seeE == true) {
                    return false;
                }

                seeDot = true;
            } else if (c == 'e') {
                if (seeE == true || seeNum == false) {
                    return false;
                }

                seeE = true;

                // 这儿需要看见num
                seeNum = false; // 例如，12e
            } else if (c == '-' || c == '+') {
                // 当前字符是+ -

                if (i != 0 && s[i - 1] != 'e') {
                    return false;
                }
            } else {
                // 出现的奇怪字符，测试用例没有的

                return false;
            }
        }

        return seeNum;
    }
};

int main(int argc, char** argv) {
    string s = "0";

    Solution sol;
    bool res = sol.isNumber(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}