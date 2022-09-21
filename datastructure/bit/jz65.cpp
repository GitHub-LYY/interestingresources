/*
** Author: Yangyang Liu
** Date: 2022-09-21
** Description: 剑指 Offer 65. 不用加减乘除做加法
** link: https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1uF411E7fS/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

int main(int argc, char** argv) {
    int a = 1;
    int b = 1;

    Solution s;
    int res = s.add(a, b);

    cout << res << endl;

    return 0;
}