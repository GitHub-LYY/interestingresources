/*
** Author: Yangyang Liu
** Date: 2022-09-14
** Description: 剑指 Offer 62. 圆圈中最后剩下的数字
** link: https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
** reference: https://www.bilibili.com/video/BV193411c7nE?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 这题是数学公式，记好
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int f(int n, int m) {
        if (n <= 1) {
            return 0;
        }

        return (f(n - 1, m) + m) % n;
    }

    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};

int main(int argc, char** argv) {
    int n = 5;
    int m = 3;

    Solution s;
    int res = s.lastRemaining(n, m);

    cout << res << endl;
    
    return 0;
}