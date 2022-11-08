/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 387. 字符串中的第一个唯一字符
** link: https://leetcode.cn/problems/first-unique-character-in-a-string/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // 定义哈希表
        unordered_map<char, int> freq;

        // 第一次遍历字符串
        for (char ch : s) {
            freq[ch]++;
        }

        // 第二次遍历字符串
        for (int i = 0; i < s.size(); i++) {
            // 这不能使用上边的形式，这需要使用索引

            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    string s = "leetcode";

    Solution sol;
    int res = sol.firstUniqChar(s);

    cout << res << endl;

    return 0;
}