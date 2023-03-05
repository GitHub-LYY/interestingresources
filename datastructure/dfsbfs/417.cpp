/*
** Author: Yangyang Liu
** Date: 2023-03-05
** Description: 417. 太平洋大西洋水流问题
** link: https://leetcode.cn/problems/pacific-atlantic-water-flow/
** reference: 官方题解，dfs
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int numRow; // 行数
    int numCol; // 列数
    vector<int> dir_row = {1, 0, -1, 0};
    vector<int> dir_col = {0, 1, 0, -1};
    vector<vector<int>> heights;
public:
    void dfs(int row, int col, vector<vector<bool>>& ocean) {
        if (ocean[row][col]) { // 已经是true了，则没必要往下了
            return;
        }

        ocean[row][col] = true; // 到这，则可以到达

        for (int i = 0; i < 4; i++) {
            int xx = row + dir_row[i];
            int yy = col + dir_col[i];

            if (xx >= 0 && xx < numRow && yy >= 0 && yy < numCol && heights[xx][yy] >= heights[row][col]) { // 可以到达的格子
                dfs(xx, yy, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        numRow = heights.size();
        numCol = heights[0].size();
        vector<vector<bool>> pacific(numRow, vector<bool>(numCol, false)); // 是否可以从太平洋到达
        vector<vector<bool>> atlantic(numRow, vector<bool>(numCol, false)); // 是否可以从大西洋到达
        vector<vector<int>> res;

        for (int i = 0; i < numRow; i++) {
            dfs(i, 0, pacific); // 左边界太平洋到达的格子做标记
        }
        for (int j = 1; j < numCol; j++) {
            dfs(0, j, pacific); // 上边界太平洋到达的格子做标记
        }
        for (int i = 0; i < numRow; i++) {
            dfs(i, numCol - 1, atlantic); // 右边界大西洋到达的格子做标记
        }
        for (int j = 0; j < numCol; j++) {
            dfs(numRow - 1, j, atlantic); // 下边界大西洋到达的格子做标记
        }

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (pacific[i][j] && atlantic[i][j]) { // 太平洋和大西洋可以到达
                    vector<int> tmp;
                    tmp.emplace_back(i);
                    tmp.emplace_back(j);
                    res.emplace_back(tmp);
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(heights);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}