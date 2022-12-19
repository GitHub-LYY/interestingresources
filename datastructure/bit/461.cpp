/*
** Author: Yangyang Liu
** Date: 2022-12-19
** Description: 461. 汉明距离
** link: https://leetcode.cn/problems/hamming-distance/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y); // 求异或后的二进制位的1的个数
    }
};

int main(int argc, char** argv) {
    int x = 1;
    int y = 4;

    Solution s;
    int res = s.hammingDistance(x, y);

    cout << res << endl;
    
    return 0;
}