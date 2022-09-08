/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 剑指 Offer 29. 顺时针打印矩阵
** link: https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/?favorite=xb9nqhhg
** reference: 看54题的题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 定义变量保存结果
        vector<int> res;

        // 必须有判断空的情况，否则LeetCode报错
        if (matrix.size() == 0) {
            return res;
        }

        // 定义上下左右四个边界
        int top = 0;
        int bottom = matrix.size() - 1; // 一开始忘记-1，报段错误
        int left = 0;
        int right = matrix[0].size() - 1;

        // true循环
        while (true) {
            for (int i = left; i <= right; i++) {
                // 从左到右保存

                res.push_back(matrix[top][i]);
            }

            if (++top > bottom) {
                // 越界了

                break;
            }

            for (int i = top; i <= bottom; i++) {
                // 从上到下保存

                res.push_back(matrix[i][right]);
            }

            if (--right < left) {
                // 越界了

                break;
            }

            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }

            if (--bottom < top) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                // 从下到上

                res.push_back(matrix[i][left]);
            }

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

    return 0;
}