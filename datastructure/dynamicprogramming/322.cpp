/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 322. 零钱兑换
** link: https://leetcode.cn/problems/coin-change/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 定义dp数组
        vector<int> dp(amount + 1, INT_MAX);    

        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main(int argc, char** argv) {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution s;
    int res = s.coinChange(coins, amount);

    cout << res << endl;

    return 0;
}