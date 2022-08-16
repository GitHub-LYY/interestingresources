/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 153. 寻找旋转排序数组中的最小值
** link: https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 定义前后指针
        int left = 0;
        int right = nums.size() - 1; // 重点，这儿是左闭右闭，while条件是不等，因为这道题一旦等于，则已经是最小值了

        // 循环
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                // 中间值小于右边值，中间值在最小值右边，right必须缩小

                right = mid; // 左闭右开
            } else {
                // 中间值大于等于右边值，中间值在最小值左边，left必须增大

                left = mid + 1; // 左闭右开
            }
        }

        // left和right相等，这个值就是最小值
        return nums[left];
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 4, 5, 1, 2};

    Solution s;
    int res = s.findMin(nums);

    cout << "res: " << res << endl;

    return 0;
}