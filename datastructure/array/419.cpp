/*
** Author: Yangyang Liu
** Date: 2022-10-26
** Description: 419. 甲板上的战舰
** link: https://leetcode.cn/problems/battleships-in-a-board/
** reference: 题解区，官方题解，方法二，枚举起点
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // 定义变量保存矩阵的行数和列数
        int numRow = board.size();
        int numCol = board[0].size();

        // 定义变量保存结果
        int res = 0;

        // 遍历矩阵
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (board[i][j] == 'X') {
                    // 此格子是X才有继续判断的必要

                    // i，j不能同时满足大于0，否则漏掉一些结果，因此换个思路，分开求

                    if (i > 0 && board[i - 1][j] == 'X') {
                        // 排除这种情况

                        continue;
                    }

                    if (j > 0 && board[i][j - 1] == 'X') {
                        // 排除这种情况

                        continue;
                    }

                    // 来到这儿，则满足是一个战舰群的左上角了
                    res++;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};

    Solution s;
    int res = s.countBattleShips(board);

    cout << res << endl;

    return 0;
}