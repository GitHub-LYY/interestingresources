/*
** Author: Yangyang Liu
** Date: 2022-12-16
** Description: 476. 数字的补数
** link: https://leetcode.cn/problems/number-complement/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // 定义索引保存最高位的1的位置
        int highbit = 0;

        for (int i = 0; i <= 30; i++) {
            if (num >= (1 << i)) {
                highbit = i;
            } else {
                break; // 这退出循环，求出最高位的索引位置了
            }
        }

        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1); // 仔细思考，最外边的两个括号一开始忘写了

        return num ^ mask; // 异或巧妙
    }
};

int main(int argc, char** argv) {
    int num = 5;

    Solution s;
    int res = s.findComplement(num);

    cout << res << endl;

    return 0;
}