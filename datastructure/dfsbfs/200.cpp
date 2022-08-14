/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 200. 岛屿数量
** link: https://leetcode.cn/problems/number-of-islands/
** reference: 题解区，代码随想录，版本一正确，版本二错误
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void dfsOld(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        // 递归跳出条件
        if (grid[x][y] == '0' || visited[x][y] == true) {
            // 遇到海水或者已经被访问了

            return;
        }

        // 标记当前位置已经被访问
        visited[x][y] = true;

        // 递归访问上下左右四个方向
        for (int dirIdx = 0; dirIdx < 4; dirIdx++) {
            // 计算要访问的下一个位置
            int nextx = x + dir[dirIdx][0];
            int nexty = y + dir[dirIdx][1];

            // 如果越界，则跳过
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }

            // 递归访问下一个位置
            dfs(grid, visited, nextx, nexty);
        }
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        // 递归跳出条件在下边

        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];

            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }

            if (grid[nextx][nexty] == '1' && visited[nextx][nexty] == false) {
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // dfs

        // 计算网格行数和列数
        int row = grid.size();
        int col = grid[0].size();

        // 定义网格有没有被访问过
        vector<vector<bool>> visited= vector<vector<bool>>(row, vector<bool>(col, false));

        // 定义岛屿数量
        int count = 0;

        // 遍历网格
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    // 来这儿，则是一个岛屿

                    // 这个位置已经被访问了
                    visited[i][j] = true;

                    // 岛屿数量加1
                    count++;

                    // 递归
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    Solution s;
    int res = s.numIslands(grid);

    cout << "number of islands: " << res << endl;

    return 0;
}