/*
** Author: Yangyang Liu
** Date: 2023-01-14
** Description: 611. 有效三角形的个数
** link: https://leetcode.cn/problems/valid-triangle-number/
** reference: 题解区，搜索，明确条件进行求解，作者，Jerring，官方题解不容易理解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0; // 定义变量保存结果
        sort(nums.begin(), nums.end()); // 一定要做排序
        int len = nums.size(); // 数组长度

        for (int i = len - 1; i >= 2; i--) { // i从最后一个数字开始
            int left = 0;
            int right = i - 1; // left和right不断逼近
            while (left < right) { // 一开始忘记写while循环了
                if (nums[left] + nums[right] > nums[i]) { // 满足条件
                    res += right - left; // 求和
                    right--; // 左移，把和变小点
                } else { // 不满足条件，把和变大点
                    left++;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 2, 3, 4};

    Solution s;
    int res = s.triangleNumber(nums);

    cout << res << endl;

    return 0;
}