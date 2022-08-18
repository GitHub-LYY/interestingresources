/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 43. 字符串相乘
** link: https://leetcode.cn/problems/multiply-strings/
** reference: 题解区，搜索，高频面试系列：字符串乘法，作者labuladong
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // 定义变量保存两个字符串的长度
        int len1 = num1.size();
        int len2 = num2.size();

        // 定义变量保存结果
        vector<int> res(len1 + len2, 0);

        // 从后往前遍历两个字符串
        for (int i = len2 - 1; i >= 0; i--) {
            for (int j = len1 - 1; j >= 0; j--) {
                // 定义变量保存当前两个字符相乘的结果
                int mulVal = (num2[i] - '0') * (num1[j] - '0');

                // 定义变量保存当前两个字符相乘的结果要放置在res数组中的位置
                int pos1 = i + j;
                int pos2 = i + j + 1;

                // 定义变量保存当前两个字符相乘的结果要放置在res数组中的位置的值
                int sum = mulVal + res[pos2]; // 在没有计算完的中间，有进位的情况，因此，某一个位保存一个两位数，但是计算完之后，是不存在的

                // 更新res数组
                res[pos2] = sum % 10;
                res[pos1] += sum / 10;
            }
        }

        // 定义索引进行遍历
        int index = 0;
        while (index < res.size() && res[index] == 0) {
            index++;
        }

        // 到此，index指向第一个非零元素

        // 定义变量保存结果
        string str;

        // 继续遍历res数组，将非零元素拼接到str中
        while (index < res.size()) {
            str += (res[index] + '0');
            index++;
        }

        return str == "" ? "0" : str; // 这必须要判断，否则，会出现空字符串的情况
    }
};

int main(int argc, char** argv) {
    string num1 = "2";
    string num2 = "3";

    Solution s;
    string res = s.multiply(num1, num2);

    cout << "multiply result: " << res << endl;

    return 0;
}