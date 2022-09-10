/*
** Author: Yangyang Liu
** Date: 2022-09-10
** Description: 剑指 Offer 48. 最长不含重复字符的子字符串
** link: https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/?favorite=xb9nqhhg
** reference: 看LeetCode第3题
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 定义哈希表保存每个字符的出现次数
        unordered_set<char> uset; // char不能改为int

        // 定义变量保存最大的长度
        int maxLen = 0;
        
        // 定义左右边界
        int left = 0;
        int right = 0; // right初始值为0

        while (right < s.size()) {
            // 取出当前字符
            char c = s[right];

            while (uset.find(c) != uset.end()) { // 这是while循环，不是if，使用if一直报错
                // 当前窗口已经有c字符了

                // 擦掉uset中的当前字符
                uset.erase(s[left]); // 使用了哈希set，必须一个一个擦除

                left++; // left边界迅速切换到right处位置
            }

            // 当前字符插入哈希表
            uset.insert(c); // c字符出现了

            // 更新长度
            if ((right - left + 1) > maxLen) {
                maxLen = right - left + 1;
            }

            right++; // 窗口扩大
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    string s = "abcabcbb";

    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);

    cout << res << endl;

    return 0;
}