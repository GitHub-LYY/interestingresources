/*
** Author: Yangyang Liu
** Date: 2022-08-13
** Description: 215. 数组中的第K个最大元素
** link: https://leetcode.cn/problems/kth-largest-element-in-an-array/
** reference: 官方题解快速排序版本，自己理解后自己写的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums, int begin, int end) {
        // 选择第一个元素作为轴点元素
        int pivot = nums[begin];

        // end归位
        end--;

        // 从左到右遍历数组，将小于轴点元素的放到轴点元素的左边，大于轴点元素的放到轴点元素的右边
        while (begin < end) {
            while (begin < end) {
                if (nums[end] > pivot) {
                    end--;
                } else {
                    nums[begin++] = nums[end];
                    break;
                }
            }

            while (begin < end) {
                if (nums[begin] < pivot) {
                    begin++;
                } else {
                    nums[end--] = nums[begin];
                    break;
                }
            }
        }

        // begin == end，此时begin指向的元素就是轴点元素的正确位置
        nums[begin] = pivot;

        return begin;
    }

    int quickSortCore(vector<int>& nums, int k, int begin, int end) {
        // 如果只有一个元素，直接返回
        if (end - begin < 2) {
            return nums[begin];
        }

        // 求出pivot元素的索引
        int pivot = pivotIndex(nums, begin, end);

        // 如果pivot元素的索引是要求的，则返回
        if (pivot == nums.size() - k) {
            return nums[pivot];
        } else if (pivot > nums.size() - k) {
            // 如果pivot元素的索引大于要求的，则递归处理左边的元素
            return quickSortCore(nums, k, begin, pivot);
        } else {
            // 如果pivot元素的索引小于要求的，则递归处理右边的元素
            return quickSortCore(nums, k, pivot + 1, end);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // 在快速排序中求出第k大的元素
        int res = quickSortCore(nums, k, 0, nums.size());

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution s;
    int res = s.findKthLargest(nums, k);

    cout << "k th largest element is " << res << endl;

    return 0;
}