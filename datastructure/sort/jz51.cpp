/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 剑指 Offer 51. 数组中的逆序对
** link: https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
** reference: 官方题解，归并排序
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int begin, int mid, int end, int& invCnt) {
        // 定义三个指针
        int left = begin;
        int right = mid;
        int index = 0; 

        // 开始合并
        while (left < mid && right < end) {
            if (nums[left] <= nums[right]) {
                vec[index++] = nums[left++];
            } else {
                vec[index++] = nums[right++];
                invCnt += mid - left; // 左边大于右边，存在逆序对
            }
        }

        while (left < mid) {
            vec[index++] = nums[left++];
        }

        while (right < end) {
            vec[index++] = nums[right++];
        }

        // 把vec中的元素拷贝回nums，忘记写这块了，结果是6，错误
        for (int i = begin; i < end; i++) {
            nums[i] = vec[i - begin];
        }
    }

    int mergeSortCore(vector<int>& nums, int begin, int end) {
        // 递归终止条件
        if (end - begin < 2) {
            return 0;
        }

        // 求出中间位置
        int mid = begin + (end - begin) / 2;

        // 递归处理左边
        int invCntLeft = mergeSortCore(nums, begin, mid);

        // 递归处理右边
        int invCntRight = mergeSortCore(nums, mid, end);

        int invCnt = invCntLeft + invCntRight;

        // 合并
        merge(nums, begin, mid, end, invCnt);

        return invCnt;
    }

    vector<int> vec;

    int reversePairs(vector<int>& nums) {
        vec = vector<int>(nums.size(), 0);

        // 归并排序，修改版的
        int res = mergeSortCore(nums, 0, nums.size());

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {7, 5, 6, 4};

    Solution s;
    int res = s.reversePairs(nums);

    cout << "reverse pairs: " << res << endl;

    return 0;
}