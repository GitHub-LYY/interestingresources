/*
** Author: Yangyang Liu
** Date: 2023-03-11
** Description: 658. 找到 K 个最接近的元素
** link: https://leetcode.cn/problems/find-k-closest-elements/
** reference: 题解区，官方题解，排序
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x] (int a, int b) -> bool {return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);});
        sort(arr.begin(), arr.begin() + k); // 数组已经根据题意排序了
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

int main(int argc, char** argv) {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    Solution s;
    vector<int> res = s.findClosestElements(arr, k, x);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}