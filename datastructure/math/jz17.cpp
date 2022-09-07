/*
** Author: Yangyang Liu
** Date: 2022-09-07
** Description: 剑指 Offer 17. 打印从1到最大的n位数
** link: https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
** reference: https://www.bilibili.com/video/BV1pv411B7yD?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** Bobbi520，b站up
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int quickMul(int x, long long n) {
        int res = 1;
        int xContri = x;
        while (n > 0) {
            if (n % 2 == 1) {
                // n的二进制最后一位是1

                res *= xContri;
            }

            xContri *= xContri;
            n /= 2;
        }

        return res;
    }

    int myPow(int x, long long n) {
        return n > 0 ? quickMul(x, n) : 1 / quickMul(x, n);
    }
public:
    vector<int> printNumbers(int n) {
        // 定义变量保存结果
        vector<int> res;

        // 求出10的n次方
        int num = myPow(10, n);

        // 遍历1-num，插入res
        for (int i = 1; i < num; i++) {
            res.push_back(i);
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 1;

    Solution s;
    vector<int> res = s.printNumbers(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}