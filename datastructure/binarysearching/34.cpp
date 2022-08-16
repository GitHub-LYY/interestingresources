/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 34. 在排序数组中查找元素的第一个和最后一个位置
** link: https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
** reference: 题解区，搜索，【忍者算法】全网最清晰易懂的题解，特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchRangeFirst(vector<int>& nums, int target) {
        // 二分搜索

        // 定义前后指针
        int left = 0;
        int right = nums.size();

        // 循环
        while (left < right) {
            // 计算中间位置
            int mid = left + (right - left) / 2;

            // 判断中间位置的值和目标值的大小
            if (target == nums[mid]) {
                // 相等了，要判断是否是第一个位置

                if (mid == 0 || nums[mid] != nums[mid - 1]) {
                    // mid是第一个位置

                    return mid;
                } else {
                    // mid不是第一个位置，right必须缩小

                    right = mid; // 左闭右开
                }
            } else if (target < nums[mid]) {
                // 目标值小于中间值，right必须缩小

                right = mid; // 左闭右开
            } else {
                // 目标值大于中间值，left必须增大

                left = mid + 1; // 左闭右开
            } 
        }

        return -1;
    }

    int searchRangeLast(vector<int>& nums, int target) {
        // 二分搜索

        // 定义前后指针
        int left = 0;
        int right = nums.size();

        // 循环
        while (left < right) {
            // 计算中间位置
            int mid = left + (right - left) / 2; // 这儿使用>> 1，本地和LeetCode上都会报错

            // 判断中间位置的值和目标值的大小
            if (target == nums[mid]) {
                // 相等了，要判断是否是最后一个位置

                if (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]) {
                    // mid是最后一个位置

                    return mid;
                } else {
                    // mid不是最后一个位置，left必须增大

                    left = mid + 1; // 左闭右开
                }
            } else if (target < nums[mid]) {
                // 目标值小于中间值，right必须缩小

                right = mid; // 左闭右开
            } else {
                // 目标值大于中间值，left必须增大

                left = mid + 1; // 左闭右开
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // 定义变量保存第一个位置
        int first = searchRangeFirst(nums, target);

        // 定义变量保存最后一个位置
        int last = searchRangeLast(nums, target);

        return vector<int>{first, last};
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution s;
    vector<int> res = s.searchRange(nums, target);

    cout << "res: " << res[0] << ", " << res[1] << endl;

    return 0;
}