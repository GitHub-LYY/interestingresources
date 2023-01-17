/*
** Author: Yangyang Liu
** Date: 2023-01-17
** Description: 475. 供暖器
** link: https://leetcode.cn/problems/heaters/
** reference: 题解区，官方题解
** https://www.bilibili.com/video/BV1F5411f78w/?spm_id_from=333.337.search-card.all.click
** b站up，第6种自由，视频听一听，官方题解容易理解了
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end()); // 一定先做排序
        sort(heaters.begin(), heaters.end());
        int res = 0; 

        for (int i = 0, j = 0; i < houses.size(); i++) {
            int curDistance = abs(houses[i] - heaters[j]); // 距离初始化
            
            // 遍历heaters数组，求出最小的距离
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j] >= abs(houses[i] - heaters[j + 1]))) {
                j++; // j往后走
                curDistance = min(curDistance, abs(houses[i] - heaters[j])); // 求出当前房子和供暖器的最近距离，j已经++了，因此这儿是j
            }

            res = max(curDistance, res); // 取每个房子最近距离中的最大值
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {2};

    Solution s;
    int res = s.findRadius(houses, heaters);

    cout << res << endl;

    return 0;
}