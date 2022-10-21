/*
** Author: Yangyang Liu
** Date: 2022-10-21
** Description: 27. 移除元素
** link: https://leetcode.cn/problems/remove-element/
** reference: 代码随想录，数组题的移除元素
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
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
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution s;
    int res = s.removeElement(nums, val);

    cout << res << endl;

    return 0;
}