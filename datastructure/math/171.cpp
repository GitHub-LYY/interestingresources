/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 171. Excel 表列序号
** link: https://leetcode.cn/problems/excel-sheet-column-number/
** reference: 题解区，搜索，画解算法：171. Excel表列序号，账号，画手大鹏
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        // 定义变量保存结果
        int res = 0;

        for (int i = 0; i < columnTitle.size(); i++) {
            int num = columnTitle[i] - 'A' + 1; // 必须

            res = res * 26 + num;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string columnTitle = "A";

    Solution s;
    int res = s.titleToNumber(columnTitle);

    cout <<res << endl;

    return 0;
}