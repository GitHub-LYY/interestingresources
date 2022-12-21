/*
** Author: Yangyang Liu
** Date: 2022-12-21
** Description: 168. Excel表列名称
** link: https://leetcode.cn/problems/excel-sheet-column-title/
** reference: 官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        // 定义变量保存结果
        string res;

        while (columnNumber > 0) {
            columnNumber--; // -1操作
            res += columnNumber % 26 + 'A'; // 转换为A-Z
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end()); // 反转

        return res;
    }
};

int main(int argc, char** argv) {
    int columnNumber = 1;

    Solution s;
    string res = s.convertToTitle(columnNumber);

    cout << res << endl;

    return 0;
}