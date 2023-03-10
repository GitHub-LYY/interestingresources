/*
** Author: Yangyang Liu
** Date: 2023-03-10
** Description: 367. 有效的完全平方数
** link: https://leetcode.cn/problems/valid-perfect-square/
** reference: 题解区，官方题解，二分搜索
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;

            if (square < num) {
                left = mid + 1;
            } else if (square > num) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    int num = 16;

    Solution s;
    bool res = s.isPerfectSquare(num);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}