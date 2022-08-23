/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 40. 组合总和 II
** link: https://leetcode.cn/problems/combination-sum-ii/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
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