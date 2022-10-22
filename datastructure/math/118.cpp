/*
** Author: Yangyang Liu
** Date: 2022-10-22
** Description: 118. 杨辉三角
** link: https://leetcode.cn/problems/pascals-triangle/
** reference: 官方题解，配合视频，容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 定义二维数组
        vector<vector<int>> triangle(numRows); // 内部有numRows个子数组

        // 遍历，填充三角
        for (int i = 0; i < numRows; i++) {
            // 每一层的长度确定了
            triangle[i].resize(i + 1); //triangle[i].size() = i + 1;

            // 每一层的第一个数和最后一个数是一
            triangle[i][0] = triangle[i][i] = 1;

            // 填充中间的数字
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};

int main(int argc, char** argv) {
    int numRows = 5;

    Solution s;
    vector<vector<int>> res = s.generate(numRows);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}