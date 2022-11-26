/*
** Author: Yangyang Liu
** Date: 2022-11-26
** Description: 392. 判断子序列
** link: https://leetcode.cn/problems/is-subsequence/
** reference: 题解区，官方题解，方法一
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 定义i指针和j指针
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                // 相等，则i需要往后走了

                i++;
            }

            // 不论是否相等，j都需要往后走
            j++;
        }

        return i == s.size();
    }
};

int main(int argc, char** argv) {
    string s = "abc";
    string t = "ahbgdc";

    Solution sol;
    bool res = sol.isSubsequence(s, t);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}