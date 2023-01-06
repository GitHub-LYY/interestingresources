/*
** Author: Yangyang Liu
** Date: 2023-01-06
** Description: 1. 两数之和
** link: https://leetcode.cn/problems/two-sum/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2index; // 数字-索引哈希表
        for (int i = 0; i < nums.size(); i++) {
            auto it = num2index.find(target - nums[i]);
            if (it != num2index.end()) { // 哈希表中存在target-nums[i]
                return {it->second, i}; // 输出两个数字的下标
            }
            num2index[nums[i]] = i; // 数据插入哈希表
        }

        return {};
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> res = s.twoSum(nums, target);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}