/*
** Author: Yangyang Liu
** Date: 2023-01-11
** Description: 523. 连续的子数组和
** link: https://leetcode.cn/problems/continuous-subarray-sum/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) { // 长度小于2一定不满足
            return false;
        }

        unordered_map<int, int> remainder2index; // 余数-索引哈希表
        remainder2index[0] = -1; // 一开始忘记了，测试用例23,2,4,6,6,k=7，错的，人为在23前边加个0，索引是-1
        int remainder = 0; // 余数

        for (int i = 0; i < nums.size(); i++) {
            remainder = (remainder + nums[i]) % k; // 求出每个位置的余数
            if (remainder2index.count(remainder) > 0) { // 余数出现在哈希表中，意味着此时可能出现一个子数组满足要求了，要判断长度是否满足
                int preIndex = remainder2index[remainder]; // 求出最早的相等的余数出现的位置方便求子数组的长度
                if (i - preIndex >= 2) { // i-preIndex是子数组的长度
                    return true; // 有一个满足已经满足题意了
                }
            } else {
                remainder2index[remainder] = i; // 填充哈希表，必须在else中，防止出现5,0,0,0的情况
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    //vector<int> nums = {23, 2, 4, 6, 7};
    //int k = 6;
    vector<int> nums = {23, 2, 4, 6, 6};
    int k = 7;

    Solution s;
    bool res = s.checkSubarraySum(nums, k);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}