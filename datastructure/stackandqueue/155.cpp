/*
** Author: Yangyang Liu
** Date: 2023-03-18
** Description: 155. 最小栈
** link: https://leetcode.cn/problems/min-stack/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class MinStack {
private:
    stack<int> x_stack; // 正常的栈
    stack<int> min_stack; // 最小栈
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {    
        x_stack.push(val); // 插入正常栈
        min_stack.push(min(val, min_stack.top())); // 最小栈插入
    }

    void pop() {
        x_stack.pop(); // 正常栈弹出
        min_stack.pop(); // 最小栈弹出
    }

    int top() {
        return x_stack.top(); // 取正常栈顶部
    }

    int getMin() {
        return min_stack.top(); // 取最小栈顶部
    }
};

int main(int argc, char** argv) {
    return 0;
}