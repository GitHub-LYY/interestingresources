/*
** Author: Yangyang Liu
** Date: 2022-12-30
** Description: 150. 逆波兰表达式求值
** link: https://leetcode.cn/problems/evaluate-reverse-polish-notation/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isNumber(string str) {
        return !(str == "+" || str == "-" || str == "*" || str == "/");
    }
    int evalRPN(vector<string>& tokens) {
        // 定义栈
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            // 取出当前字符串
            string token = tokens[i];

            if (isNumber(token)) {
                // 当前字符串是数字字符串

                stk.push(atoi(token.c_str())); // 字符串转换为数字插入栈
            } else {
                // 当前字符串是运算符

                // 取出栈顶的两个值
                int num2 = stk.top(); // 第一个是第二个运算的数
                stk.pop();
                int num1 = stk.top(); // 第二个是第二个运算的数
                stk.pop();

                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }

        return stk.top();
    }
};

int main(int argc, char **argv) {
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    Solution s;
    int res = s.evalRPN(tokens);

    cout << res << endl;

    return 0;
}