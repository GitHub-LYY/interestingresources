/*
** Author: Yangyang Liu
** Date: 2022-08-22，2023-02-26
** Description: 78. 子集
** link: https://leetcode.cn/problems/subsets/
** reference: 代码随想录
** 20230226，子集理解后写的
*/

#include <iostream>
#include <vector>

using namespace std;

class SolutionOld {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        res.push_back(path);

        if (startIndex >= nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        if (nums.size() == 0) {
            return res;
        }
        backtracking(nums, 0);
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存子集
public:
    void backtrack(vector<int>& nums, int startIndex) {
        res.emplace_back(path); // 子集不用判断条件

        for (int i = startIndex; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> res = s.subsets(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}