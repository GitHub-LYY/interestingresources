/*
** Author: Yangyang Liu
** Date: 2023-04-01
** Description: 229. 多数元素 II
** link: https://leetcode.cn/problems/majority-element-ii/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> num2count;
        int n = nums.size();
        for (auto num : nums) {
            num2count[num]++;
        }
        for (auto keyvalue : num2count) {
            if (keyvalue.second > n / 3) {
                res.push_back(keyvalue.first);
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums = {3, 2, 3};

    Solution s;
    vector<int> res = s.majorityElement(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}