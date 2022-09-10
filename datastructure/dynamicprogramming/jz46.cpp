/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 46. 把数字翻译成字符串
** link: https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
** reference: 官方题解评论区说的青蛙跳台阶，题解区搜索，把数字翻译成字符串 | 图解DP | 最清晰易懂的题解 【c++/java版本】，作者，林小鹿
** 二者结合着看，再配上代码随想录的思想，自己写
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        // 为了方便操作每一位的数字，转换为字符串
        string str = to_string(num);

        // 定义dp数组
        vector<int> dp(str.size() + 1);

        // dp数组初始化
        dp[0] = 1; // 1纯粹是为了后边的推导

        for (int i = 1; i <= str.size(); i++) {
            // i是从1开始的，根据dp数组的定义

            // 先考虑翻译一个数字的情况
            dp[i] = dp[i - 1];

            // 接下来考虑翻译两个连着的数字的情况
            if (i > 1) {
                // i必须大于1才有i-2成立的情况

                // 定义变量保存i，i-1位的数值
                int digits = (str[i - 2] - '0') * 10 + (str[i - 1] - '0'); // 只有两位，因此乘10

                // 判断数值是否在10-25之间，在才行
                if (digits >= 10 && digits <= 25) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[str.size()];
    }
};

int main(int argc, char** argv) {
    int num = 12258;

    Solution s;
    int res = s.translateNum(num);

    cout << res << endl;

    return 0;
}