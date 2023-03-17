/*
** Author: Yangyang Liu
** Date: 2023-03-17
** Description: 225. 用队列实现栈
** link: https://leetcode.cn/problems/implement-stack-using-queues/
** reference: 题解区，官方题解，一个队列实现
*/

#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int> que; // 实现栈的一个队列
public:
    MyStack() {

    }

    void push(int x) {
        int size = que.size(); // 先求出队列中有多少个数了，要把他们放到队尾

        que.push(x); // 插入队尾

        for (int i = 0; i < size; i++) { // 把除刚插入队尾的数从队头出队，放入到队尾
            que.push(que.front());
            que.pop();
        }

        return;
    }

    int pop() {
        int popRes = que.front(); // 取出队首
        que.pop();
        return popRes;
    }

    int top() {
        return que.front(); // 输出队首
    }

    bool empty() {
        return que.empty(); // 判断队列空否
    }
};

int main(int argc, char** argv) {
    return 0;
}