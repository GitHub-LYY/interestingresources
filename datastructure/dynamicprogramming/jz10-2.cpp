/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 10- II. 青蛙跳台阶问题
** link: https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
** reference: 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n < 1) {
            return 1;
        }

        // 定义dp数组
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }

        return dp[n] % 1000000007;
    }
};

int main(int argc, char** argv) {
    int n = 2;
    
    Solution s;
    int res = s.numWays(n);

    cout << "res : " << res << endl;

    return 0;
}