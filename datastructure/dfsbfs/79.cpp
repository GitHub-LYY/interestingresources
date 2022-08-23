/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 79. 单词搜索
** link: https://leetcode.cn/problems/word-search/
** reference: 题解区，搜索，单词搜索 | 回溯算法 | 最通俗易懂的讲解 【c++/java版】，根据自己从岛屿题学习的dfs做
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int u) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[u]) {
            return false;
        }

        if (u == word.size() - 1) { // 必须有
            return true;
        }

        // 来到这儿，则board[i][j] == word[u]
        // 把当前字符设为点号，防止再被遍历，题目说了不能重复利用一个单元格的
        char c = board[i][j];
        board[i][j] = '.';

        // 上下左右递归
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

        board[i][j] = c;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int numRow = board.size();
        int numCol = board[0].size();

        // 如果board为空，则一定搜不到
        if (numRow == 0 || numCol == 0) {
            return false;
        }

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
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

    cout << "res:" << res << endl;

    return 0;
}