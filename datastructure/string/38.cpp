/*
** Author: Yangyang Liu
** Date: 2022-11-22
** Description: 38. 外观数列
** link: https://leetcode.cn/problems/count-and-say/
** reference: 题解区，官方题解，方法一，写的很好，比别的版本写的好，太厉害了
** 忍者算法也有，但是觉得官方题解的容易理解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // 定义变量保存上一个字符串
        string pre = "1"; // 一开始的值是1

        // 从2开始遍历到n，包含n
        for (int i = 2; i <= n; i++) {
            string cur = ""; // 每次求出上一个字符串的外观数列是当前的字符串的值
            int start = 0; // 统计每个字符的开始位置
            int j = 0; // 不断遍历每个字符串的字符，一开始写位i了，错的

            // 遍历上一个字符串
            while (j < pre.size()) {
                while (j < pre.size() && pre[j] == pre[start]) {
                    // 把i走到不同的字符的位置求次数

                    j++;
                }

                cur += to_string(j - start) + pre[start]; // 次数、字符，不断拼接
                start = j; // 开始另外的一个字符了
            }

            pre = cur; // 上一个改变了
        }

        return pre;
    }
};

int main(int agrc, char** argv) {
    int n = 4;

    Solution s;
    string res = s.countAndSay(n);

    cout << res << endl;

    return 0;
}