/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 53 - I. 在排序数组中查找数字 I
** link: https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/?favorite=xb9nqhhg
** reference: 二分搜索
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchFirst(vector<int>& nums, int target) {
        // 二分搜索

        // 定义左右边界
        int left = 0;
        int right = nums.size(); // 左闭右开

        while (left < right) {
            int mid = left + (right - left) / 2; // 求出中间位置

            if (target == nums[mid]) {
                // 相等了，要继续看是否是第一个位置

                if (mid == 0 || nums[mid] != nums[mid - 1]) {
                    // mid是第一个位置，或者mid位置的和前一个位置的不相等，则mid位置是第一个位置了

                    return mid;
                } else {
                    // 不是第一个位置

                    right = mid; // 更新的是left
                }
            } else if (target > nums[mid]) {
                left = mid + 1; // 更新左边界
            } else {
                right = mid; // 更新右边界
            }
        }

        return -1;
    }

    int searchLast(vector<int>& nums, int target) {
        // 定义左右边界
        int left = 0;
        int right = nums.size();

        while (left < right) {
            // 求出中间位置
            int mid = left + (right - left) / 2;

            if (target == nums[mid]) {
                // 相等了，要看是否是最后一个位置

                if (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]) {
                    return mid;
                } else {
                    // 不是最后一个位置

                    left = mid + 1;
                }
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // 求出target出现的第一个位置
        int left = searchFirst(nums, target);

        // 求出target出现的最后一个位置
        int right = searchLast(nums, target);

        // 这儿必须判断一下是否返回-1，即没有target
        if (left == -1 || right == -1) {
            // 判断一个便行了

            return 0; // 没有出现
        }

        return right - left + 1;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution s;
    int res = s.search(nums, target);

    cout << res << endl;

    return 0;
}