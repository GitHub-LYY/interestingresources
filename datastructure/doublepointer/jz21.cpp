/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
** link: https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
** reference: 官方题解，双指针版本
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        // 定义数组保存结果
        vector<int> res(nums.size());

        // 定义前后指针指向res
        int left = 0;
        int right = res.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            // 遍历nums数组

            if (nums[i] % 2 == 1) {
                // 奇数，插入前边

                res[left++] = nums[i];
            } else {
                // 偶数，插入后边

                res[right--] = nums[i];
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4};

    Solution s;
    vector<int> res = s.exchange(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}