/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 191. 位1的个数
** link: https://leetcode.cn/problems/number-of-1-bits/
** reference: 题解区，官方题解，方法一
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 计数器保存二进制1的个数
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                // 很巧妙，1每次移动i位

                count++; // 进入这儿了，则当前位是1
            }
        }

        return count;
    }
};

int main(int argc, char** argv) {
    uint32_t n = 11;

    Solution s;
    int res = s.hammingWeight(n);

    cout << res << endl;
    
    return 0;
}