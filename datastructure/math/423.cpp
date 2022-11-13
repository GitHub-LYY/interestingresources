/*
** Author: Yangyang Liu
** Date: 2022-11-13
** Description: 423. 从英文中重建数字
** link: https://leetcode.cn/problems/reconstruct-original-digits-from-english/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        // 定义哈希表保存每个字符出现的次数
        unordered_map<char, int> umap;

        // 遍历字符串
        for (auto ch : s) {
            umap[ch]++;
        }

        // 使用vector数组定义哈希表保存0-9共10个数字的次数
        vector<int> count(10);

        // 求出每个数字的出现次数
        count[0] = umap['z'];
        count[2] = umap['w'];
        count[4] = umap['u'];
        count[6] = umap['x'];
        count[8] = umap['g'];

        count[3] = umap['h'] - count[8];
        count[5] = umap['f'] - count[4];
        count[7] = umap['s'] - count[6];

        count[1] = umap['o'] - count[0] - count[2] - count[4];

        count[9] = umap['i'] - count[5] - count[6] - count[8];

        // 定义变量保存结果
        string res;

        // 遍历外层10次
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                res += char(i + '0'); // 把当前数字转换为字符加入结果字符串中
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "owoztneoer";

    Solution sol;
    string res = sol.originalDigits(s);

    cout << res << endl;

    return 0;
}