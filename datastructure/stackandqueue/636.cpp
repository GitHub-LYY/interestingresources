/*
** Author: Yangyang Liu
** Date: 2022-12-31
** Description: 636. 函数的独占时间
** link: https://leetcode.cn/problems/exclusive-time-of-functions/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // 定义栈
        stack<pair<int, int>> stk;

        // 定义变量保存结果
        vector<int> res(n, 0);

        for (auto log : logs) {
            // 定义变量保存分割开是log的各个分量
            int idx; // 编号
            char type[10]; // start or end
            int timestamp;
            // 使用sscanf分割
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp); // 分割开后保存到变量

            if (type[0] == 's') {
                // start

                if (!stk.empty()) {
                    // 栈非空，要先求一下栈顶进程的占用时间了

                    res[stk.top().first] += timestamp - stk.top().second;
                }

                stk.push(pair<int, int>{idx, timestamp});
            } else {
                // end

                auto top = stk.top();
                stk.pop();
                // 弹出栈顶后，求出时间
                res[top.first] += timestamp - top.second + 1;

                if (!stk.empty()) {
                    // 栈非空，要更新时间戳方便求时间

                    stk.top().second = timestamp + 1; // 一开始没有+1，错的
                }
            }
        }

        return res;
    }
};

int main(int argc, char ** argv) {
    int n = 2;
    vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};

    Solution s;
    vector<int> res = s.exclusiveTime(n, logs);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}