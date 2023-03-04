/*
** Author: Yangyang Liu
** Date: 2023-03-04
** Description: 994. 腐烂的橘子
** link: https://leetcode.cn/problems/rotting-oranges/
** reference: 题解区，官方题解不容易理解，评论区容易理解，作者，ForFut
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(); // 行数
        int col = grid[0].size(); // 列数
        int fresh = 0; // 新鲜橘子个数
        int minutes = 0; // 分钟数
        queue<pair<int, int>> que; // 队列，保存腐烂橘子的坐标位置
        vector<int> move_row = {1, 0, -1, 0}; // 行坐标的移动
        vector<int> move_col = {0, 1, 0, -1}; // 列坐标的移动

        // 遍历矩阵，腐烂橘子入队，新鲜橘子统计个数
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) { // 新鲜橘子
                    fresh++;
                }
                if (grid[i][j] == 2) { // 腐烂橘子入队
                    que.push(make_pair(i, j));
                }
            }
        }

        // 类似二叉树层序遍历
        while (!que.empty()) {
            if (fresh == 0) { // 进来这个腐烂新鲜橘子的循环，如果没有新鲜橘子了，则直接不用再腐烂了
                break;
            }

            int size = que.size(); // 本层腐烂橘子数量

            for (int i = 0; i < size; i++) { // 一层腐烂橘子的遍历
                int x = que.front().first; // 当前层腐烂橘子的横坐标
                int y = que.front().second; // 当前层腐烂橘子的纵坐标
                que.pop(); // 不要忘了弹出队列

                for (int i = 0; i < 4; i++) { // 上下左右四个方向的邻居遍历
                    int xx = x + move_row[i]; // 往某个方向走
                    int yy = y + move_col[i]; // 往某个方向走
                    
                    if (xx >= 0 && xx < row && yy >= 0 && yy < col && grid[xx][yy] == 1) { // 往某个方向走，没有越界，而且是新鲜的橘子
                        grid[xx][yy] = 2; // 腐烂新鲜的橘子，做个标记
                        fresh--; // 新鲜橘子数量减少
                        que.push(make_pair(xx, yy)); // 当前被腐烂的橘子坐标入队
                    }
                }
            }

            minutes++; // 遍历完一层腐烂橘子不要忘了分钟多一
        }

        return fresh == 0 ? minutes : -1;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    Solution s;
    int res = s.orangesRotting(grid);

    cout << res << endl;

    return 0;
}