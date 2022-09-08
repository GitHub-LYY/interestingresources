/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 169. 多数元素
** link: https://leetcode.cn/problems/majority-element/
** reference: 摩尔投票法，剑指offer39题解区，搜索，详细讲解 — 哈希表 | 排序 | 摩尔投票（不懂来 KO 我）
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 默认第一个元素是正式候选人，数量为1
        int candidate = nums[0];
        int count = 1;

        // 从第二个元素遍历
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                // 相等，则数量加一

                count++;
            } else if (--count == 0) {
                // 必须减一，因此直接在条件中进一步判断，巧妙

                candidate = nums[i]; // 当前元素是正式候选人
                count = 1; // 这一定是1
            }
        }

        return candidate;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 3};

    Solution s;
    int res = s.majorityElement(nums);

    cout << res << endl;

    return 0;
}