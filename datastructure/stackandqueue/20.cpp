/*
** Author: Yangyang Liu
** Date: 2022-12-31
** Description: 20. 有效的括号
** link: https://leetcode.cn/problems/valid-parentheses/
** reference: 题解区，官方题解，不学代码随想录的
*/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 异常情况，个数是奇数
        if (s.size() % 2 == 1) {
            return false;
        }

        // 定义哈希表保存右括号匹配的左括号
        unordered_map<char, char> pair = {{')', '('}, {']', '['}, {'}', '{'}};

        // 定义栈
        stack<char> stk;

        for (char c : s) {
            if (pair.find(c) != pair.end()) {
                // 哈希表的key存在，则是右括号

                if (stk.empty() || stk.top() != pair[c]) {
                    // 栈为空，或者栈顶不匹配

                    return false;
                }

                stk.pop(); // 这儿是匹配了，弹出栈顶
            } else {
                // 这是左括号，入栈

                stk.push(c);
            }
        }

        return stk.empty();
    }
};

int main(int argc, char **argv) {
    string s = "()";

    Solution sol;
    bool res = sol.isValid(s);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}