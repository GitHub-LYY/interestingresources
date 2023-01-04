/*
** Author: Yangyang Liu
** Date: 2023-01-04
** Description: 532. 数组中的 k-diff 数对
** link: https://leetcode.cn/problems/k-diff-pairs-in-an-array/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited; // 保存遍历nums的每个数字
        unordered_set<int> res; // 保存满足条件数对的第一个数字

        for (int num : nums) {
            if (visited.find(num + k) != visited.end()) { // visited中存在num+k，则是一个数对，保存数对的第一数字
                res.emplace(num);
            }
            if (visited.find(num - k) != visited.end()) {
                res.emplace(num - k);
            }

            visited.emplace(num);
        }

        return res.size();
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    Solution s;
    int res = s.findPairs(nums, k);

    cout << res << endl;

    return 0;
}