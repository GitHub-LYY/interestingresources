/*
** Author: Yangyang Liu
** Date: 2022-08-22，2023-02-25
** Description: 46. 全排列
** link: https://leetcode.cn/problems/permutations/
** reference: 代码随想录
** 20230225，忍者算法，容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class SolutionOld {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
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
        if (path.size() == nums.size()) { // 排列数组的大小满足了
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) { // 排列问题没有startIndex，从0开始，使用visited数组标志是否访问
            if (!visited[i]) { // 没有被访问，才可以访问
                path.emplace_back(nums[i]);
                visited[i] = true; // 标记已经访问
                backtrack(nums); // 递归
                visited[i] = false; // 回溯
                path.pop_back(); // 回溯
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size()); // 是否访问数组的大小
        backtrack(nums); // 回溯
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> res = s.permute(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}