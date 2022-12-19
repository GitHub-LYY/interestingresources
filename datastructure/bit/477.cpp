/*
** Author: Yangyang Liu
** Date: 2022-12-19
** Description: 477. 汉明距离总和
** link: https://leetcode.cn/problems/total-hamming-distance/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // 定义变量保存结果
        int res = 0;

        for (int i = 0; i < 30; i++) {
            // 0-29

            int numOne = 0;

            for (int num : nums) {
                numOne += (num >> i) & 1; // 求当前位是1的数的数量
            }

            res += numOne * (nums.size() - numOne); // 计算公式
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 14, 2};

    Solution s;
    int res = s.totalHammingDistance(nums);

    cout << res << endl;

    return 0;
}