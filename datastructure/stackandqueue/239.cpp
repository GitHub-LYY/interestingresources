/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 239. 滑动窗口最大值
** link: https://leetcode.cn/problems/sliding-window-maximum/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
            }
        }

        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back(); // 从back弹出
            }
            que.push_back(value); // 此时插入的保持了单调
        }

        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 定义单调队列
        MyQueue que;

        // 定义变量保存结果
        vector<int> res;

        // 把前k个元素放入队列中
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }

        // 把第一个最大值放入结果中
        res.push_back(que.front());

        // 从第k个元素开始遍历
        for (int i = k; i < nums.size(); i++) {
            // 把窗口最左边的元素弹出
            que.pop(nums[i - k]);

            // 把当前元素插入队列
            que.push(nums[i]);

            // 把当前最大值放入结果
            res.push_back(que.front());
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k  = 3;

    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}