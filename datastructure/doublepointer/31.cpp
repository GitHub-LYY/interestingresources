/*
** Author: Yangyang Liu
** Date: 2022-08-15
** Description: 31. 下一个排列
** link: https://leetcode.cn/problems/next-permutation/
** reference: 题解区，搜索，【忍者算法】全网最清晰易懂题解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            // i指针不断往前移动
            for (int j = nums.size() - 1; j > i; j--) {
                // j指针不能超越i指针，活动范围限定在最后到i之间

                if (nums[j] > nums[i]) {
                    // 如果j位置的元素大于i位置的元素了，则交换两个位置的元素
                    swap(nums[i], nums[j]);

                    // 交换完之后，把i之后位置的元素进行升序
                    sort(nums.begin() + i + 1, nums.end());

                    return;
                }
            }
        }

        // 如果到这儿了，则当前的排列是最大的了，把最小的返回
        sort(nums.begin(), nums.end());
        return;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};

    Solution s;
    s.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}