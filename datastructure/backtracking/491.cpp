/*
** Author: Yangyang Liu
** Date: 2023-02-26
** Description: 491. 递增子序列
** link: https://leetcode.cn/problems/non-decreasing-subsequences/
** reference: 自己理解后写的
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存子集
public:
    void backtrack(vector<int>& nums, int startIndex) {
        if (path.size() > 1) { // 数组长度大于一则要收割了
            res.emplace_back(path);
        }

        unordered_set<int> uset; // 定义集合用来去除同一层的重复的数，防止结果出现重复的子集
        for (int i = startIndex; i < nums.size(); i++) {
            // path中的最后一个数大于当前的数，不满足
            // 集合中已经有当前这个数了，不要重复取了
            if ((!path.empty() && path.back() > nums[i]) || uset.find(nums[i]) != uset.end()) { // 直接下一个数
                continue; 
            }

            uset.insert(nums[i]); // 插入集合中
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1); 
            path.pop_back();
        }

        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 6, 7, 7};

    Solution s;
    vector<vector<int>> res = s.findSubsequences(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}