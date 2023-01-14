/*
** Author: Yangyang Liu
** Date: 2023-01-14
** Description: 187. 重复的DNA序列
** link: https://leetcode.cn/problems/repeated-dna-sequences/
** reference: 题解区，官方题解，方法一，哈希表
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res; // 定义变量保存结果
        unordered_map<string, int> substr2num; // 子字符串-出现次数哈希表
        int len = s.size(); // 字符串长度
        int lenSubstr = 10; // 子字符串长度

        for (int i = 0; i <= len - lenSubstr; i++) { // 必须有等号
            string substr = s.substr(i, lenSubstr); // 取出当前位置后边10个字符组成的子字符串
            substr2num[substr]++; // 记录次数
            if (substr2num[substr] == 2) { // substr子字符串出现不止一次
                res.push_back(substr);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution sol;
    vector<string> res = sol.findRepeatedDnaSequences(s);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}