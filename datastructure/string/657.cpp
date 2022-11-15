/*
** Author: Yangyang Liu
** Date: 2022-11-15
** Description: 657. 机器人能否返回原点
** link: https://leetcode.cn/problems/robot-return-to-origin/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        // 定义原点坐标
        int x = 0;
        int y = 0;

        // 遍历字符串
        for (char c : moves) {
            if (c == 'U') {
                // 往上走了一步

                y--;
            } else if (c == 'D') {
                // 往下走了一步

                y++;
            } else if (c == 'L') {
                // 往左走了一步

                x--;
            } else if (c == 'R') {
                // 往右走了一步

                x++;
            }
        }

        return x == 0 && y == 0; // 只有是原点才是true
    }
};

int main(int argc, char** argv) {
    string moves = "UD";

    Solution sol;
    bool res = sol.judgeCircle(moves);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}