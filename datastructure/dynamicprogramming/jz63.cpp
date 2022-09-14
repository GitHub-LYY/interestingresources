/*
** Author: Yangyang Liu
** Date: 2022-09-14
** Description: 剑指 Offer 63. 股票的最大利润
** link: https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) { // 必须有，否则LeetCode报错
            return 0;
        }

        // dp数组定义
        vector<vector<int>> dp(prices.size(), vector<int>(2));

        // dp数组初始化
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};

int main(int argc,char** argv) {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution s;
    int res = s.maxProfit(prices);

    cout << res << endl;

    return 0;
}