/*
** Author: Yangyang Liu
** Date: 2022-10-21
** Description: 283. 移动零
** link: https://leetcode.cn/problems/move-zeroes/
** reference: 代码随想录，数组题的移除元素，类似，先移除0，再把后边的置为0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 定义慢指针
        int slow = 0;

        // 定义快指针遍历数组
        for (int fast = 0; fast < nums.size(); fast++) {
            // 关键是nums[fast] != 0

            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }

        // 此时的slow指向的刚好是要开始置为0的开始位置

        // 第二次遍历数组，从slow开始，到最后，把元素置为0
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }

        return;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution s;
    s.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}