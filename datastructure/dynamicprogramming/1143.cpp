/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 1143. 最长公共子序列
** link: https://leetcode.cn/problems/longest-common-subsequence/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 定义变量保存字符串的长度
        int m = text1.size();
        int n = text2.size();

        // 定义dp数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char** argv) {
    string text1 = "abcde";
    string text2 = "ace";

    Solution s;
    int res = s.longestCommonSubsequence(text1, text2);

    cout << res << endl;

    return 0;
}