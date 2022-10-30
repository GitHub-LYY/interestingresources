/*
** Author: Yangyang Liu
** Date: 2022-10-30
** Description: 289. 生命游戏
** link: https://leetcode.cn/problems/game-of-life/
** reference: 题解区，官方题解，方法二，评论区一网友的方向数组比官方的好理解，消化吸收这两个方法，自己从0开始写
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 定义方向数组
        int dir[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // 定义变量保存矩阵的行数和列数
        int numRow = board.size();
        int numCol = board[0].size();

        // 遍历矩阵
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                // 当前遍历的格子，要遍历它周围的8个格子

                // 定义变量保存8个格子1的数量
                int count = 0;

                // 遍历周围8个格子
                for (int k = 0; k < 8; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1]; // 纵坐标

                    // 坐标不能出界才有意义计算数量
                    if (x >= 0 && x < numRow && y >= 0 && y < numCol && abs(board[x][y]) == 1) { // 这儿有abs，很巧妙
                        count++; // 当前格子周围有一个1
                    }
                }

                // 条件一和条件三，条件二不用做操作
                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = -1; // 原来是活的，现在是死的
                }

                // 条件四
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2; // 原来是死的，现在是活的，复活了
                }
            }
        }

        // 再次遍历矩阵，把大于0的格子置为1，小于等于0的置为0
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (board[i][j] <= 0) {
                    board[i][j] = 0;
                } else {
                    board[i][j] = 1;
                }
            }
        }

        return;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

    Solution s;
    s.gameOfLife(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}