/*
** Author: Yangyang Liu
** Date: 2022-08-21，2023-03-28
** Description: 224. 基本计算器
** link: https://leetcode.cn/problems/basic-calculator/
** reference: 题解区，搜索，拆解复杂问题：实现一个完整计算器，作者，labuladong，搜索，labuladong，参考
** 20230328，官方题解，没有很多弯弯绕绕，容易理解
*/

#include <iostream>
#include <stack>

using namespace std;

class SolutionOld {
private:
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    int helper(string& s, int& index) {
        // 定义栈保存数字
        stack<int> st;

        // 定义符号位
        char sign = '+'; // 默认为正号

        // 定义变量保存要放入栈的数字
        int num = 0;

        // 遍历字符串
        for (index; index < s.size(); index++) {
            // 如果是数字，则计算数字
            char c = s[index];
            if (isDigit(c)) {
                num = num * 10 + (c - '0');
            }

            // 如果是左括号，则递归计算括号内的值
            if (c == '(') {
                num = helper(s, ++index);
            }

            // 如果是符号位或者是最后一个字符，则根据符号位决定入栈的是正数或者负数
            if ((!isDigit(c) && c != ' ') || index == s.size() - 1) {
                switch (sign) {
                    case '+' :
                        st.push(num);
                        break;
                    case '-' :
                        st.push(-num);
                        break;
                }

                // 更新符号位
                sign = c;

                // num归位
                num = 0;
            }

            // 如果是右括号，则结束递归
            if (c == ')') {
                break;
            }
        }

        // for循环结束后，所有数字已经进入栈，求和得到结果
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
public:
    int calculate(string s) {
        int index = 0;
        return helper(s, index);
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<int> ops; // 栈
        ops.push(1); // 默认是1
        int sign = 1; // 符号
        int res = 0;
        int len = s.size(); // 字符串长度
        int i = 0; // 索引

        while (i < len) {
            if (s[i] == ' ') { // 空格字符
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else { // 数字字符
                long num = 0; // 数字
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += sign * num;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "(1+(4+5+2)-3)+(6+8)";

    Solution sol;
    int res = sol.calculate(s);

    cout << "res: " << res << endl;

    return 0;
}