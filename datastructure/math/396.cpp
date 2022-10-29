/*
** Author: Yangyang Liu
** Date: 2022-10-29
** Description: 396. 旋转函数
** link: https://leetcode.cn/problems/rotate-function/
** reference: 官方题解，也有评论区的seven的网友的评论比官方的有的地方说的好
** key point：F(i) = F(i - 1) + sum - n * nums[n - i]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 定义变量保存数组的和
        int sum = 0;

        // 定义变量保存数组的元素个数
        int n = nums.size();

        // 定义变量保存F
        int F = 0;

        // 遍历求出和，F
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i]; // F的计算公式，先求出F(0)，后边迭代求出最大的，第一版，忘记写+=的+了，错误
        }

        // 定义变量保存F的最大值
        int res = F;

        // 再次遍历数组求出最大的F
        for (int i = 1; i < n; i++) {
            F = F + sum - n * nums[n - i];
            res = max(res, F);
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 3, 2, 6};

    Solution s;
    int res = s.maxRotateFunction(nums);

    cout << res << endl;

    return 0;
}