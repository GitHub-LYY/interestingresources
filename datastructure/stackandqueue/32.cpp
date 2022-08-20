/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 32. 最长有效括号
** link: https://leetcode.cn/problems/longest-valid-parentheses/
** reference: b站，搜索k个一组的时候的那个up
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // 定义栈
        stack<int> st; // 栈保存的是下标，因此是int

        // 初始化栈
        st.push(-1);

        // 定义变量保存最大长度
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // 遍历s字符串

            // 如果当前字符是左括号，入栈
            if (s[i] == '(') {
                st.push(i); // 下标入栈
            } else {
                // 如果当前字符是右括号

                st.pop(); // 先出栈

                // 接下来再判断

                if (st.empty()) {
                    // 如果栈为空，则当前右括号的索引入栈

                    st.push(i);
                } else {
                    // 如果栈不为空，则计算当前有效括号的长度

                    int len = i - st.top(); // 这儿不用加一，因为这儿设计的巧妙，栈顶元素是上一个左括号的下标，这儿减去栈顶元素就是当前有效括号的长度

                    // 更新最长长度
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    string s = ")()())";

    Solution sol;
    int res = sol.longestValidParentheses(s);

    cout << "longest valid parentheses: " << res << endl;

    return 0;
}