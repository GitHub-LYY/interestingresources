/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 221. 最大正方形
** link: https://leetcode.cn/problems/maximal-square/
** reference: 题解区，搜索，动态规划（C++），作者，zjwreal
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 定义dp数组
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        // 定义最大边长用来计算结果
        int maxSide = 0;

        // dp数组初始化
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]); // 必须在这更新，否则报错
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }

        // 遍历dp数组
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    // 0的情况什么也不用做，因为已经初始化为0了，这点比较妙

                    dp[i][j] = min(min(dp[i- 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; // min有两个参数，有三个报错
                }

                maxSide = max(maxSide, dp[i][j]); // 每遍历一个位置，都要更新一下最大边长
            }
        }

        return maxSide * maxSide;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution s;
    int res = s.maximalSquare(matrix);

    cout << "square is " << res << endl;

    return 0;
}