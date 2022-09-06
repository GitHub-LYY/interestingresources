/*
** Author: Yangyang Liu
** Date: 2022-09-06
** Description: 剑指 Offer 14- II. 剪绳子 II
** link: https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1DB4y1e7Z3?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站视频提到了说数据范围扩大使用动态规划不行，使用贪心
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRopeDP(int n) {
        // 定义dp数组
        vector<int> dp(n + 1);

        // dp数组初始化
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n] % 1000000007;
    }

    int cuttingRope(int n) {
        // 本题使用14-1的动态规划不行，数据范围扩大了，使用贪心

        // 贪心的地方在不断分解为3相乘

        if (n < 4) {
            // 2->1,3->2

            return n - 1;
        }

        // 定义long long类型的结果
        long long res = 1;

        // 定义模数
        int mod = 1e9+7;

        // n大于4则不断循环贪心
        while (n > 4) { // 没有等于4的情况
            res = res * 3 % mod;
            n = n - 3;
        }

        return int(res * n % mod);
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    int res = s.cuttingRope(n);

    cout << res << endl;

    return 0;
}