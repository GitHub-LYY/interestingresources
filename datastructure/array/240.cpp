/*
** Author: Yangyang Liu
** Date: 2022-08-18
** Description: 240. 搜索二维矩阵 II
** link: https://leetcode.cn/problems/search-a-2d-matrix-ii/
** reference: 题解区，官方题解，z字形
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 如果矩阵为空，直接返回false
        if (matrix.empty()) {
            return false;
        }

        // 定义变量保存行数列数
        int numRow = matrix.size();
        int numCol = matrix[0].size();

        // 定义行列索引
        int row = 0;
        int col = numCol - 1;

        // 从右上角开始遍历
        while (row < numRow && col >= 0) {
            // 如果当前元素等于目标值，直接返回true
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                // 如果target小于当前元素，列索引减一

                col--;
            } else {
                // 如果target大于当前元素，行索引加一

                row++;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;

    Solution s;
    bool res = s.searchMatrix(matrix, target);

    cout << "target is in matrix: " << res << endl;

    return 0;
}