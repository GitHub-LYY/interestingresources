/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 39. 组合总和
** link: https://leetcode.cn/problems/combination-sum/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution s;
    vector<vector<int>> res = s.combinationSum(candidates, target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}