/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 09. 用两个栈实现队列
** link: https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
** reference: 代码随想录，自己的理解自己写的
*/

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
private:
    // 用两个栈实现队列，首先先创建两个成员变量栈
    stack<int> inStack;
    stack<int> outStack;
public:
    CQueue() {

    }

    void appendTail(int value) {
        inStack.push(value);
        return;
    }

    int deleteHead() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        } else {
            // 输出栈不为空

            int res = outStack.top();
            outStack.pop();
            return res;
        }
        if (outStack.empty()) {
            return -1;
        } else {
            int res = outStack.top();
            outStack.pop();
            return res;
        }
    }
};

int main(int argc, char** argv) {
    CQueue que;
    que.appendTail(3);
    int res1 = que.deleteHead();
    int res2 = que.deleteHead();

    cout << res1 << " " << res2 << endl;

    return 0;
}