/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 剑指 Offer 41. 数据流中的中位数
** link: https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/?favorite=xb9nqhhg
** reference: 题解区，搜索，面试题41. 数据流中的中位数（优先队列 / 堆，清晰图解），作者，Krahets，评论区，版本很好，作者，mrbear
*/

#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    class CmpBig {
    public:
        bool operator()(int a, int b) {
            return a < b; // 构建大顶堆
        }
    };

    class CmpSmall {
    public:
        bool operator()(int a, int b) {
            return a > b; // 构建小顶堆
        }
    };

    // 构建大顶堆和小顶堆
    priority_queue<int, vector<int>, CmpBig> priQueBig;
    priority_queue<int, vector<int>, CmpSmall> priQueSmall;

    MedianFinder() {

    }

    void addNum(int num) {
        // 这个函数是最关键的，在插入元素的时候，根据两个堆的大小来判断往哪个堆插入，插入的时候先插入另外的一个，再从另外一个再插入此堆

        if (priQueBig.size() == priQueSmall.size()) {
            // 如果当前两个堆大小相等，则一定是插入左边的堆，大顶堆

            // 先插入右边的小顶堆
            priQueSmall.push(num);

            // 从右边的小顶堆取堆顶元素
            int queueTop = priQueSmall.top();
            priQueSmall.pop();

            // 把这个堆顶元素插入左边的大顶堆
            priQueBig.push(queueTop);
        } else {
            // 如果当前两个堆大小不等，则一定是左边的大顶堆比右边的小顶堆多一个元素，此时一定是插入右边的小顶堆

            // 先插入左边的大顶堆
            priQueBig.push(num);

            // 从左边的大顶堆取堆顶元素
            int queueTop = priQueBig.top();
            priQueBig.pop();

            // 把这个堆顶元素插入右边的小顶堆
            priQueSmall.push(queueTop);
        }

        return;
    }

    double findMedian() {
        // 判断元素数量是奇数，则取左边大顶堆的堆顶元素，如果是偶数，则取左边大顶堆的堆顶和右边小顶堆的堆顶，求平均值

        // 定义变量保存数据流的大小
        int size = priQueBig.size() + priQueSmall.size();

        if (size % 2 == 1) {
            // 元素数量是奇数个

            return priQueBig.top() * 1.0; // *1.0是为了转换为double类型的
        } else {
            // 元素数量是偶数个

            return (priQueBig.top() + priQueSmall.top())  * 1.0 / 2; // *1.0必须放置/2的前边，否则，没有小数位了
        }
    }
};

int main(int argc, char** argv) {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    double res1 = mf.findMedian(); // 这是double类型的
    mf.addNum(3);
    double res2 = mf.findMedian();

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}