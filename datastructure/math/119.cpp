/*
** Author: Yangyang Liu
** Date: 2022-10-22
** Description: 119. 杨辉三角 II
** link: https://leetcode.cn/problems/pascals-triangle-ii/
** reference: 官方题解，配合视频，容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 定义三角
        vector<vector<int>> triangle(rowIndex + 1);

        // 遍历，填充数字
        for (int i = 0; i <= rowIndex; i++) {
            // 每一层的长度确定了
            triangle[i].resize(i + 1);

            // 每一层第一个和最后一个数字是一
            triangle[i][0] = triangle[i][i] = 1;

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle[rowIndex];
    }
};

int main(int argc, char** argv) {
    int rowIndex = 3;

    Solution s;
    vector<int> res = s.getRow(rowIndex);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}