/*
** Author: Yangyang Liu
** Date: 2022-11-21
** Description: 592. 分数加减运算
** link: https://leetcode.cn/problems/fraction-addition-and-subtraction/
** reference: 题解区，官方题解，说的很好
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        // 定义分子、分母不断求运算
        int x = 0;
        int y = 1; // x/y=0，原始数据

        // 定义索引进行遍历
        int i = 0;

        // 遍历
        while (i < expression.size()) {
            // 遍历中的每一次求的分子、分母
            int x1 = 0;
            int y1 = 0; // 初始值全部为0，一开始写了1，错的

            // 定义每次分式前边的符号，把它放到分子的前边
            int sign = 1; // 默认是1，代表正数

            // 先判断正负号
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '+' ? 1 : -1);
                i++;
            }

            // 取出分子
            while (i < expression.size() && isdigit(expression[i])) {
                x1 *= 10;
                x1 += expression[i] - '0'; // 不断求出分子

                i++;
            }
            x1 = sign * x1; // 把正负号每次放到分子上
            i++; // 很重要，把/跳走，很巧妙，一开始忘记了，错了

            // 取出分母
            while (i < expression.size() && isdigit(expression[i])) {
                y1 *= 10;
                y1 += expression[i] - '0';

                i++;
            }

            // 不断进行分式的运算
            x = x * y1 + x1 * y; // 分子已经包括了正负号了，直接运算
            y = y * y1; // 分母

            // 不用i++了，因为此时的i已经到了下一位了
        }

        // 如果结果是0，要用分式输出
        if (x == 0) {
            return "0/1"; // 结果是0时候的输出形式
        }

        // 结果不是0，则求出最大公约数，用到库函数gcd
        int g = __gcd(abs(x), y); // 别忘了abs分子，分子包括了正负号

        return to_string(x / g) + '/' + to_string(y / g);
    }
};

int main(int argc, char** argv) {
    string expression = "-1/2+1/2";

    Solution s;
    string res = s.fractionAddition(expression);

    cout << res << endl;

    return 0;
}