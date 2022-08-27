/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 128. 最长连续序列
** link: https://leetcode.cn/problems/longest-consecutive-sequence/
** reference: 题解区，搜索，最长连续序列 | 哈希 | 代码简洁易懂 【c++/java版】，作者，林小鹿
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;

        // 定义变量保存最长长度
        int maxLen = 0;
        
        // 把nums中的所有元素放入set
        for (int i = 0; i < nums.size(); i++) {
            uset.insert(nums[i]);
        }

        for (int num : uset) {
            if (uset.find(num - 1) == uset.end()) {
                // num-1不在uset集合中

                int y = num + 1; // 定义y求出最长连续序列的右边界

                while (uset.find(y) != uset.end()) {
                    y++;
                }
                maxLen = maxLen > (y - num) ? maxLen : (y - num);
            }
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution s;
    int res = s.longestConsecutive(nums);

    cout << "res:" << res << endl;

    return 0;
}