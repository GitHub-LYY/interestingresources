/*
** Author: Yangyang Liu
** Date: 2023-03-10
** Description: 540. 有序数组中的单一元素
** link: https://leetcode.cn/problems/single-element-in-a-sorted-array/
** reference: 题解区，官方题解，二分搜索
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) { // left等于right的时候是结果了
            int mid = left + (right - left) / 2; // 计算中间索引

            // 异或的妙用，mid是偶数，代表mid+1，mid是奇数，代表mid-1，恰好是本题需要的
            if (nums[mid] == nums[mid ^ 1]) { // 偶数或者奇数索引，规律没有被打破
                left = mid + 1; // 往右边继续搜索
            } else { // 规律被打破了，往左边搜索
                right = mid;
            }
        }

        return nums[left];
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    Solution s;
    int res = s.singleNonDuplicate(nums);

    cout << res << endl;

    return 0;
}