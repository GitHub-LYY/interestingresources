/*
** Author: Yangyang Liu
** Date: 2022-11-01
** Description: 304. 二维区域和检索 - 矩阵不可变
** link: https://leetcode.cn/problems/range-sum-query-2d-immutable/
** reference: 题解区，作者，fuxuemingzhu，容易理解
** key point：一，初始化的时候求前缀和矩阵，二，求区域和的时候使用前缀和求
*/

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    // 定义前缀和矩阵
    vector<vector<int>> preSum; // 前缀和矩阵作为data member，不能放在构造函数，因为sumRegion用了
    NumMatrix(vector<vector<int>>& matrix) {
        // 定义变量保存矩阵的行数和列数
        int numRow = matrix.size();
        int numCol = matrix[0].size();

        // 初始化前缀和矩阵
        preSum.resize(numRow + 1, vector<int>(numCol + 1)); // resize的方式

        // 遍历矩阵求前缀和
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // 利用公式求矩形的和
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> mat = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix matrix(mat);
    int res1 = matrix.sumRegion(2, 1, 4, 3);
    int res2 = matrix.sumRegion(1, 1, 2, 2);
    int res3 = matrix.sumRegion(1, 2, 2, 4);

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;

    return 0;
}