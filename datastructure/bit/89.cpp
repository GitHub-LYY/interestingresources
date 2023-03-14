/*
** Author: Yangyang Liu
** Date: 2023-03-14
** Description: 89. 格雷编码
** link: https://leetcode.cn/problems/gray-code/
** reference: 题解区，官方题解，公式法
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n); // 数组有2^n次方个数，使用了位运算求次方

        for (int i = 0; i < res.size(); i++) {
            res[i] = (i >> 1) ^ i; // 直接用公式
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    vector<int> res = s.grayCode(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}