/*
** Author: Yangyang Liu
** Date: 2022-11-16
** Description: 467. 环绕字符串中唯一的子字符串
** link: https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
** reference: 结合3个题解理解了，第一是b站视频，第二是fuxuemingzhu的题解，第三是最后看了官方题解理解了
** https://www.bilibili.com/video/BV1cB4y1X7cQ/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 题解区，搜索fuxuemingzhu，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 定义dp数组
        vector<int> dp(26, 0);

        // 定义变量保存一某个字符结尾的子字符串满足题目要求的数量
        int count = 0;

        // 遍历字符串
        for (int i = 0; i < p.size(); i++) {
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1) {
                // 相邻位置的字符是字母表中连续的

                count++;
            } else {
                count = 1; // 很巧妙，一箭双雕，不仅不连续要置1，上边if条件满足的时候的处理也需要先置为1
            }

            // 别忘了不能重复，因此，字符结尾的求最大的数量
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
        }

        // 把dp数组的数求和
        int res = 0;
        for (auto i : dp) {
            res += i;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string p = "a";

    Solution s;
    int res = s.findSubstringInWraproundString(p);

    cout << res << endl;

    return 0;
}