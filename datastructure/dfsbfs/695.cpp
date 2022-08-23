/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 695. 岛屿的最大面积
** link: https://leetcode.cn/problems/max-area-of-island/
** reference: 题解区，官方题解，看了这题后，岛屿数量也自己做出来了
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // 递归结束条件
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        // 现在访问的1的位置置为0
        grid[i][j] = 0;

        // 定义变量保存面积
        int ans = 1; // 1代表当前访问的是1，则面积是1

        // 递归上下左右
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i, j + 1);
        ans += dfs(grid, i, j - 1);

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numRow = grid.size();
        int numCol = grid[0].size();

        // 如果grid为空，则面积为0
        if (numRow == 0 || numCol == 0) {
            return 0;
        }

        // 定义变量保存最大面积
        int maxArea = 0;

        // 从上到下，从左到右遍历grid
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                int area = dfs(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0}};

    Solution s;
    int res = s.maxAreaOfIsland(grid);

    cout << "res:" << res << endl;

    return 0;
}