/*
** Author: Yangyang Liu
** Date: 2022-12-28
** Description: 682. 棒球比赛
** link: https://leetcode.cn/problems/baseball-game/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        // 定义变量保存结果
        int res = 0;

        // 定义数组模拟栈
        vector<int> points;

        for (auto& op : operations) {
            int size = points.size();
            int num = 0;

            switch (op[0]) {
                case '+':
                    num = points[size - 1] + points[size - 2]; // 取出+号前边的两个数字
                    res += num;
                    points.push_back(num); // points插入的是num，不是res
                    break;
                case 'D':
                    num = points[size - 1];
                    res += num * 2;
                    points.push_back(num * 2);
                    break;
                case 'C':
                    num = points[size - 1];
                    res -= num;
                    points.pop_back();
                    break;
                default:
                    num = stoi(op);
                    res += num;
                    points.push_back(num);
                    break;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> ops = {"5", "2", "C", "D", "+"};

    Solution s;
    int res = s.calPoints(ops);

    cout << res << endl;

    return 0;
}