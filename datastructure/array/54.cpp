/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 54. 螺旋矩阵
** link: https://leetcode.cn/problems/spiral-matrix/
** reference: 题解区，搜索，C++ 详细题解，作者YouLookDeliciousC，题解特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 定义变量保存结果
        vector<int> res;

        // 如果矩阵为空，则直接返回
        if (matrix.size() == 0) {
            return res;
        }

        // 定义四个指针，分别指向矩阵的上下左右边界
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        // 循环
        while (true) {
            // 从左到右保存结果
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }

            // 判断top的下一行是否超过bottom，如果超过，则跳出循环
            if (++top > bottom) {
                break;
            }

            // 从上到下保存结果
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }

            // 判断right的前一列是否小于left，如果小于，则跳出循环
            if (--right < left) {
                break;
            }

            // 从右到左保存结果
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }

            // 判断bottom的上一行是否小于top，如果小于，则跳出循环
            if (--bottom < top) {
                break;
            }

            // 从下到上保存结果
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }

            // 判断left的后一列是否超过right，如果超过，则跳出循环
            if (++left > right) {
                break;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    vector<int> res = s.spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}