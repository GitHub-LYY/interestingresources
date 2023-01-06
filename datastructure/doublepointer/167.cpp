/*
** Author: Yangyang Liu
** Date: 2023-01-06
** Description: 167. 两数之和 II - 输入有序数组
** link: https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; // 指向开始位置
        int right = numbers.size() - 1; // 指向末尾位置

        for (int i = 0; i < numbers.size(); i++) {
            int sum = numbers[left] + numbers[right]; // 求出此时两个数字的和
            if (sum == target) { // 两个数字的和等于target了，则输出
                return {left + 1, right + 1}; // 题目下标从1开始，因此+1
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }

        return {-1, -1};
    }
};

int main(int argc, char** argv) {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> res = s.twoSum(numbers, target);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}