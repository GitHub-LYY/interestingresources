/*
** Author: Yangyang Liu
** Date: 2022-08-19
** Description: 59. 螺旋矩阵 II
** link: https://leetcode.cn/problems/spiral-matrix-ii/
** reference: 题解区，官方题解讨论区，作者，Moreality
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 定义变量保存结果
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        // 定义变量保存上下左右位置
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        // 定义变量保存当前数字
        int x = 1; // 从1开始

        // 循环遍历
        while (true) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = x++;
            }

            if (++top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = x++;
            }

            if (--right < left) {
                break;
            }

            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = x++;
            }

            if (--bottom < top) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = x++;
            }

            if (++left > right) {
                break;
            }
        }

        return matrix;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(n);

    cout << "generated matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}