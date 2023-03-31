/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 593. 有效的正方形
** link: https://leetcode.cn/problems/valid-square/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkLength(vector<int>& v1, vector<int>& v2) {
        return (v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]);
    }
    bool checkMidPoint(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (p1[0] + p2[0]) == (p3[0] + p4[0]) && (p1[1] + p2[1]) == (p3[1] + p4[1]);
    }
    int calCos(vector<int>& v1, vector<int>& v2) {
        return (v1[0] * v2[0] + v1[1] * v2[1]) == 0;
    }
    bool help(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v1 = {p1[0] - p2[0], p1[1] - p2[1]};
        vector<int> v2 = {p3[0] - p4[0], p3[1] - p4[1]}; // 交叉点坐标相减
        if (checkMidPoint(p1, p2, p3, p4) && checkLength(v1, v2) && calCos(v1, v2)) {
            return true;
        }
        return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2) { // 两个交叉的点相等了
            return false;
        }
        if (help(p1, p2, p3, p4)) {
            return true;
        }
        if (p1 == p3) {
            return false;
        }
        if (help(p1, p3, p2, p4)) {
            return true;
        }
        if (p1 == p4) {
            return false;
        }
        if (help(p1, p4, p2, p3)) {
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 1};

    Solution s;
    bool res = s.validSquare(p1, p2, p3, p4);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}