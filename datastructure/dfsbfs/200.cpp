/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 200. 岛屿数量
** link: https://leetcode.cn/problems/number-of-islands/
** reference: 题解区，代码随想录，版本一正确，版本二错误，不要看代码随想录的版本了，看的官方的岛屿的最大面积的题解，这题根据自己的理解写的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // 递归结束条件
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            // 超出边界了，或者当前格子是0，则结束递归
            return;
        }

        // 来到这儿，当前格子是1，但是现在访问了，把它置为0
        grid[i][j] = '0';

        // 上下左右四个方向继续递归
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int numRow = grid.size();
        int numCol = grid[0].size();

        // 如果grid为空，则数量是0
        if (numRow == 0 || numCol == 0) {
            return 0;
        }

        // 定义变量保存岛屿数量
        int numIslands = 0;

        // 从上到下，从左到右开始遍历grid的每一个格子
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (grid[i][j] == '1') { // 这儿必须是1才是岛屿
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
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