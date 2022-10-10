/*
** Author: Yangyang Liu
** Date: 2022-10-10
** Description: 628. 三个数的最大乘积
** link: https://leetcode.cn/problems/maximum-product-of-three-numbers/
** reference: 官方题解，方法二，线性扫描
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 定义变量保存最大值，第二大的值，第三大的值
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        // 定义变量保存最小值，第二小的值
        int min1 = INT_MAX;
        int min2 = INT_MAX; // 初始化是方便能赋值

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                // 比最大值还大，则最大值必须更新，连带更新第二大和第三大的值

                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                // 比第二大值还大，则更新第二大的值，连带更新第三大的值

                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] > max3) {
                // 比第三大的值还大，则更新第三大的值，没有连带更新

                max3 = nums[i];
            }

            if (nums[i] < min1) {
                // 比最小值还小，则最小值必须更新，连带更新第二小的值

                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                // 比第二小的值还小，则更新第二小的值，没有连带更新

                min2 = nums[i];
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};

    Solution s;
    int res = s.maximumProduct(nums);

    cout << res << endl;

    return 0;
}