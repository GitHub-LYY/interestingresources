/*
** Author: Yangyang Liu
** Date: 2023-01-10
** Description: 560. 和为 K 的子数组
** link: https://leetcode.cn/problems/subarray-sum-equals-k/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum2num; // 前缀和-出现次数哈希表
        int res = 0; // 初始化为0方便累加
        int preSum = 0;
        presum2num[0] = 1; // 这句不能少，仔细思考

        for (auto& num : nums) {
            preSum += num; // 求前缀和
            if (presum2num.count(preSum - k) > 0) { // presum[j-1]出现在哈希表中，要收割了
                res += presum2num[preSum - k]; // presum[j-1]有了，则也有和为k的数组
            }
            presum2num[preSum]++; // 填充哈希表
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution s;
    int res = s.subarraySum(nums, k);

    cout << res << endl;

    return 0;
}