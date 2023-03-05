/*
** Author: Yangyang Liu
** Date: 2023-03-05
** Description: 130. 被围绕的区域
** link: https://leetcode.cn/problems/surrounded-regions/
** reference: 官方题解，dfs
*/

#include <iostream>
#include <vector>

using  namespace std;

class Solution {
private:
    int numRow; // 行数
    int numCol; // 列数
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= numRow || y < 0 || y >= numCol || board[x][y] != 'O') { // 越界或者不是O
            return;
        }

        board[x][y] = 'A'; // 来到这儿，则当前是O，变为A

        dfs(board, x + 1, y); // 下边
        dfs(board, x, y + 1); // 右边
        dfs(board, x - 1, y); // 上边
        dfs(board, x, y - 1); // 左边
    }
    void solve(vector<vector<char>>& board) {
        numRow = board.size(); 
        numCol = board[0].size();

        for (int i = 0; i < numRow; i++) {
            dfs(board, i, 0); // 左边界相连的O标记为A
            dfs(board, i, numCol - 1); // 右边界相连的O标记为A
        }
        for (int j = 0; j < numCol; j++) {
            dfs(board, 0, j); // 上边界相连的O标记为A
            dfs(board, numRow - 1, j); // 下边界相连的O标记为A
        }

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (board[i][j] == 'A') { // 当前格子被标记为A
                    board[i][j] = 'O'; // 这些是不被围绕的O
                } else if (board[i][j] == 'O') { // 这些是被围绕的O
                    board[i][j] = 'X';
                } else {
                    continue;
                }
            }
        }

        return;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    Solution s;
    s.solve(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}