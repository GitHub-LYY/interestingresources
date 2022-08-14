/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 33. 搜索旋转排序数组
** link: https://leetcode.cn/problems/search-in-rotated-sorted-array/
** reference: 题解区，【忍者算法】全网最清晰易懂的题解，视频很好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分搜索

        // 异常情况
        if (nums.size() == 0) {
            return -1;
        }

        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }

        // 定义左右指针
        int left = 0;
        int right = nums.size(); // 左闭右开

        // 二分搜索
        while (left < right) {
            // 求出中间位置
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                // 左边数组有序

                // 判断target是否在左边数组中
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    // target在右边数组中

                    left = mid + 1; // 左闭右开，left必须加1，不加1LeetCode执行ac，但是提交报错
                }
            } else {
                // 右边数组有序

                // 判断target是否在右边数组中
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1; // 左闭右开，left必须加1，不加1LeetCode执行ac，但是提交报错
                } else {
                    // target在左边数组中

                    right = mid;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution s;
    int index = s.search(nums, target);

    cout << "index: " << index << endl;

    return 0;
}