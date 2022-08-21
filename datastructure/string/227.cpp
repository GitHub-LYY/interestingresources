/*
** Author: Yangyang Liu
** Date: 2022-08-21
** Description: 227. 基本计算器 II
** link: https://leetcode.cn/problems/basic-calculator-ii/
** reference: 题解区，搜索，拆解复杂问题：实现一个完整计算器，作者，labuladong，搜索，labuladong，参考
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
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
            // 取出index索引的字符
            char c = s[index];

            // 如果是数字，则计算数字
            if (isDigit(c)) {
                num = num * 10 + (c - '0');
            }

            // 如果是左括号，则递归计算括号内的值
            if (c == '(') {
                num = helper(s, ++index);
            }

            // 如果是符号位或者是最后一个字符，则根据符号位决定入栈的是正数或者负数
            if ((!isDigit(c) && c != ' ') || index == s.size() - 1) {
                int tmp = 0;
                switch (sign) {
                    case '+' :
                        st.push(num);
                        break;
                    case '-' :
                        st.push(-num);
                        break;
                    case '*' :
                        tmp = st.top();
                        st.pop();
                        st.push(tmp * num);
                        break;
                    case '/' :
                        tmp = st.top();
                        st.pop();
                        st.push(tmp / num);
                        break;
                }

                // 更新符号位
                sign = c;

                // num归位
                num = 0;     
            }

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

    int calculate(string s) {
        int index = 0;
        return helper(s, index);
    }
};

int main(int argc, char** argv) {
    string s = "3+2*2";

    Solution sol;
    int res = sol.calculate(s);

    cout << "res: " << res << endl;

    return 0;
}