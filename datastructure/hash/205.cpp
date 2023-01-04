/*
** Author: Yangyang Liu
** Date: 2023-01-04
** Description: 205. 同构字符串
** link: https://leetcode.cn/problems/isomorphic-strings/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t; // s中字符-t中字符的映射
        unordered_map<char, char> t2s; // t中字符-s中字符的映射

        for (int i = 0; i < s.size(); i++) { // 遍历第一个字符串
            int x = s[i];
            int y = t[i];

            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) { // 不满足一一映射
                return false;
            }

            s2t[x] = y;
            t2s[y] = x;
        }

        return true;
    }
};

int main(int argc, char** argv) {
    string s = "egg";
    string t = "add";

    Solution sol;
    bool res = sol.isIsomorphic(s, t);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}