/*
** Author: Yangyang Liu
** Date: 2023-02-20
** Description: 565. 数组嵌套
** link: https://leetcode.cn/problems/array-nesting/
** reference: 题解区，官方题解，再搜索，作图帮助理解，作者，才半页
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int len = nums.size(); // 定义变量保存数组长度
        vector<bool> visited(len); // 定义等长的数组保存是否已经访问这个数字
        for (int i = 0; i < len; i++) { // 每次从一个数开始遍历
            int count = 0; // 每次从一个数字开始的时候，把数量置为0，从头开始计算

            while (!visited[i]) { // 当前位置的数没有被访问，需要说的是，每个数只能被访问一次
                visited[i] = true; // 标记当前数已经访问了
                i = nums[i]; // 索引置为当前的数值
                count++; // 数量多一
            }

            res = max(res, count); // 求出每次从一个数开始遍历的最大数量
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};

    Solution s;
    int res = s.arrayNesting(nums);

    cout << res << endl;

    return 0;
}