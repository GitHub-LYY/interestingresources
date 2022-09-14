/*
** Author: Yangyang Liu
** Date: 2022-09-14
** Description: 剑指 Offer 64. 求1+2+…+n
** link: https://leetcode.cn/problems/qiu-12n-lcof/
** reference: https://www.bilibili.com/video/BV1qY411L7b3?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** you only live once，剑指offer说的特别好
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        // 使用递归

        // 递归结束条件
        if (n == 1) {
            return 1;
        }

        return sumNums(n - 1) + n;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    int res = s.sumNums(n);

    cout << res << endl;
    
    return 0;
}