/*
** Author: Yangyang Liu
** Date: 2022-09-11
** Description: 剑指 Offer 60. n个骰子的点数
** link: https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/
** reference: https://www.bilibili.com/video/BV1rT4y1D7QK?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
** c++版本参考题解区，搜索，【n个骰子的点数】：详解动态规划及其优化方式，作者，路漫漫我不畏
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 和最小是n，最大是6n，因此，结果的长度是6n-n+1=5n+1
        // 定义变量保存结果
        vector<double> res; // 这儿不用说几个元素了，直接是空的

        // 定义dp数组
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));

        // dp数组初始化
        for (int s = 1; s < 7; s++) {
            dp[1][s] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int s = i; s <= 6 * i; s++) { // 这是i，不是n了
                // 和的范围是n-6n

                //dp[i][s] = dp[i - 1][s - 1] + dp[i - 1][s - 2] + dp[i - 1][s - 3] + dp[i - 1][s - 4] + dp[i - 1][s - 5] + dp[i - 1][s - 6];
                // c++不能写成上边的，python行，c++的超出范围的它是未知的内存的数字了，所以不能
                // 再起一个循环，每次判断s减去1,2,3,4,5,6看看不超出范围则可以进行累加，否则，不用加，相当于加0
                for (int k = 1; k <= 6; k++) {
                    if  (s - k > 0) {
                        // 大于0了，才是有意义的值

                        dp[i][s] += dp[i - 1][s - k];
                    }
                }
            }
        }

        // 求出了每个和的个数了，该求概率了

        // 定义总的排列数
        double totalNum = pow(6, n); // 类型是double，一开始写错了

        for (int s = n; s <= 6 * n; s++) {
            double prob = dp[n][s] / totalNum;
            res.push_back(prob); // 结果插入 
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 2;

    Solution s;
    vector<double> res = s.dicesProbability(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}