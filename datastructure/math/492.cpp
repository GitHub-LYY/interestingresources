/*
** Author: Yangyang Liu
** Date: 2022-12-21
** Description: 492. 构造矩形
** link: https://leetcode.cn/problems/construct-the-rectangle/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        // 定义宽度
        int w = sqrt(area);

        while (area % w) {
            // 等于0，则不执行这

            w--; // 否则，不断减小w
        }

        return vector<int>{area / w, w};
    }
};

int main(int argc, char** argv) {
    int area = 4;

    Solution s;
    vector<int> res = s.constructRectangle(area);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}