/*
** Author: Yangyang Liu
** Date: 2022-12-21
** Description: 670. 最大交换
** link: https://leetcode.cn/problems/maximum-swap/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // 定义变量保存结果
        int res = num; // 一开始写位了INT_MIN，错的

        // 数字转字符串
        string charArray = to_string(num);

        for (int i = 0; i < charArray.size(); i++) {
            for (int j = i + 1; j < charArray.size(); j++) {
                swap(charArray[i], charArray[j]); // 交换两个位置
                res = max(res, stoi(charArray)); // 求出最大值
                swap(charArray[i], charArray[j]); // 再交换这两个位置
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int num = 2736;

    Solution s;
    int res = s.maximumSwap(num);

    cout << res << endl;

    return 0;
}