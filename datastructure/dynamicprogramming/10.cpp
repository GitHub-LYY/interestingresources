/*
** Author: Yangyang Liu
** Date: 2022-09-03
** Description: 10. 正则表达式匹配
** link: https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/?favorite=xb9nqhhg
** reference: b站CSON，作者，EdwardShi，这道题说的特别好，我看了许多题解，没有理解，一看这个作者的，立即理解了，
** 搜索，【CSON】LeetCode千题讲解HOT热题100，
** 结合LeetCode第10题的题解，自己的理解，最终迭代除此版本
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // 如果s或者p为空，则一定不匹配
        //if (s.empty() || p.empty()) {
        //    return false;
        //}
        // 以上的判断空的不要有，否则LeetCode报错，这个困扰了我几天，LeetCode一直报错，

        // 定义dp数组，dp[i][j]表示s的下标i-1及其之前的字符串和p的j-1及其之前的字符串是否匹配
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));

        // dp数组初始化
        dp[0][0] = true; // 按现在dp数组的定义，这儿的初始化纯粹是为了推导dp数组

        // 处理一种特殊情况，如s="aab", p="c*aab"，c*为空的情况
        //for (int j = 1; j <= p.size(); j++) {
        //    if (p[j] == '*') {
        //        dp[0][j + 1] = dp[0][j - 1]; // dp[0][j + 1 - 2]容易理解
        //    }
        //}
        // 这个版本的for循环容易理解一点，p的索引不能取到p.size()
        for (int j = 1; j <= p.size(); j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // 这个状态是为*位置的状态，不是*后边的状态
            }
        }

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                // 第一大类情况
                if (s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                if (p[j - 1] == '.') {
                    // 第二大类情况

                    dp[i][j] = dp[i - 1][j - 1];
                }

                if (p[j - 1] == '*') {
                    // 第三大类情况

                    // 第三类情况的第一类情况
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') { // && 的条件必须有
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    } else {
                        // 第三类情况的第二类情况，又分为三种情况，合在一块

                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};

int main(int argc, char** argv) {
    string s = "aab";
    string p = "c*a*b";

    Solution sol;
    bool res = sol.isMatch(s, p);

    cout << res << endl;

    return 0;
}