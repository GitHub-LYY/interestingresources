/*
** Author: Yangyang Liu
** Date: 2022-08-23
** Description: 135. 分发糖果
** link: https://leetcode.cn/problems/candy/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // 定义变量保存结果，初始化为1,
        vector<int> candyVec(ratings.size(), 1);

        // 从前往后遍历
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        // 从后往前遍历
        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1]) {
                candyVec[j] = max(candyVec[j], candyVec[j + 1] + 1);
            }
        }

        int res = 0;
        for (int i = 0; i < candyVec.size(); i++) {
            res += candyVec[i];
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> ratings = {1, 0, 2};

    Solution s;
    int res = s.candy(ratings);

    cout << "res:" << res << endl;

    return 0;
}