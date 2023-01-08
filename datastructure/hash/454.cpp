/*
** Author: Yangyang Liu
** Date: 2023-01-08
** Description: 454. 四数相加 II
** link: https://leetcode.cn/problems/4sum-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> num2num; // 数值和-出现次数哈希表

        for (auto a : nums1) {
            for (auto b : nums2) {
                num2num[a + b]++;
            }
        }

        int res = 0;
        for (auto c : nums3) {
            for (auto d : nums4) {
                if (num2num.count(-c-d) > 0) {
                    res += num2num[-c-d];
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    Solution s;
    int res = s.fourSumCount(nums1, nums2, nums3, nums4);

    cout << res << endl;

    return 0;
}