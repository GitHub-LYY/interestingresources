/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 189. 轮转数组
** link: https://leetcode.cn/problems/rotate-array/
** reference: 官方题解，数组翻转
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        // 定义变量保存数组长度
        int len = nums.size();

        // 求出最终的k值
        k %= len;

        // 翻转整个数组
        reverse(nums, 0, len - 1);

        // 翻转前k个元素
        reverse(nums, 0, k - 1);

        // 翻转后边的元素
        reverse(nums, k, len - 1);
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution s;
    s.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}