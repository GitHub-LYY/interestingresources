/*
** Author: Yangyang Liu
** Date: 2023-03-20
** Description: 386. 字典序排数
** link: https://leetcode.cn/problems/lexicographical-numbers/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n); // 结果长度是n
        int number = 1; // 从1开始

        for (int i = 0; i < n; i++) {
            res[i] = number; // number赋值res

            if (number * 10 <= n) { // 第一个条件，满足，则是下一个数
                number *= 10;
            } else { // 第二个条件
                while (number % 10 == 9 || number + 1 > n) { // 第二个条件，意味着此时的数是最后一个数，要往前一位走
                    number /= 10;
                }

                number++; // 不断多一
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 13;

    Solution s;
    vector<int> res = s.lexicalOrder(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}