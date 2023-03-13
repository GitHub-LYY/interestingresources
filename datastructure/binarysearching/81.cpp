/*
** Author: Yangyang Liu
** Date: 2023-03-13
** Description: 81. 搜索旋转排序数组 II
** link: https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size(); // 数组长度

        if (len == 0) { // 数组的空的，则一定没有
            return false;
        }
        if (len == 1) { // 数组只有一个数，则直接比较二者
            return nums[0] == target; 
        }

        int left = 0;
        int right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    Solution s;
    bool res = s.search(nums, target);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}