/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 48. 旋转图像
** link: https://leetcode.cn/problems/rotate-image/
** reference: 题解区，搜索，旋转图像 | 操作分解 | 超简洁易懂的代码 【c++/java详细题解】，作者，林小鹿，特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 定义矩阵的行数
        int row = matrix.size();

        // 矩阵进行转置
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 矩阵在中间的竖线进行翻转
        for (int i = 0; i < row; i++) {
            for (int j = 0, k = row - 1; j < k; j++, k--) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    s.rotate(matrix);

    cout <<"matrix after rotate: " << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}