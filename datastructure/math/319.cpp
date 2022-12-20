/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 319. 灯泡开关
** link: https://leetcode.cn/problems/bulb-switcher/
** reference: 官方题解
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n + 0.5);
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    int res = s.bulbSwitch(n);

    cout << res << endl;

    return 0;
}