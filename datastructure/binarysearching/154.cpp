/*
** Author: Yangyang Liu
** Date: 2023-03-13
** Description: 154. 寻找旋转排序数组中的最小值 II
** link: https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) {
                high = mid;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high -= 1;
            }
        }

        return nums[low];
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, 5};

    Solution s;
    int res = s.findMin(nums);

    cout << res << endl;

    return 0;
}