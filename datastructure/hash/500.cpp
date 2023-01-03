/*
** Author: Yangyang Liu
** Date: 2023-01-03
** Description: 500. 键盘行
** link: https://leetcode.cn/problems/keyboard-row/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res; // 定义变量保存结果

        string rowIdx = "12210111011122000010020202";

        for (string word : words) {
            bool isValid = true; // 先假设为true
            char idx = rowIdx[tolower(word[0]) - 'a']; // 求出当前字符串首字母的行号
            for (int i = 1; i < word.size(); i++) { // 索引从1开始遍历      
                if (rowIdx[tolower(word[i]) - 'a'] != idx) { // 不在一行中
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                res.push_back(word);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    Solution s;
    vector<string> res = s.findWords(words);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}