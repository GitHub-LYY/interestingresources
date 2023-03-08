/*
** Author: Yangyang Liu
** Date: 2023-03-08
** Description: 374. 猜数字大小
** link: https://leetcode.cn/problems/guess-number-higher-or-lower/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int guess(int num) {

    }
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    return 0;
}