/*
** Author: Yangyang Liu
** Date: 2023-02-25
** Description: 216. 组合总和 III
** link: https://leetcode.cn/problems/combination-sum-iii/
** reference: 自己理解后写的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存组合
public:
    void backtrack(int k, int n, int sum, int startIndex) {
        if (path.size() == k) { // 长度满足要求了
            if (sum == n) { // 组合的和满足要求了
                res.emplace_back(path);
            }

            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            path.emplace_back(i); // 当前路径上的数
            sum += i; // 求和
            backtrack(k, n, sum, i + 1); // 不能重复，从i+1开始
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1); // 回溯
        return res;
    }
};

int main(int argc, char** argv) {
    int k = 3; 
    int n = 7;

    Solution s;
    vector<vector<int>> res = s.combinationSum3(k, n);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}