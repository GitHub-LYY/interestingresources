/*
** Author: Yangyang Liu
** Date: 2022-09-11
** Description: 264. 丑数 II
** link: https://leetcode.cn/problems/ugly-number-ii/
** reference: https://www.bilibili.com/video/BV1D341177zj?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // 定义三个指针
        int twoPtr = 0;
        int threePtr = 0;
        int fivePtr = 0;

        // 定义变量保存丑数
        vector<int> uglyVec(n, 0); // 丑数数组

        // 第一个丑数是一
        uglyVec[0] = 1;

        for (int i = 1; i < n; i++) {
            uglyVec[i] = min(uglyVec[twoPtr] * 2, min(uglyVec[threePtr] * 3, uglyVec[fivePtr] * 5)); // 求出每一个丑数，2,3,5倍数取最小

            if (uglyVec[i] == uglyVec[twoPtr] * 2) {
                // 是2的倍数，则把two指针移动到后一个丑数上

                twoPtr++;
            }

            if (uglyVec[i] == uglyVec[threePtr] * 3) {
                // 是3的倍数，则把three指针移动到后一个丑数上，three指针不再参到这个丑数的乘法了

                threePtr++;
            }

            if (uglyVec[i] == uglyVec[fivePtr] * 5) {
                // 是5的倍数，则把five指针移动到后一个丑数上

                fivePtr++;
            }
        }

        // 以上求出了前n个丑数，是按顺序排列的

        return uglyVec[n - 1];
    }
};

int main(int argc, char** argv) {
    int n = 10;

    Solution s;
    int res = s.nthUglyNumber(n);

    cout << res << endl;

    return 0;
}