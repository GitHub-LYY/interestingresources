/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 39. 数组中出现次数超过一半的数字
** link: https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/?favorite=xb9nqhhg
** reference: 摩尔投票法，剑指offer39题解区，搜索，详细讲解 — 哈希表 | 排序 | 摩尔投票（不懂来 KO 我）
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 令第一个数字为正式候选人，票数为一
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            // 从下表为1开始遍历

            if (nums[i] == candidate) {
                // 相等，则count++

                count++;
            } else if (--count == 0) {
                // 这直接使用--count比较巧妙

                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};

    Solution s;
    int res = s.majorityElement(nums);

    cout << res << endl;

    return 0;
}