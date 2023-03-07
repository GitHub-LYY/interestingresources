/*
** Author: Yangyang Liu
** Date: 2023-03-07
** Description: 433. 最小基因变化
** link: https://leetcode.cn/problems/minimum-genetic-mutation/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bank_set; // 去重
        unordered_set<string> visited; // 记录已经被遍历的字符串
        vector<int> keys = {'A', 'G', 'C', 'T'};

        for (string& str : bank) { // bank字符串去重
            bank_set.insert(str);
        }

        if (startGene == endGene) {
            return 0;
        }

        if (!bank_set.count(endGene)) {
            return -1;
        }

        queue<string> que; // 队列保存每一层的字符串
        que.push(startGene); // 第一个字符串入队
        visited.insert(startGene); // 第一个已经访问了
        int step = 1; // 遍历的层数
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                string str = que.front();
                que.pop();

                for(int j = 0; j < 8; j++) { // 基因序列长度是8
                    for (int k = 0; k < 4; k++) { // 有四个字符
                        if (str[j] != keys[k]) { // 当前字符不相等的字符
                            string tmp = str; // 记录产生的新的基因序列
                            tmp[j] = keys[k]; // 修改一位字符变为新的基因
                            if (!visited.count(tmp) && bank_set.count(tmp)) { // 没有被访问，且是合法的
                                if (tmp == endGene) { // 已经是end了
                                    return step;
                                }

                                que.push(tmp); // 插入队列
                                visited.insert(tmp); // 标记已经访问
                            }
                        } 
                    }
                }
            }

            step++;
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    string startGene = "AACCGGTT";
    string endGene = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    Solution s;
    int res = s.minMutation(startGene, endGene, bank);

    cout << res << endl;

    return 0;
}