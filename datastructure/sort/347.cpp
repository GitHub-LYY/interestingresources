/*
** Author: Yangyang Liu
** Date: 2023-03-26
** Description: 347. 前 K 个高频元素
** link: https://leetcode.cn/problems/top-k-frequent-elements/
** reference: 官方题解
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    class Cmp {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2count; // 数字-次数哈希表
        for (int i = 0; i < nums.size(); i++) { // 填充哈希表
            num2count[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pri_que;
        for (auto numcount : num2count) { // 填充小顶堆
            if (pri_que.size() == k) { // 小顶堆已经有k个数了
                if (pri_que.top().second < numcount.second) { // 此时的次数比堆顶大，则弹出堆顶
                    pri_que.pop(); // 弹出堆顶
                    pri_que.emplace(numcount.first, numcount.second); // 插入堆维持k个数
                }
            } else { // 小顶堆数小于k
                pri_que.emplace(numcount.first, numcount.second);
            }
        }

        vector<int> res;
        while (!pri_que.empty()) { // 此时的堆是k个最大的
            res.emplace_back(pri_que.top().first);
            pri_que.pop();
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution s;
    vector<int> res = s.topKFrequent(nums, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}