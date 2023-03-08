/*
** Author: Yangyang Liu
** Date: 2023-03-08
** Description: 278. 第一个错误的版本
** link: https://leetcode.cn/problems/first-bad-version/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
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