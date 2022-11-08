/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 242. 有效的字母异位词
** link: https://leetcode.cn/problems/valid-anagram/
** reference: 题解区，官方题解，哈希表解法，本题和383类似
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 本题需要先判断长度是否相等，不相等，则没有继续判断的必要了
        if (s.size() != t.size()) {
            return false;
        }
        
        // 使用vector数组作为哈希表
        vector<int> map(26);

        // 遍历s
        for (char ch : s) {
            map[ch - 'a']++;
        }

        // 遍历t
        for (char ch : t) {
            map[ch - 'a']--;

            if (map[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    string s = "anagram";
    string t = "nagaram";
    //s = "ab";
    //t = "a";

    Solution sol;
    bool res = sol.isAnagram(s, t);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}