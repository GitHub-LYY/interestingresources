/*
** Author: Yangyang Liu
** Date: 2022-09-24
** Description: 495. 提莫攻击
** link: https://leetcode.cn/problems/teemo-attacking/
** reference: 题解区，搜索，【宫水三叶】简单模拟题
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 定义last变量保存上一个区间的结束位置
        int last = -1;

        // 定义变量保存结果
        int ans = 0;

        for (int i = 0; i < timeSeries.size(); i++) {
            int start = timeSeries[i];
            int end = start + duration - 1;

            if (start > last) {
                ans += duration;
                last = end; // 别忘了
            } else {
                // start <= last

                ans += end - last;
                last = end; // 别忘了
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> timeSeries = {1, 4};
    int duration = 2;

    Solution s;
    int res = s.findPoisonedDuration(timeSeries, duration);
    
    cout << res << endl;

    return 0;
}