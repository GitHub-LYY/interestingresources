/*
** Author: Yangyang Liu
** Date: 2023-03-10
** Description: 69. x 的平方根 
** link: https://leetcode.cn/problems/sqrtx/
** reference: 题解区，官方题解，二分搜索
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;

            if (square <= x) {
                res = mid; // 必须写这种形式
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int x = 4;

    Solution s;
    int res = s.mySqrt(x);

    cout << res << endl;
    
    return 0;
}