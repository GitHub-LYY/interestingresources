/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 62. 不同路径
** link: https://leetcode.cn/problems/unique-paths/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 初始化dp[i][0]=1
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // 初始化dp[0][j]=1
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m -1][n - 1];
    }
};

int main(int argc, char** argv) {
    int m = 3;
    int n = 7;

    Solution s;
    int res = s.uniquePaths(m, n);

    cout << "res:" << res << endl;

    return 0;
}