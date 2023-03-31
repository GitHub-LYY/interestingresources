/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 223. 矩形面积
** link: https://leetcode.cn/problems/rectangle-area/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);
        int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
        return area1 + area2 - overlapArea;
    }
};

int main(int argc, char** argv) {
    int ax1 = -3;
    int ay1 = 0;
    int ax2 = 3;
    int ay2 = 4;
    int bx1 = 0;
    int by1 = -1;
    int bx2 = 9;
    int by2 = 2;

    Solution s;
    int res = s.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    cout << res << endl;

    return 0;
}