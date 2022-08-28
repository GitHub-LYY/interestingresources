/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 10- I. 斐波那契数列
** link: https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        // 定义dp数组
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007; // 这个地方记得mod
        }

        return (dp[n] % 1000000007); // 这个地方记得mod
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    int res = s.fib(n);

    cout << "res :" << res << endl;

    return 0;
}