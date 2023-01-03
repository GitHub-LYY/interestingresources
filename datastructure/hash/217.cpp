/*
** Author: Yangyang Liu
** Date: 2023-01-03
** Description: 217. 存在重复元素
** link: https://leetcode.cn/problems/contains-duplicate/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 定义set哈希表
        unordered_set<int> uset;

        for (int num : nums) { // 遍历数组
            if (uset.find(num) != uset.end()) { // num已经存在nums数组中了，则true
                return true;
            }

            uset.insert(num); // 每次循环把当前遍历的数字插入set
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 1};

    Solution s;
    bool res = s.containsDuplicate(nums);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}