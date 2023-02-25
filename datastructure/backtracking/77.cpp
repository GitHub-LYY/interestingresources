/*
** Author: Yangyang Liu
** Date: 2023-02-25
** Description: 77. 组合
** link: https://leetcode.cn/problems/combinations/
** reference: 自己理解后写的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; // 定义变量保存结果
    vector<int> path; // 定义变量保存某个组合
public:
    void backtrack(int n, int k, int startIndex) {
        if (path.size() == k) { // 组合长度满足要求，则收割
            res.emplace_back(path);
            return; // 不要忘了
        }

        for (int i = startIndex; i <= n; i++) {
            path.emplace_back(i); // 路径收集组合
            backtrack(n, k, i + 1); // 从i+1开始，已经遍历的不能再遍历了，这是组合
            path.pop_back(); // 回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1); // 回溯
        return res;
    }
};

int main(int argc, char** argv) {
    int n = 4;
    int k = 2;

    Solution s;
    vector<vector<int>> res = s.combine(n, k);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}