/*
** Author: Yangyang Liu
** Date: 2022-12-20
** Description: 458. 可怜的小猪
** link: https://leetcode.cn/problems/poor-pigs/
** reference: 题解区，搜索，画解算法：458. 可怜的小猪，账号，画手大鹏
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base) - 1e-5);
    }
};

int main(int argc, char** argv) {
    int buckets = 1000;
    int minutesToDie = 15;
    int minutesToTest = 60;

    Solution s;
    int res = s.poorPigs(buckets, minutesToDie, minutesToTest);

    cout << res << endl;

    return 0;
}