/*
** Author: Yangyang Liu
** Date: 2022-11-02
** Description: 238. 除自身以外数组的乘积
** link: https://leetcode.cn/problems/product-of-array-except-self/
** reference: 官方题解，方法二，空间复杂度为O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 定义结果数组
        vector<int> res(nums.size());

        // 第一次从前往后遍历，求出每个元素左边的乘积，保存在结果数组中
        res[0] = 1; // 第0个元素左边初始化为1，因为是做乘积运算
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1]; // 每个元素（不包含这个元素）左边数字的乘积
        }

        // 定义变量保存右边的乘积，这个乘积是临时的，用一个遍历即可
        int rightMul = 1; // 最后一个元素右边乘积初始化为1
        // 第二次从后往前遍历，求出结果
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = res[i] * rightMul; // 最后一个元素开始，先有这句，再有下句求右边乘积
            rightMul *= nums[i]; // 巧妙
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4};

    Solution s;
    vector<int> res = s.productExceptSelf(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}