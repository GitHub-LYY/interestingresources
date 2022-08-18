/*
** Author: Yangyang Liu
** Date: 2022-08-18
** Description: 498. 对角线遍历
** link: https://leetcode.cn/problems/diagonal-traverse/
** reference: 题解区，搜索，对角线遍历 | 图解找规律 | 代码简洁易懂 【c++ / Java版本】，作者，林小鹿
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 定义变量保存结果
        vector<int> res; 

        // 定义变量保存行数列数
        int numRow = mat.size();
        int numCol = mat[0].size();

        // 定义变量保存对角线个数，方便后边为对角线索引编号
        int numDiagonal = numRow + numCol - 1;

        // 对角线进行遍历
        for (int i = 0; i < numDiagonal; i++) {
            // 每一次循环是遍历一个对角线的所有元素

            if (i % 2 == 0) {
                // 索引为偶数的对角线，从下往上遍历

                for (int x = min(i, numRow - 1); x >= max(0, i - numCol + 1); x--) {
                    // 遍历偶数对角线的每一个元素

                    res.push_back(mat[x][i - x]); // x是横坐标，i-x是纵坐标
                }
            }

            if (i % 2 == 1) {
                // 索引为奇数的对角线，从上往下遍历

                for (int x = max(0, i - numCol + 1); x <= min(i, numRow - 1); x++) {
                    // 遍历奇数对角线的每一个元素

                    res.push_back(mat[x][i - x]);
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    
    Solution s;
    vector<int> res = s.findDiagonalOrder(mat);

    cout << "diagonal order: " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}