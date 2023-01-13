/*
** Author: Yangyang Liu
** Date: 2023-01-13
** Description: 80. 删除有序数组中的重复项 II
** link: https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(); // 定义变量保存数组长度
        if (len <= 2) {
            return len;
        }
        int slow = 2; // 从2开始
        int fast = 2;

        while (fast < len) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }

            fast++; // 快指针不断遍历数组
        }

        return slow;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    Solution s;
    int res = s.removeDuplicates(nums);

    cout << res << endl;

    return 0;
}