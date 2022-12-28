/*
** Author: Yangyang Liu
** Date: 2022-12-28
** Description: 372. 超级次方
** link: https://leetcode.cn/problems/super-pow/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int MOD = 1337;
public:
    int pow(int x, int y) {
        int res = 1;

        while (y > 0) {
            if (y % 2 == 1) {
                // N的二进制的当前位是1，需要多乘以个x_contri

                res = (long) res * x % MOD;
            }

            // 整除求平方
            x = (long) x * x % MOD;

            // N右移一位
            y /= 2;
        }

        return res;
    }
    int superPow(int a, vector<int>& b) {
        int res = 1; // 不断累乘，因此初始化为1

        for (int i = b.size() - 1; i >= 0; i--) {
            // 这是逆序遍历b数组，很巧妙，下边求a的10的k次方

            res = (long) res * pow(a, b[i]) % MOD; // 别忘了取模

            a = pow(a, 10); // 这句很巧妙，从后遍历，仔细思考，记忆
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int a = 2;
    vector<int> b = {3};

    Solution s;
    int res = s.superPow(a, b);

    cout << res << endl;

    return 0;
}