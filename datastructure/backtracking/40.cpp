/*
** Author: Yangyang Liu
** Date: 2022-08-23，2023-02-25
** Description: 40. 组合总和 II
** link: https://leetcode.cn/problems/combination-sum-ii/
** reference: 代码随想录
** 20230225，忍者算法，容易理解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolutionOld {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }

            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存路径
public:
    void backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) { // 满足要求了，收割
            res.emplace_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (sum < target) { // 和小于target才有插入的必要
                path.emplace_back(candidates[i]); // 收集路径
                sum += candidates[i]; // 求和
                backtrack(candidates, target, sum, i + 1); // 递归
                sum -= candidates[i]; // 回溯
                path.pop_back(); // 回溯
            }

            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) { // 去重
                i++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 先进行排序方便去重
        backtrack(candidates, target, 0, 0); // 回溯
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates, target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}