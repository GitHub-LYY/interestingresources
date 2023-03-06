/*
** Author: Yangyang Liu
** Date: 2023-03-06
** Description: 529. 扫雷游戏
** link: https://leetcode.cn/problems/minesweeper/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> dir_row = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dir_col = {1, -1, 0, 1, -1, 0, 1, -1};
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int count = 0; // 当前空格周围8个格子中的地雷数量
        for (int i = 0; i < 8; i++) {
            int xx = x + dir_row[i];
            int yy = y + dir_col[i];

            if (xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size()) { // 出界了
                continue;
            }

            // 来到这，则没有越界
            if (board[xx][yy] == 'M') { // 统计周围8个格子的地雷
                count++;
            }
        }

        // 根据周围地雷数量来决定写入内容
        if (count > 0) { // 周围有地雷，则写入地雷的数量
            board[x][y] = count + '0';
        } else { // 周围没有地雷，则递归传染周围的空格，周围的空格也按此规律进行下去
            board[x][y] = 'B'; // 写入B

            for (int i = 0; i < 8; i++) {
                int xx = x + dir_row[i];
                int yy = y + dir_col[i];

                if (xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size() || board[xx][yy] != 'E') { // 越界了，或者不是空格子
                    continue;
                }

                dfs(board, xx, yy);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0]; // 求出点击的横坐标
        int y = click[1]; // 点击的纵坐标

        if (board[x][y] == 'M') { // 点击到了地雷
            board[x][y] = 'X';
        } else { // 点击到了空格
            dfs(board, x, y);
        }

        return board;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};

    Solution s;
    vector<vector<char>> res = s.updateBoard(board, click);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}