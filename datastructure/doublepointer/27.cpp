/*
** Author: Yangyang Liu
** Date: 2022-10-21
** Description: 27. 移除元素
** link: https://leetcode.cn/problems/remove-element/
** reference: 代码随想录，数组题的移除元素
** 20210113，官方题解，容易理解，不要参考代码随想录了
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElementOld(vector<int>& nums, int val) {
        // 定义慢指针
        int slow = 0;

        // 定义快指针遍历数组
        for (int fast = 0; fast < nums.size(); fast++) {
            // 关键是nums[fast] != val

            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }

        return slow;
    }

    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(); // 定义变量保存数组长度
        int left = 0; // left指向要被赋值的位置，也指向最终的结果位置

        for (int right = 0; right < len; right++) {
            if (nums[right] != val) { // right位置遍历的数字不等于val了，则要更新left位置的数字了
                nums[left] = nums[right]; // 更新left位置的数字
                left++; // left指针右移
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution s;
    int res = s.removeElement(nums, val);

    cout << res << endl;

    return 0;
}