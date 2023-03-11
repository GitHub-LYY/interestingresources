/*
** Author: Yangyang Liu
** Date: 2023-03-11
** Description: 162. 寻找峰值
** link: https://leetcode.cn/problems/find-peak-element/
** reference: 题解区，官方题解评论区容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size(); // 长度
        int left = 0;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 1};

    Solution s;
    int res = s.findPeakElement(nums);

    cout << res << endl;

    return 0;
}