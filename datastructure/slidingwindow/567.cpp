/*
** Author: Yangyang Liu
** Date: 2023-01-15
** Description: 567. 字符串的排列
** link: https://leetcode.cn/problems/permutation-in-string/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(); // 定义变量保存s1字符串的长度
        int len2 = s2.size(); // 定义变量保存s2字符串的长度
        if (len1 > len2) {
            return false;
        }

        vector<int> count1(26); // 定义动态数组作为哈希表
        vector<int> count2(26); // 定义动态数组作为哈希表
        
        for (int i = 0; i < len1; i++) { // 遍历s1，填充哈希表
            count1[s1[i] - 'a']++; // s1每个字母出现次数
            count2[s2[i] - 'a']++; // s2最开始的滑动窗口中字母的出现次数
        }
        if (count1 == count2) {
            return true; // 一个也是true
        }

        for (int i = 0; i < len2 - len1; i++) {
            count2[s2[i] - 'a']--; // 去掉滑动窗口左边缘的旧的值
            count2[s2[i + len1] - 'a']++; // 滑动窗口右边缘，滑动窗口

            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    string s1 = "ab";
    string s2 = "eidbaooo";

    Solution s;
    bool res = s.checkInclusion(s1, s2);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}