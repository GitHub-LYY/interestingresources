/*
** Author: Yangyang Liu
** Date: 2022-12-04
** Description: 482. 密钥格式化
** link: https://leetcode.cn/problems/license-key-formatting/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // 定义变量保存结果
        string res;

        // 定义s中除了-有多少字符
        int count = 0;

        // 逆序遍历s
        for (int i = s.size() - 1; i >= 0; i--) {
            // 是-，则忽略
            // 不是-，则处理，是字符了

            if (s[i] != '-') {
                // 当前字符是字符

                count++; // 字符数多了

                res.push_back(toupper(s[i])); // 转换大写字母再插入结果

                if (count % k == 0) {
                    // 是k的倍数了，要插入-了，是一组

                    res.push_back('-');
                }
            }
        }

        // 如果最后有-，则要删除了
        if (res.size() > 0 && res[res.size() - 1] == '-') { // 一开始忘记写第一个条件了，错的
            res.pop_back();
        }

        // 逆序
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    string S = "5F3Z-2e-9-w";
    int k = 4;

    Solution s;
    string res = s.licenseKeyFormatting(S, k);

    cout << res << endl;

    return 0;
}