/*
** Author: Yangyang Liu
** Date: 2022-09-04
** Description: 343. 整数拆分
** link: https://leetcode.cn/problems/integer-break/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // 定义dp数组
        vector<int> dp(n + 1);

        // dp数组初始化
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    int res = s.integerBreak(n);

    cout << res << endl;

    return 0;
}