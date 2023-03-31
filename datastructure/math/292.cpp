/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 292. Nim 游戏
** link: https://leetcode.cn/problems/nim-game/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(int argc, char** argv) {
    int n = 4;

    Solution s;
    bool res = s.canWinNim(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}