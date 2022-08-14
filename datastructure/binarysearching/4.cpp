/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 4. 寻找两个正序数组的中位数
** link: https://leetcode.cn/problems/median-of-two-sorted-arrays/
** reference: 官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 求出两个数组的长度
        int m = nums1.size();
        int n = nums2.size();

        // 令nums1是最短的数组，后边全是在nums1上进行二分搜索
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // 定义nums1数组上的left和right指针
        int left = 0;
        int right = nums1.size(); // 左闭右开

        // 定义变量保存中位数
        int leftMax = 0;
        int rightMin = 0;
        double res = 0; // 定位为int，LeetCode出错
        
        // 二分搜索
        while (left <= right) {
            // 求出nums1数组上的中间位置
            int i = left + (right - left) / 2; // i是nums1数组上的中间位置

            // 求出nums2数组上的中间位置
            int j = (m + n + 1) / 2 - i; // j是nums2数组上的中间位置

            // 有了i，j，能求出i-1，i，j-1，j四个位置上的元素
            int nums1im1 = (i == 0) ? INT32_MIN : nums1[i - 1]; // i左边没有元素也要处理一下
            int nums1i = (i == m) ? INT32_MAX : nums1[i]; // i右边没有元素也要处理一下
            int nums2jm1 = (j == 0) ? INT32_MIN : nums2[j - 1]; // j左边没有元素也要处理一下
            int nums2j = (j == n) ? INT32_MAX : nums2[j]; // j右边没有元素也要处理一下

            // 判断a[i-1]和b[j]的大小关系
            if (nums1im1 <= nums2j) {
                // 暂时满足，记录一下
                leftMax = max(nums1im1, nums2jm1);
                rightMin = min(nums1i, nums2j);
                left = i + 1; // 求最大的i
            } else {
                // a[i-1] > b[j]了，往左边缩小区间

                right = i - 1;
            }
        }

        // 判断总长度是奇数还是偶数
        if ((m + n) % 2 == 0) {
            // 总长度是偶数

            res = (leftMax + rightMin) / 2.0;
        } else {
            // 奇数

            res = (double)leftMax;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution s;
    double res = s.findMedianSortedArrays(nums1, nums2);

    cout << "median of two sorted arrays is: " << res << endl;

    return 0;
}