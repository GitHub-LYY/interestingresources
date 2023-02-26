/*
** Author: Yangyang Liu
** Date: 2023-02-26
** Description: 90. 子集 II
** link: https://leetcode.cn/problems/subsets-ii/
** reference: 自己理解后写的
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存子集
public:
    void backtrack(vector<int>& nums, int startIndex) {
        res.emplace_back(path); // 没有条件判断

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) { // 去重
                continue;
            }

            path.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序
        backtrack(nums, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 2};

    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}