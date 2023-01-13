/*
** Author: Yangyang Liu
** Date: 2023-01-13
** Description: 26. 删除有序数组中的重复项
** link: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(); // 定义变量保存数组长度
        if (len < 1) {
            return 0;
        }
        int slow = 1;
        int fast = 1; // 快慢指针从位置1开始

        while (fast < len) {
            if (nums[fast] != nums[fast - 1]) { // 不是重复的数字，则慢指针也要往右走
                nums[slow] = nums[fast]; // 一开始忘了
                slow++;
            }

            fast++; // 快指针不断往右走，遍历数组
        }

        return slow;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 2};

    Solution s;
    int res = s.removeDuplicates(nums);

    cout << res << endl;

    return 0;
}