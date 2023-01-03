/*
** Author: Yangyang Liu
** Date: 2023-01-03
** Description: 349. 两个数组的交集
** link: https://leetcode.cn/problems/intersection-of-two-arrays/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1); // 第一个参数size小于第二个参数size
        }

        vector<int> intersection; // 定义变量保存结果

        for (int num : set1) {
            if (set2.find(num) != set2.end()) {
                intersection.push_back(num);
            }
        }

        return intersection;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1; // 定义set
        unordered_set<int> uset2;

        for (int num : nums1) {
            uset1.insert(num); // 插入set，去重插入
        }
        for (int num : nums2) {
            uset2.insert(num);
        }

        return getIntersection(uset1, uset2);
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution s;
    vector<int> res = s.intersection(nums1, nums2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}