/*
** Author: Yangyang Liu
** Date: 2022-11-20
** Description: 537. 复数乘法
** link: https://leetcode.cn/problems/complex-number-multiplication/
** reference: 题解区，搜索，【微扰理论】C++模拟题｜find+substr+stoi，说的很好
** 官方题解很复杂，不要参考了
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // 把两个复数写出来方便理解
        // a+bi
        // c+di

        // 求出两个复数+号的位置
        int plusIndex1 = num1.find('+');
        int plusIndex2 = num2.find('+');

        // 使用+号的位置分割实部和虚部，转换为int型的
        int a = stoi(num1.substr(0, plusIndex1));
        int b = stoi(num1.substr(plusIndex1 + 1, num1.size() - 1)); // 不包含最后的i，巧妙
        int c = stoi(num2.substr(0, plusIndex2));
        int d = stoi(num2.substr(plusIndex2 + 1, num2.size() - 1));

        int real = a * c - b * d; // 模拟
        int imag = a * d + b * c;

        return to_string(real) + '+' + to_string(imag) + 'i';
    }
};

int main(int argc, char** argv) {
    string num1 = "1+1i";
    string num2 = "1+1i";

    Solution s;
    string res = s.complexNumberMultiply(num1, num2);

    cout << res << endl;

    return 0;
}