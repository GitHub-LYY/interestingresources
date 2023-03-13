/*
** Author: Yangyang Liu
** Date: 2023-03-13
** Description: 240. 搜索二维矩阵 II
** link: https://leetcode.cn/problems/search-a-2d-matrix-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRow = matrix.size(); // 行数
        int numCol = matrix[0].size(); // 列数

        int row = 0;
        int col = numCol - 1; // 从右上角开始

        while (row < numRow && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (target < matrix[row][col]) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;

    Solution s;
    bool res = s.searchMatrix(matrix, target);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}