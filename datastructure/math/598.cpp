/*
** Author: Yangyang Liu
** Date: 2022-10-26
** Description: 598. 范围求和 II
** link: https://leetcode.cn/problems/range-addition-ii/
** reference: 题解区，结合几个题解、视频最后理解了，搜索，[小松漫步]重复绘制，取最小宽高，作者，小松漫步
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // 定义变量保存最小宽、最小高
        int minW = m; // 初始值为m，方便下边min函数
        int minH = n;

        // 遍历ops二维数组
        for (auto vec : ops) {
            minW = min(minW, vec[0]);
            minH = min(minH, vec[1]);
        }

        return minW * minH;
    }
};

int main(int argc, char** argv) {
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};

    Solution s;
    int res = s.maxCount(m, n, ops);

    cout << res << endl;

    return 0;
}