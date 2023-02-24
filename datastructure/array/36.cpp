/*
** Author: Yangyang Liu
** Date: 2023-02-24
** Description: 36. 有效的数独
** link: https://leetcode.cn/problems/valid-sudoku/
** reference: 官方题解
** https://www.bilibili.com/video/BV1qA411J7DD/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 两种方法，官方题解的，书森学院的
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]; // 9行，每一行0-9出现的次数
        int col[9][9]; // 9列，每一列0-9出现的次数
        int box[3][3][9]; // 9个九宫格，每个九宫格0-9出现的次数

        memset(row, 0, sizeof(row)); // 置零
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j]; // 取出当前格子中的字符
                if (ch == '.') { // 一开始忘了
                    continue;
                }
                int index = ch - '0' - 1; // ch是1-9，索引是0-9，因此要减一
                row[i][index]++; // 第i行的index+1的数字出现了，记录次数
                col[j][index]++; // 第j列的index+1的数字出现了，记录次数
                box[i / 3][j / 3][index]++; // 当前的九宫格中index+1的数字出现了，记录次数

                if (row[i][index] > 1 || col[j][index] >1 || box[i / 3][j / 3][index] > 1) { // 任何一个次数大于1，则不满足
                    return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    return 0;
}