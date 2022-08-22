/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 78. 子集
** link: https://leetcode.cn/problems/subsets/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
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