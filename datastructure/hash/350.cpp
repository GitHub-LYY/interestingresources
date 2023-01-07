/*
** Author: Yangyang Liu
** Date: 2023-01-07
** Description: 350. 两个数组的交集 II
** link: https://leetcode.cn/problems/intersection-of-two-arrays-ii/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // 减小空间复杂度，遍历长度小的数组填充哈希表
            return intersect(nums2, nums1); 
        }

        vector<int> res;
        unordered_map<int, int> num2num; // 数字-出现次数哈希表
        for (auto num : nums1) {
            num2num[num]++;
        }

        for (auto num : nums2) {
            if (num2num.count(num) > 0) { // 哈希表中出现数字num
                res.push_back(num); // 结果插入
                num2num[num]--; // 哈希表出现次数减一
                if (num2num[num] == 0) { // 要删除哈希表的num了
                    num2num.erase(num);
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution s;
    vector<int> res = s.intersect(nums1, nums2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}