/*
** Author: Yangyang Liu
** Date: 2022-08-24
** Description: 402. 移掉 K 位数字
** link: https://leetcode.cn/problems/remove-k-digits/
** reference: 题解区，搜索，「手画图解」单调递增栈，为什么？何时用？| 402.移掉K位数字，讨论区
*/

#include <iostream>
#include <queue>

using namespace std;

class Solution {
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