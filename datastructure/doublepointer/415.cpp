/*
** Author: Yangyang Liu
** Date: 2022-12-02
** Description: 415. 字符串相加
** link: https://leetcode.cn/problems/add-strings/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // 定义两个指针
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        // 定义变量保存进位
        int add = 0;

        // 定义变量保存结果
        string res;

        while (i >= 0 || j >= 0 || add != 0) {
            // 三个条件是或的关系，仔细品味

            // 每一次取出对应位置的数值
            int x = i >= 0 ? num1[i] - '0' : 0; // 没有越界，则拿出数值，否则，拿出0
            int y = j >= 0 ? num2[j] - '0' : 0;

            int num = x + y + add; // 别忘了进位也要运算

            // 插入结果
            res.push_back(num % 10 + '0'); // 转换为字符的数字再插入

            // 计算add进位
            add = num / 10; // 一开始写位add /= 10了，错的

            // 一开始忘记写指针的减减了，错的
            i--;
            j--;
        }

        // 因为push back是一直往末尾插入，因此要reverse一下
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main(int argc, char** argv) {
    string num1 = "11";
    string num2 = "123";

    Solution s;
    string res = s.addStrings(num1, num2);

    cout << res << endl;

    return 0;
}