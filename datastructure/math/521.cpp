/*
** Author: Yangyang Liu
** Date: 2022-11-28
** Description: 521. 最长特殊序列 Ⅰ
** link: https://leetcode.cn/problems/longest-uncommon-subsequence-i/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};

int main(int argc, char** argv) {
    string a = "aba";
    string b = "cdc";

    Solution s;
    int res = s.findLUSlength(a, b);

    cout << res << endl;
    
    return 0;
}