/*
** Author: Yangyang Liu
** Date: 2022-09-24
** Description: 485. 最大连续 1 的个数
** link: https://leetcode.cn/problems/max-consecutive-ones/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // 定义变量保存最大的数量
        int maxCount = 0;

        // 定义计数器
        int count = 0;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                // 当前数字是1，则计数器加一

                count++;
            } else {
                // 当前数字是0

                maxCount = max(maxCount, count); // 更新最大数量

                count = 0; // 计数器设置为0
            }
        }

        // 最后再更新一次最大数量
        maxCount = max(maxCount, count);

        return maxCount;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    Solution s;
    int res = s.findMaxConsecutiveOnes(nums);

    cout << res << endl;
    
    return 0;
}