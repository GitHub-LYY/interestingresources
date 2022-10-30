/*
** Author: Yangyang Liu
** Date: 2022-10-30
** Description: 303. 区域和检索 - 数组不可变
** link: https://leetcode.cn/problems/range-sum-query-immutable/
** reference: 题解区，官方题解，前缀和
** key point：sums数组长度为n+1容易求解
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    // 定义前缀和数组
    vector<int> sums;
    NumArray(vector<int>& nums) {
        // 初始化前缀和数组长度
        sums.resize(nums.size() + 1);

        // 遍历数组求前缀和
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i]; // 长度多1，方便计算
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    int res1 = numArray.sumRange(0, 2);
    int res2 = numArray.sumRange(2, 5);
    int res3 = numArray.sumRange(0, 5);

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    
    return 0;
}