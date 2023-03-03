/*
** Author: Yangyang Liu
** Date: 2023-03-03
** Description: 463. 岛屿的周长
** link: https://leetcode.cn/problems/island-perimeter/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0}; // 定义方向数组
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(); // 行数
        int col = grid[0].size(); // 列数
        int res = 0; // 结果，周长

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) { // 格子值不是1才遍历
                    int count = 0; // 临时保存周长
                    for (int k = 0; k < 4; k++) { // 当前格子往四个方向遍历，判断是否要求周长了
                        int xx = i + dx[k];
                        int yy = j + dy[k]; // 求出四个方向
                        if (xx < 0 || xx >= row || yy < 0 || yy >= col || !grid[xx][yy]) { // 满足求周长的条件了
                            count++;
                        }
                    }
                    res += count; // 累计周长
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    Solution s;
    int res = s.islandPerimeter(grid);

    cout << res << endl;

    return 0;
}