/*
** Author: Yangyang Liu
** Date: 2023-03-08
** Description: 35. 搜索插入位置
** link: https://leetcode.cn/problems/search-insert-position/
** reference: 忍者算法
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution s;
    int res = s.searchInsert(nums, target);

    cout << res << endl;

    return 0;
}