/*
** Author: Yangyang Liu
** Date: 2022-10-29
** Description: 73. 矩阵置零
** link: https://leetcode.cn/problems/set-matrix-zeroes/
** reference: 官方题解，方法二，看了视频后，再看题解，理解了，网上也多是方法二的思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 定义变量保存矩阵的行数和列数
        int m = matrix.size();
        int n = matrix[0].size();

        // 定义变量保存原始矩阵的第0行、第0列是否有0
        bool flagRow0 = false;
        bool flagCol0 = false;

        // 遍历原始的第0列是否有0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                flagCol0 = true;
            }
        }

        // 遍历原始的第0行是否有0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                flagRow0 = true;
            }
        }

        // 从(1,1)遍历到(m-1,n-1)，标记需要置0的行和列
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // 标记第i行要置为0
                    matrix[0][j] = 0; // 标记第j列要置为0
                }
            }
        }

        // 从(1,1)遍历到(m-1,n-1)，根据第0行和第0列的标记来对对应的行和列进行置0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    // 第i行要置为0，第j列要置为0

                    matrix[i][j] = 0;
                }
            }
        }

        // 根据原始第0行是否有0对第0行置0
        if (flagRow0 == true) {
            // 为true，则第0行要全部置为0

            // 遍历第0行
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0; // 第0行的值为0
            }
        }

        // 根据原始第0列是否有0对第0列置0
        if (flagCol0 == true) {
            // 为true，则第0列要全部置为0

            // 遍历第0列
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0; // 第0列的值为0
            }
        }

        return;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    Solution s;
    s.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}