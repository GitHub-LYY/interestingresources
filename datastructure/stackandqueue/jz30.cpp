/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 30. 包含min函数的栈
** link: https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    // 用一个正常的栈保存元素，一个最小值栈保存最小值
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        minSt.push(INT_MAX);
    }

    void push(int x) {
        // 每次插入栈，把当前元素所在栈的最小值记录到最小值栈

        st.push(x);
        minSt.push(::min(minSt.top(), x));
    }

    void pop() {
        // 两个栈操作

        st.pop();
        minSt.pop();
        return;
    }

    int top() {
        return st.top();
    }

    int min() {
        // 直接返回最小值栈的栈顶
        return minSt.top();
    }
};

int main(int argc, char** argv) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    int res1 = minStack.min();
    minStack.pop();
    int res2 = minStack.top();
    int res3 = minStack.min();

    cout << res1 << " " << res2 << " " << res3 << endl;

    return 0;
}