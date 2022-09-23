/*
** Author: Yangyang Liu
** Date: 2022-09-22
** Description: 面试题59 - II. 队列的最大值
** link: https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/
** reference: 
*/

#include <iostream>

using namespace std;

class MaxQueue {
private:
    queue<int> que;
    deque<int> dque; // 单调队列
public:
    MaxQueue() {

    }

    int max_value() {
        if (dque.empty()) {
            return -1;
        }

        // dque不位空，则返回队头的值
        return dque.front();
    }

    void push_back(int value) {
        // 插入que，也要插入dque

        while (!dque.empty() && value > dque.back()) {
            // 插入的value大于dque队尾的值

            dque.pop_back(); // 不断弹出队尾的值，保持dque的单调递减特性
        }

        // 现在满足单调性了，直接插入value
        dque.push_back(value); // 从尾部插入

        // 别忘了que也要插入
        que.push(value); // que的插入很简单

        return;
    }

    int pop_front() {
        if (que.empty()) {
            return -1;
        }

        int ans = que.front();

        if (ans == dque.front()) {
            // 如果que的队头和dque的队头相等，则意味着dque也要弹出队头

            dque.pop_front();
        }

        que.pop(); // 弹出que的队头

        return ans;
    }
};

int main(int argc, char** argv) {
    MaxQueue mque = new MaxQueue();
    mque.push_back(1);
    mque.push_back(2);
    int maxVal1 = mque.max_value();
    int front1 = mque.pop_front();
    int maxVal2 = mque.max_valule();
    
    cout << maxVal1 << endl;
    cout << front1 << endl;
    cout << maxVal2 << endl;

    return 0;
}