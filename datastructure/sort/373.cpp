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
        auto
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