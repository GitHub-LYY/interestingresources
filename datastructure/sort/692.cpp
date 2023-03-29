/*
** Author: Yangyang Liu
** Date: 2023-03-29
** Description: 692. 前K个高频单词
** link: https://leetcode.cn/problems/top-k-frequent-words/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    class Cmp {
    public:
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> str2count; // 字符串-出现次数哈希表
        for (auto word : words) { // 遍历字符串数组，填充哈希表
            str2count[word]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp> pri_que; // 小顶堆
        for (auto keyvalue : str2count) { // 遍历哈希表，填充小顶堆
            pri_que.push(make_pair(keyvalue.first, keyvalue.second));
            if (pri_que.size() > k) { // 维持k个数
                pri_que.pop();
            }
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) { // 遍历小顶堆
            res[i] = pri_que.top().first; // 取出堆顶
            pri_que.pop();
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution s;
    vector<string> res = s.topKFrequent(words, k);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}