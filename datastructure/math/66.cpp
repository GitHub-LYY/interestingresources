/*
** Author: Yangyang Liu
** Date: 2022-11-29
** Description: 66. 加一
** link: https://leetcode.cn/problems/plus-one/
** reference: 题解区，官方题解，评论区说官方题解写的复杂了，我觉得写的很好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 逆序遍历数组
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                // 当前数字不是9

                digits[i]++; // 加一操作

                for (int j = i + 1; j < digits.size(); j++) {
                    // 巧妙，后边全部置为0

                    digits[j] = 0;
                }

                return digits; // 这满足了直接输出了
            }
        }

        // 来到这儿，则是第三种情况，数组全部是9
        vector<int> res(digits.size() + 1); // 初始化为0
        res[0] = 1; // 第一个是0
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> digits = {1, 2, 3};

    Solution s;
    vector<int> res = s.plusOne(digits);

    for (int i = 0; i < res.size(); i++) {
        cout << res [i] << " ";
    }

    return 0;
}