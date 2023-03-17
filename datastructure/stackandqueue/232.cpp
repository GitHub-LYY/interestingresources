/*
** Author: Yangyang Liu
** Date: 2023-03-17
** Description: 232. 用栈实现队列
** link: https://leetcode.cn/problems/implement-queue-using-stacks/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class MyQueue {
private:
    stack<int> inSt; // 输入栈
    stack<int> outSt; // 输出栈
    void in2out() { // 输入栈插入输出栈
        while (!inSt.empty()) { // 输入栈要全部插入
            outSt.push(inSt.top());
            inSt.pop();
        }
        return;
    }
public:
    MyQueue() {

    }

    void push(int x) {
        inSt.push(x); // 输入栈插入
        return;
    }

    int pop() {
        if (outSt.empty()) { // 输出栈是空
            in2out();
        }

        // 此时求输出栈顶
        int popRes = outSt.top();
        outSt.pop();
        return popRes;
    }

    int peek() {
        if (outSt.empty()) { // 输出栈是空
            in2out();
        }

        // 此时求输出栈顶
        return outSt.top();
    }

    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};

int main(int argc, char** argv) {
    return 0;
}