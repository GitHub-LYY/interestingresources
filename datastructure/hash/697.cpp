/*
** Author: Yangyang Liu
** Date: 2022-10-14
** Description: 697. 数组的度
** link: https://leetcode.cn/problems/degree-of-an-array/
** reference: 题解区，搜索，详细分析题意与思路，简洁代码，看完必懂，作者，负雪明烛
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 定义哈希表保存次数
        unordered_map<int, int> umap;

        // 定义哈希表保存第一次出现的位置
        unordered_map<int, int> left;

        // 定义哈希表保存最后一次出现的位置
        unordered_map<int, int> right;

        // 定义变量保存度
        int maxCount = INT_MIN;

        // 定义变量保存结果
        int len = INT_MAX;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++; // 当前数字出现次数

            maxCount = max(maxCount, umap[nums[i]]); // 更新度

            if (umap[nums[i]] == 1) {
                left[nums[i]] = i; // 记录首次出现位置
            }

            right[nums[i]] = i; // 最后一次出现的位置覆盖掉前边的位置
        }

        // 遍历次数哈希表
        for (auto it = umap.begin(); it != umap.end(); it++) {
            if (it->second == maxCount) {
                // 到这儿，则这个数是求出度的那个数，它有用

                len = min(len, right[it->first] - left[it->first] + 1);
            }
        }

        return len;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 2, 3, 1};

    Solution s;
    int res = s.findShortestSubArray(nums);

    cout << res << endl;
    
    return 0;
}