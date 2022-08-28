/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 40. 最小的k个数
** link: https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
** reference: 思考
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 大顶堆仿函数
    class Cmp {
    public:
        bool operator()(int a, int b) {
            return a < b;
        }
    };
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 定义大顶堆
        priority_queue<int, vector<int>, Cmp> pri_que;

        // 遍历arr，但是大顶堆中保存k个数，不用全部保存
        for (int i = 0; i < arr.size(); i++) {
            // 当前数字插入大顶堆
            pri_que.push(arr[i]);

            // 判断大顶堆是否超出k长度，超出则删除堆顶，一直维持k个数字
            if (pri_que.size() > k) {
                // 堆顶删除
                pri_que.pop();
            }
        }

        // 此时大顶堆保存的是最小的k个数
        vector<int> res;
        for (int i = k - 1; i >= 0; i--) { // 这的size一直在减小，所以不能使用正序，使用k
            res.push_back(pri_que.top()); // 本题无顺序要求，随便出堆
            pri_que.pop(); // 一开始忘记了，出错
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> arr = {3, 2, 1};
    int k = 2;

    Solution s;
    vector<int> res = s.getLeastNumbers(arr, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}