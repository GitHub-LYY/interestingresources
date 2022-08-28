/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 50. 第一个只出现一次的字符
** link: https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
** reference: 自己做的
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        // 定义哈希表保存每个字符出现的个数
        unordered_map<char, int> umap;

        // 统计每个字符的出现频次
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]]++;
        }

        // 第二次遍历，遇到第一个频次是一的字符直接返回
        for (int i = 0; i < s.size(); i++) {
            if (umap[s[i]] == 1) {
                return s[i];
            }
        }

        return ' ';
    }
};

int main(int argc, char** argv) {
    string s = "abaccdeff";

    Solution sol;
    char res = sol.firstUniqChar(s);

    cout << "char is :" << res << endl;

    return 0;
}