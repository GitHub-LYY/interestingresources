/*
** Author: Yangyang Liu
** Date: 2022-11-19
** Description: 506. 相对名次
** link: https://leetcode.cn/problems/relative-ranks/
** reference: 题解区，官方题解评论区使用堆排序，理解了自己写
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    class Cmp {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first < b.first; // 大顶堆
        }
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        // 定义变量保存结果
        vector<string> answer(score.size());

        // 定义大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pri_que;

        // 放入大顶堆
        for (int i = 0; i < score.size(); i++) {
            pri_que.push(make_pair(score[i], i));
        }

        // 这别使用while循环了，使用for循环容易利用下标
        for (int i = 0; i < score.size(); i++) {
            // 取出堆顶数据
            pair<int, int> topPair = pri_que.top();
            pri_que.pop();

            // 判断前三名和后边的名次
            if (i == 0) {
                // 第一名，很巧妙，这儿

                answer[topPair.second] = "Gold Medal";
            } else if (i == 1) {
                // 第二名

                answer[topPair.second] = "Silver Medal";
            } else if (i == 2) {
                // 第三名

                answer[topPair.second] = "Bronze Medal";
            } else {
                // 不是前三名

                answer[topPair.second] = to_string(i + 1); // 第一次写忘记
            }
        }

        return answer;
    }
};

int main(int argc, char** argv) {
    vector<int> score = {5, 4, 3, 2, 1};

    Solution s;
    vector<string> res = s.findRelativeRanks(score);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}