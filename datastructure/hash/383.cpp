/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 383. 赎金信
** link: https://leetcode.cn/problems/ransom-note/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 使用数组作为哈希表
        vector<int> map(26); // 只需要保存26个小写字母的value

        // 先遍历magazine求出哈希表
        for (char ch : magazine) {
            map[ch - 'a']++; // 使用vector数组做哈希表的写法，和传统的数组有区别，要习惯这种方式
        }

        // 遍历randomNote
        for (char ch : ransomNote) {
            // 先把哈希表对应的次数减去一
            map[ch - 'a']--;

            // 如果次数小于0，则一定不满足
            if (map[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    string ransomNote = "a";
    string magazine = "b";

    Solution s;
    bool res = s.canConstruct(ransomNote, magazine);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}