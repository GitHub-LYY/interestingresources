/*
** Author: Yangyang Liu
** Date: 2022-11-26
** Description: 481. 神奇字符串
** link: https://leetcode.cn/problems/magical-string/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        // 定义生成的字符串
        string s(n, '0'); // 长度是n，用字符0初始化
        s[0] = '1'; // 前3个字符已经知道了，要初始化
        s[1] = '2';
        s[2] = '2';

        // 定义变量保存结果
        int res = 1; // 已经有一个1了

        // 定义i指针和j指针
        int i = 2; // 根据i指针不断求出后边的字符
        int j = 3; // 开始放置字符的位置

        while (j < n) {
            // j不能越界了，j一定比i走的快，因此判断j足够了

            // 求出j位置要放置的字符的size
            int size = s[i] - '0'; // 字符转int

            // 求出j位置要放置的字符的数字
            int num = 3 - (s[j - 1] - '0'); // 要么是1，要么是2，i位置是1，则求出2，i位置是2，则求出是1，括号是j-1，一开始写i，错的

            // 不断往j位置安放字符了
            while (size > 0 && j < n) {
                // size > 0才有意义

                s[j] = num + '0'; // 转换为字符放入字符串

                // 别忘了统计1的个数
                if (s[j] == '1') {
                    res++;
                }

                // 别忘了j要走到下一个位置了
                j++;

                // 别忘了size要--，一开始写的时候忘了
                size--;
            }

            // i位置处理忘了，别忘了i往后走
            i++;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n = 6;

    Solution s;
    int res = s.magicalString(n);

    cout << res << endl;

    return 0;
}