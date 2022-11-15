/*
** Author: Yangyang Liu
** Date: 2022-11-15
** Description: 696. 计数二进制子串
** link: https://leetcode.cn/problems/count-binary-substrings/
** reference: 题解区，官方题解，方法二，空间复杂度为O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        // 定义变量保存上一个字符的次数
        int numPre = 0;

        // 定义变量保存结果
        int res = 0;

        // 定义遍历字符串的指针
        int i = 0;

        // 遍历字符串
        //for (int i = 0; i < s.size();) { // 不要使用for循环了，使用for循环，不要i++否则错误
        while (i < s.size()) {
            char c = s[i]; // 记录当前遍历的字符
            int count = 0; // 记录这个字符的次数
            while (i < s.size() && s[i] == c) {
                count++;
                i++;
            }
            res += min(count, numPre); // 两个取最小的
            numPre = count; // 下一个开始了
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "00110011";

    Solution sol;
    int res = sol.countBinarySubstrings(s);

    cout << res << endl;

    return 0;
}