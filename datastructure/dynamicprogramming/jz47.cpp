/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 47. 礼物的最大价值
** link: https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
** reference: 题解区，搜索，面试题47. 礼物的最大价值（动态规划，清晰图解），评论区，作者，Sumail的答案比题解的更简单
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        // 定义dp数组
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1));

        // dp数组初始化隐藏在上边了

        for (int i = 1; i <= grid.size(); i++) {
            for (int j = 1; j <= grid[0].size(); j++) { // i错写为j了，报段错误
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[grid.size()][grid[0].size()];
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    int res = s.maxValue(grid);

    cout << res << endl;

    return 0;
}