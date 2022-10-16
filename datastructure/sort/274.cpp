/*
** Author: Yangyang Liu
** Date: 2022-10-16
** Description: 274. H 指数
** link: https://leetcode.cn/problems/h-index/
** reference: 官方题解，方法一，排序
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 对数组排序
        sort(citations.begin(), citations.end());

        // 定义变量从后往前索引数组
        int i = citations.size() - 1;

        // 定义变量保存结果
        int h = 0;

        while (i >= 0 && citations[i] > h) { // 大于h，没有等于号
            h++;
            i--;
        }

        return h;
    }
};

int main(int argc, char** argv) {
    vector<int> citations = {3, 0, 6, 1, 5};

    Solution s;
    int res = s.hIndex(citations);

    cout << res << endl;

    return 0;
}