/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 04. 二维数组中的查找
** link: https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
** reference: 题解去搜剑指 Offer 04. 二维数组中的查找（详细C++代码注释学习代码随想录的风格写的）
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 这个异常处理必须有，没有则在leetcode上会报错
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int row = 0;
        int col = matrix[0].size() - 1;
        // 从右上角开始遍历，直到下标越界停止
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }

        // 下标越界，说明没有找到
        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {
        {1,  4, 7, 11, 15},
        {2,  5, 8, 12, 19},
        {3,  6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    cout << "matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "target: " << target << endl;
    
    Solution s;
    bool res = s.findNumberIn2DArray(matrix, target);

    cout << "Is target in matrix: " << res << endl;

    return 0;
}