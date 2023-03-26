/*
** Author: Yangyang Liu
** Date: 2023-03-25
** Description: 373. 查找和最小的 K 对数字
** link: https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/
** reference: 官方题解的不容易理解，没有理解，自己思考后，自己写的。自己写的超时了。最后必须参考官方题解。直接读代码，比题解容易理解。
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res; // 结果
        auto cmp = [&nums1, &nums2] (const pair<int, int>& a, const pair<int, int>& b) { // 小顶堆仿函数
            return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pri_que(cmp); // 小顶堆
        int len1 = nums1.size(); // 数组一的长度
        int len2 = nums2.size(); // 数组二的长度

        for (int i = 0; i < min(k, len1); i++) { // 第一个数组的数字和第二个数组的第一个数字组成对组
            pri_que.push(make_pair(i, 0));
        }

        while (k-- > 0 && !pri_que.empty()) { // k消耗完
            auto [x, y] = pri_que.top(); // 取出堆顶
            pri_que.pop(); // 出堆
            res.emplace_back(vector<int>{nums1[x], nums2[y]}); // 插入结果
            if (y + 1 < len2) { // 再取第二个数组的下一个数
                pri_que.emplace(make_pair(x, y + 1)); 
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution s;
    vector<vector<int>> res = s.kSmallestPairs(nums1, nums2, k);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}