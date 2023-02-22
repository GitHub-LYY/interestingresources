/*
** Author: Yangyang Liu
** Date: 2023-02-22
** Description: 526. 优美的排列
** link: https://leetcode.cn/problems/beautiful-arrangement/
** reference: 题解区，搜索，C++经典回溯，作者，hoboom
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> visited; // 长度在函数中确定，现在先定义变量
    int res = 0; // 定义变量保存优美排列的数量
public:
    void backtrack(int n, int index) { // index有两个作用，第一个是从一开始的下标位置，第二个是当前使用了几个数了，不理解思考n=3中123，132的情况
        if (index == n + 1) { // 能达到这个条件，则这个排列满足优美排列
            res++; // 结果多一个排列
            return; // 直接退出
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (i % index == 0 || index % i == 0)) { // 这的i代表的是数，不要思考成索引了
                visited[i] = true; // 标记已经访问了
                backtrack(n, index + 1); // 递归
                visited[i] = false; // 回溯
            }
        }
    }
    int countArrangement(int n) {
        visited.resize(n + 1); // 下标0的位置不使用，题目说了下标从1开始
        backtrack(n, 1); // 回溯求优美排列的数量
        return res;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    int res = s.countArrangement(n);

    cout << res << endl;

    return 0;
}