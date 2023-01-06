/*
** Author: Yangyang Liu
** Date: 2023-01-06
** Description: 219. 存在重复元素 II
** link: https://leetcode.cn/problems/contains-duplicate-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2index; // 数字-索引哈希表
        for (int i = 0; i < nums.size(); i++) {
            if (num2index.count(nums[i]) > 0 && (i - num2index[nums[i]]) <= k) { // 存在相等的数字且i-j<=k
                return true;
            }
            num2index[nums[i]] = i; // 不断把当前遍历的数字和索引插入哈希表
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution s;
    bool res = s.containsNearbyDuplicate(nums, k);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}