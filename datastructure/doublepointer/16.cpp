/*
** Author: Yangyang Liu
** Date: 2023-01-13
** Description: 16. 最接近的三数之和
** link: https://leetcode.cn/problems/3sum-closest/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void updateBest(const int target, int& best, const int sum) {
        int diffOld = abs(best - target); // 求出旧的差
        int diffNew = abs(sum - target); // 求出当前的差
        if (diffNew < diffOld) { // 当前新的差更小，则要更新了
            best = sum; // 这个可能是答案
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 先排序
        int len = nums.size(); // 保存数组长度
        int best = 1e7; // 保存结果，三数之和，选一个大点的数字，方便更新别的值

        for (int i = 0; i < len; i++) { // i指针先固定下来，不断逼近j和k的位置
            if (i > 0 && nums[i] == nums[i - 1]) { // 优化，不要也行，去除重复的i位置的数字
                continue; // 一开始写成i++了，错的
            }

            int j = i + 1; // j是i+1的位置
            int k = len - 1; // k是最后一个位置
            while (j < k) { // 双指针经典写法
                int sum = nums[i] + nums[j] + nums[k]; // 求出当前三数之和备用
                if (sum == target) { // 优化，不要也行，等于target了，则没有比当前他们差值更小的和了
                    return sum;
                }
                updateBest(target, best, sum);
                if (sum > target) { // 意味着k要左移了
                    int kTmp = k - 1;
                    while (j < kTmp && nums[kTmp] == nums[k]) { // 优化，不要也行，去掉重复数字
                        kTmp--;
                    }
                    k = kTmp; // 更新k的值
                } else {
                    int jTmp = j + 1;
                    while (jTmp < k && nums[jTmp] == nums[j]) { // 优化，不要也行，去掉重复数字
                        jTmp++;
                    }
                    j = jTmp; // 更新j的值
                }
            }
        }

        return best;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution s;
    int res = s.threeSumClosest(nums, target);

    cout << res << endl;

    return 0;
}