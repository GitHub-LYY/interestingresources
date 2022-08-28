/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 12. 矩阵中的路径
** link: https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/
** reference: 之前做了，自己做
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int u) {
        // 如果i，j越界了，当前字符不匹配
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[u]) { // 记得写等号，忘记写，则报段
            return false;
        }

        // 一开始忘写了，这必须有，成功了的出口
        if (u == word.size() - 1) {
            return true;
        }

        // 到这儿，则当前字符是匹配的
        // 把当前字符保存一下，后边要改它
        char c = board[i][j];

        // 当前字符改为点号，防止在上下左右遍历继续用了它
        board[i][j] = '.'; // 题目说了同一个单元格的字符不能再次使用

        // 上下左右遍历
        if (dfs(board, i + 1, j, word, u + 1)) {
            return true;
        }

        if (dfs(board, i - 1, j, word, u + 1)) {
            return true;
        }

        if (dfs(board, i, j + 1, word, u + 1)) {
            return true;
        }

        if (dfs(board, i, j - 1, word, u + 1)) {
            return true;
        }

        // 上边匹配成功是不需要改点号的，到这了，则匹配失败了，要把点号改了，类似乘胜一路追击
        board[i][j] = c;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }

        // 从上到下，从左到右遍历每一个位置
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    Solution s;
    bool res = s.exist(board, word);

    cout << "exist?" << " " << res << endl;

    return 0;
}