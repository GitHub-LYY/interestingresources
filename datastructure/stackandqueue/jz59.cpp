/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 59 - I. 滑动窗口的最大值
** link: https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    class MonotonicQueue {
    private:
        deque<int> dque;
    public:
        void pop(int value) {
            if (value == dque.front()) {
                dque.pop_front();
            }
            return;
        }

        void push(int value) {
            if (dque.empty()) {
                dque.push_back(value);
            } else {
                while (!dque.empty() && value > dque.back()) {
                    dque.pop_back();
                }
                dque.push_back(value);
            }
            return;
        }

        int front() {
            // 返回队列的最大值，即队头

            return dque.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 定义一个单调递减队列
        MonotonicQueue que;

        // 把nums的所有元素插入单调队列
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }

        // 定义变量保存最大值
        vector<int> maxVec;

        // 取出第一个最大值
        maxVec.push_back(que.front());

        // 从k开始遍历nums，取出每个窗口的最大值
        for (int i = k; i < nums.size(); i++) {
            // 首先把窗口最左边移除
            que.pop(nums[i - k]);

            // 把右边下一个入队
            que.push(nums[i]);

            // 取出当前窗口最大值
            maxVec.push_back(que.front());
        }

        return maxVec;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}