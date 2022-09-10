/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 57. 和为s的两个数字
** link: https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
** reference: 题解区，搜索，面试题57. 和为 s 的两个数字（双指针 + 证明，清晰图解），直接看java代码，不用看原理分析
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 定义前后指针
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // left=right则是一个数字了，不符合要求了

            int sum = nums[left] + nums[right];

            if (target > sum) {
                // sum小了，则左指针往右走

                left++;
            } else if (target < sum) {
                // sum大了，则右指针往左走

                right--;
            } else {
                // target == sum了

                return vector<int>{nums[left], nums[right]};
            }
        }

        return vector<int>();
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> res = s.twoSum(nums, target);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}