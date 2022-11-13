/*
** Author: Yangyang Liu
** Date: 2022-11-13
** Description: 451. 根据字符出现频率排序
** link: https://leetcode.cn/problems/sort-characters-by-frequency/
** reference: 题解区，官方题解评论区使用堆排序的，账号，小二
*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    class Cmp {
    public:
        bool operator()(pair<int, char> a, pair<int, char> b) {
            return a.first < b.first;
        }
    };
public:
    string frequencySort(string s) {
        // 定义哈希表保存每个字符的出现次数
        unordered_map<char, int> umap;

        // 遍历字符串的每个字符求次数
        for (auto ch : s) {
            umap[ch]++;
        }

        // 定义大顶堆，节点是pair<int, char>对组，对int进行排序，即对次数排序
        priority_queue<pair<int, char>, vector<pair<int, char>>, Cmp> pri_que;

        // 把哈希表的元素插入大顶堆
        for (auto keyValue : umap) {
            pri_que.push(pair<int, char>{keyValue.second, keyValue.first}); // first和second别写错了，这和umap的有区别
        }

        // 定义变量保存结果
        string res;

        // 遍历大顶堆求结果
        while (!pri_que.empty()) {
            for (int i = 0; i < pri_que.top().first; i++) {
                // 把次数用完拼接字符
                res += pri_que.top().second;
            }
            pri_que.pop(); // 拼接完了，次数用完了，该弹出大顶堆了
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "tree";

    Solution sol;
    string res = sol.frequencySort(s);

    cout << res << endl;

    return 0;
}