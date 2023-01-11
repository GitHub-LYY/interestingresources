/*
** Author: Yangyang Liu
** Date: 2023-01-11
** Description: 525. 连续数组
** link: https://leetcode.cn/problems/contiguous-array/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0; // 定义变量保存最长的长度
        unordered_map<int, int> presum2index; // 前缀和-索引哈希表
        presum2index[0] = -1; // 人为在0之前的-1位置插入前缀和0
        int counter = 0; // 0转换为-1，求前缀和

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) { // 要么是0，要么是1
                counter++; // 是1，则前缀和++
            } else {
                counter--; // 此时是0，当做-1，前缀和要--
            }

            if (presum2index.count(counter) > 0) {
                int preIndex = presum2index[counter]; // 求出最早相等前缀和出现的位置
                maxLen = max(maxLen, i - preIndex); // i-preIndex是满足条件的子数组的长度
            } else {
                presum2index[counter] = i; // 填充哈希表
            }
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {0, 1};

    Solution s;
    int res = s.findMaxLength(nums);

    cout << res << endl;

    return 0;
}