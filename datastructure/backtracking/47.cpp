/*
** Author: Yangyang Liu
** Date: 2022-08-23，2023-02-25
** Description: 47. 全排列 II
** link: https://leetcode.cn/problems/permutations-ii/
** reference: 代码随想录
** 20230225，忍者算法
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolutionOld {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存路径
    vector<bool> visited; // 定义变量保存是否访问的标志
public:
    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) { // 排列大小满足要求了
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) { // 去重，两个条件，当前和前边相等，且前边的没有被访问
                continue; 
            }

            if (!visited[i]) { // 没有被访问才可以访问
                path.emplace_back(nums[i]);
                visited[i] = true; // 已经被访问
                backtrack(nums); // 递归
                visited[i] = false; 
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 一开始忘了
        visited.resize(nums.size()); // 标志数组大小
        backtrack(nums); // 回溯
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 2};

    Solution s;
    vector<vector<int>> res = s.permuteUnique(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}