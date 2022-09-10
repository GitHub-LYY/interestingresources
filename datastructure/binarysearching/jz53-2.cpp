/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 53 - II. 0～n-1中缺失的数字
** link: https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/
** reference: 官方题解评论区，作者，是金猪啊，搜索，【宫水三叶】常规二段性分析运用题
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 定义左右边界
        int left = 0;
        int right = nums.size();

        while (left < right) {
            // 求出中间位置
            int mid = left + (right - left) / 2;

            if (mid == nums[mid]) {
                // 不可能存在mid>nums[mid]的情况

                left = mid + 1;
            } else {
                // mid < nums[mid]的情况

                right = mid;
            }
        }

        return left; // left，right均可以
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {0, 1, 3};

    Solution s;
    int res = s.missingNumber(nums);

    cout << res << endl;

    return 0;
}