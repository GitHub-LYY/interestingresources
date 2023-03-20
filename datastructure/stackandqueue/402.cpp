/*
** Author: Yangyang Liu
** Date: 2022-08-24，2023-03-20
** Description: 402. 移掉 K 位数字
** link: https://leetcode.cn/problems/remove-k-digits/
** reference: 题解区，搜索，「手画图解」单调递增栈，为什么？何时用？| 402.移掉K位数字，讨论区
** 20230320，粗读官方题解，直接读官方题解的代码，容易理解，也容易写
*/

#include <iostream>
#include <queue>

using namespace std;

class SolutionOld {
public:
    string removeKdigits(string num, int k) {
        // 如果num字符串为空，则输出0字符
        if (num.size() == 0) {
            return "0";
        }

        // 定义双端队列模拟栈
        deque<char> que;

        for (int i = 0; i < num.size(); i++) {
            char c = num[i];
            while (k > 0 && !que.empty() && c < que.back()) {
                que.pop_back();
                k--;
            }

            // 为了保证有元素入栈，也是为了使得空栈的时候0不入栈
            if (c != '0' || !que.empty()) {
                que.push_back(c);
            }
        }

        // 因为上边有k--的操作，因此在这判断栈是否为空
        if (que.empty()) {
            return "0";
        }

        // 来到这，栈不为空

        // k没有用完，继续弹出后边的元素
        while (k > 0 && !que.empty()) { // 这一开始忘记写非空条件了
            que.pop_back();
            k--;
        }

        // 判断栈是否为空
        if (que.empty()) {
            return "0";
        }

        // k用完了，栈也不为空，则输出最小的字符串

        string str;
        while (!que.empty()) {
            str += que.front();
            que.pop_front();
        }

        return str == "" ? "0" : str; // 一开始忘记写成判断了
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st; // 使用vector模拟栈，从头取数据方便

        for (char ch : num) {
            while (k > 0 && !st.empty() && st.back() > ch) { // 出现此条件，则要把栈顶大的数弹出了
                st.pop_back(); // 弹出栈顶
                k--; // 次数少一
            }

            st.push_back(ch); // 循环中不断插入字符
        }

        for (; k > 0; k--) { // 次数没有用完继续弹出栈顶
            st.pop_back();
        }

        string res; // 结果
        bool isBeginZero = true; // 一开始设开头的字符是0
        for (auto ch : st) { // 体现出使用vector的方便之处了，从头开始
            if (isBeginZero && ch == '0') { // 当前是开头的0了，则要舍去
                continue; // 直接下一个字符
            }

            isBeginZero = false; // 来到这儿，则已经处理完开头的0字符了
            res += ch; // 拼接
        }

        return res == "" ? "0" : res;
    }
};

int main(int argc, char** argv) {
    string num = "1432219";
    int k = 3;

    Solution s;
    string res = s.removeKdigits(num, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }

    return 0;
}