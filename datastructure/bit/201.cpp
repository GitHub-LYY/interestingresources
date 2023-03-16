/*
** Author: Yangyang Liu
** Date: 2023-03-16
** Description: 201. 数字范围按位与
** link: https://leetcode.cn/problems/bitwise-and-of-numbers-range/
** reference: 官方题解，方法一
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0; // 右移次数

        while (left < right) { // 右移到二者相等为止
            left >>= 1;
            right >>= 1;
            shift++; 
        }

        return left << shift;
    }
};

int main(int argc, char** argv) {
    int left = 5;
    int right = 7;

    Solution s;
    int res = s.rangeBitwiseAnd(left, right);

    cout << res << endl;
    
    return 0;
}