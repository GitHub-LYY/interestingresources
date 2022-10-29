/*
** Author: Yangyang Liu
** Date: 2022-10-29
** Description: 566. 重塑矩阵
** link: https://leetcode.cn/problems/reshape-the-matrix/
** reference: 官方题解
** key point：res[i / c][i % c] = mat[i / n][i % n]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // 定义变量保存mat矩阵的行数和列数
        int m = mat.size();
        int n = mat[0].size();

        // 判断reshape的形状是否合理
        if (m * n != r * c) {
            // 元素数量不等，不能reshape

            return mat;
        }

        // 定义变量保存reshape后的结果
        vector<vector<int>> res(r, vector<int>(c)); // reshape后的矩阵是r行c列的

        // 按一维数组开始遍历mat
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n]; // 对应位置的数字放到res的位置
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1;
    int c = 4;

    Solution s;
    vector<vector<int>> res = s.matrixReshape(mat, r, c);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}