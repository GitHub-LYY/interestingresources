/*
** Author: Yangyang Liu
** Date: 2022-08-15
** Description: 41. 缺失的第一个正数
** link: https://leetcode.cn/problems/first-missing-positive/
** reference: 题解区，搜索，【忍者算法】全网最清晰易懂的讲解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 先遍历一遍，把元素归位
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >=1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                // nums[i]必须在1到nums.size()之间，且它不在它该在的位置上

                // 交换nums[i]和nums[nums[i] - 1]的值
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 至此，元素已经归位

        // 再次遍历，找到第一个不在它该在的位置上的元素
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // 如果没有找到，说明数组中的元素都在它该在的位置上，返回数组长度加1
        return nums.size() + 1;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 0};

    Solution s;
    int res = s.firstMissingPositive(nums);

    cout << "The first missing positive is: " << res << endl;

    return 0;
}