/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 74. 搜索二维矩阵
** link: https://leetcode.cn/problems/search-a-2d-matrix/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 把矩阵按行展开，拼接，是一个升序数组，可以用二分查找

        // 定义变量保存行数列数
        int numRow = matrix.size();
        int numCol = matrix[0].size();

        // 定义变量保存左右边界
        int left = 0;
        int right = numRow * numCol;

        // 二分搜索
        while (left < right) {
            // 计算中间位置
            int mid = left + (right - left) / 2;

            // 计算中间位置对应的矩阵的位置
            int midValue = matrix[mid / numCol][mid % numCol];

            if (target == midValue) {
                return true;
            } else if (target < midValue) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    Solution s;
    bool res = s.searchMatrix(matrix, target);

    cout << "target in matrix: " << res << endl;

    return 0;
}