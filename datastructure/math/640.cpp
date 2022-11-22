/*
** Author: Yangyang Liu
** Date: 2022-11-22
** Description: 640. 求解方程
** link: https://leetcode.cn/problems/solve-the-equation/
** reference: 题解区，官方题解，写的很好，比别的版本写的好，太厉害了
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        // 定义变量保存x的系数、常数项
        int factor = 0;
        int val = 0;

        // 定义变量保存正负号
        int sign1 = 1;

        // 定义索引
        int i = 0;

        // 遍历
        while (i < equation.size()) {
            // 首先判断等号的情况，下边的逻辑既能处理等号左边的，也能处理等号右边的
            if (equation[i] == '=') {
                sign1 = -1; // 变号了
                i++; // 要跳到下一个字符了，等号字符不用处理别的了
                continue; // 一定要有，直接跳到下一个字符再处理
            }

            // 处理正负号、数字，有可能是x的系数，也可能是常数项
            // 定义正负号2，定义number保存数值，定义valid标记数值是否不是1，这点需要思考才可以理解
            int sign2 = sign1; // sign2每次取sign1的值
            int number = 0;
            bool valid = false; // 默认值
            if (equation[i] == '+' || equation[i] == '-') {
                sign2 = (equation[i] == '+' ? sign1 : -sign1); // 也有没有正负号的情况，比如一开始的位置，执行不到这块，一开始写位1和-1了，错的，必须写位sign1和-sign1
                i++; // 别忘了，下次该遍历数值了
            }
            while (i < equation.size() && isdigit(equation[i])) {
                number *= 10;
                number += equation[i] - '0'; // 不断求出数值
                valid = true;
                i++; // 别忘了
            }

            // 该判断是x的系数还是常数项了
            if (i < equation.size() && equation[i] == 'x') {
                // 是x的系数项

                factor += (valid == true ? sign2 * number : sign2); // sign初始值1也可以用来进行求和，很巧妙
                i++; // 别忘了
            } else {
                // 是常数项

                val += (valid == true ? sign2 * number : sign2);
                // 这没有i++，因为不是x，则一定是正负号或者等号，因此直接下一轮循环即可，不可以i++
            }
        }

        // 判断异常情况
        if (factor == 0) {
            // x的系数是0

            return val == 0 ? "Infinite solutions" : "No solution"; // 仔细理解
        }

        int res = -val / factor;

        return "x=" + to_string(res);
    }
};

int main(int argc, char** argv) {
    string equation = "x+5-3+x=6+x-2";

    Solution s;
    string res = s.solveEquation(equation);

    cout << res << endl;

    return 0;
}