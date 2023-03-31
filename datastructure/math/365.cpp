/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 365. 水壶问题
** link: https://leetcode.cn/problems/water-and-jug-problem/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }
        return targetCapacity % __gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

int main(int argc, char** argv) {
    int jug1Capacity = 3;
    int jug2Capacity = 5;
    int targetCapacity = 4;

    Solution s;
    bool res = s.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}