/*
** Author: Yangyang Liu
** Date: 2023-03-11
** Description: 275. H 指数 II
** link: https://leetcode.cn/problems/h-index-ii/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(); // 数组长度
        int left = 0;
        int right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (citations[mid] >= len - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return len - left;
    }
};

int main(int argc, char** argv) {
    vector<int> citations = {0, 1, 3, 5, 6};

    Solution s;
    int res = s.hIndex(citations);

    cout << res << endl;

    return 0;
}