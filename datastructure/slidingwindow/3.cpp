/*
** Author: Yangyang Liu
** Date: 2022-08-14
** Description: 3. 无重复字符的最长子串
** link: https://leetcode.cn/problems/longest-substring-without-repeating-characters/
** reference: b站，douma学堂，特别好，三种方法，一步一步优化
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 定义左右边界指针
        int left = 0;
        int right = 0;

        // 定义变量保存最大长度
        int maxLen = 0;

        // 定义哈希set
        unordered_set<char> uset;

        // 滑动窗口了
        while (right < s.size()) {
            // 定义变量保存当前字符
            char rightChar = s[right];

            // 判断当前字符是否在set中
            while (uset.find(rightChar) != uset.end()) {
                // 来到这儿，则当前字符在set中，必须剔除左边重复的字符

                uset.erase(s[left]);
                left++;
            }
            
            // 来到这儿，则set没有当前字符
            uset.insert(rightChar);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    string s = "abcabcbb";

    Solution sol;
    int maxLen = sol.lengthOfLongestSubstring(s);

    cout << "length of longest substring: " << maxLen << endl;

    return 0;
}