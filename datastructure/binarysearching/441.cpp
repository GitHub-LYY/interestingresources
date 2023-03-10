/*
** Author: Yangyang Liu
** Date: 2023-03-10
** Description: 441. 排列硬币
** link: https://leetcode.cn/problems/arranging-coins/
** reference: 题解区，官方题解，二分搜索
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if ((long long) mid * (mid + 1) <= (long long) 2 * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    int n = 5;

    Solution s;
    int res = s.arrangeCoins(n);

    cout << res << endl;

    return 0;
}