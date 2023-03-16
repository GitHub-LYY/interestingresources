/*
** Author: Yangyang Liu
** Date: 2023-03-16
** Description: 318. 最大单词长度乘积
** link: https://leetcode.cn/problems/maximum-product-of-word-lengths/
** reference: 官方题解，位运算
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int numWords = words.size(); // 单词数量
        vector<int> masks(numWords); // 位掩码保存单词中字母出现信息

        for (int i = 0; i < numWords; i++) { // 遍历每个单词，求出掩码信息
            int numLen = words[i].size(); // 当前单词的长度

            for (int j = 0; j < numLen; j++) {
                masks[i] |= (1 << (words[i][j] - 'a')); // 32位数足够保存26位的位信息了
            }
        }

        int maxProd = 0;
        for (int i = 0; i < numWords; i++) {
            for (int j = i + 1; j < numWords; j++) {
                if ((masks[i] & masks[j]) == 0) { // 等于0意味着两个单词没有公共字母
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }

        return maxProd;
    }
};

int main(int argc, char** argv) {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    Solution s;
    int res = s.maxProduct(words);

    cout << res << endl;

    return 0;
}