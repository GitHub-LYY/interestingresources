/*
** Author: Yangyang Liu
** Date: 2023-01-16
** Description: 88. 合并两个有序数组
** link: https://leetcode.cn/problems/merge-sorted-array/
** reference: 题解区，官方题解，方法三，逆向双指针
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; // p1指向nums1数组尾部，有实际意义的尾部
        int p2 = n - 1; // p2指向nums2数组尾部
        int tail = m + n - 1; // tail指向nums1数组整个的尾部
        int cur = 0; // 定义变量保存当前遍历到的数字

        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) { // p1先越界，后边直接把nums2剩下的放入nums1对应位置
                cur = nums2[p2]; // 先临时保存当前遍历到的数字
                p2--; // 左移
            } else if (p2 == -1) { // p2先越界，后边直接把nums1剩下的放入nums1对应位置
                cur = nums1[p1]; // 先临时保存当前遍历到的数字
                p1--; // 左移
            } else if (nums1[p1] < nums2[p2]) { // p2的大
                cur = nums2[p2]; // 取出p2位置的数字
                p2--; // 左移
            } else {
                cur = nums1[p1]; // 取出p1位置的数字
                p1--; // 左移
            }
            nums1[tail] = cur; // 临时保存的值放入nums1对应tail位置
            tail--; // 不要忘记左移
        }
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}