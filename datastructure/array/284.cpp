/*
** Author: Yangyang Liu
** Date: 2023-03-17
** Description: 284. 顶端迭代器
** link: https://leetcode.cn/problems/peeking-iterator/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class PeekingIterator : public Iterator {
private:
    bool flag; // 标记是否有剩余的数
    int nextElement; // 记录下一个数
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) { // 父类已经初始化了，要利用好父类
        flag = Iterator::hasNext(); // 是否有剩余的数
        if (flag) { // 如果有，再去求下一个数
            nextElement = Iterator::next();
        }
    }

    int peek() { // 直接输出下一个数
        return nextElement;
    }

    int next() {
        int res = nextElement; // 先记录，一会输出，要修改了

        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }

        return res;
    }

    bool hasNext() const {
        return flag;
    }
};

int main(int argc, char** argv) {
    return 0;
}