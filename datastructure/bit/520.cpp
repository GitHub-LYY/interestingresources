/*
** Author: Yangyang Liu
** Date: 2022-11-02
** Description: 520. 检测大写字母
** link: https://leetcode.cn/problems/detect-capital/
** reference: 官方题解
** key point：一，如果第一个字母是小写，第二个字母是否是小写，二，从第3个字母开始，全部和第2个字母大小写相等才true
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // 第一，如果第一个字母是小写，第二个字母是大写，则false
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }

        // 来到这儿，则第二个条件

        // 不论第一个字母大小写，从第三个字母开始，如果有和第二个字母大小写不一致，则false
        for (int i = 2; i < word.size(); i++) {
            if (islower(word[i]) ^ islower(word[1])) {
                return false;
            }
        }

        // 来到这儿，满足条件
        return true;
    }
};

int main(int argc, char** argv) {
    string word = "USA";

    Solution s;
    bool res = s.detectCapitalUse(word);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}