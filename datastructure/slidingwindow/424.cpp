/*
** Author: Yangyang Liu
** Date: 2023-01-16
** Description: 424. 替换后的最长重复字符
** link: https://leetcode.cn/problems/longest-repeating-character-replacement/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> nums(26); // 定义动态数组保存26个大写字母的出现次数
        int maxn = 0; // 保存滑动窗口中出现最大次数的字母的次数
        int len = s.size(); // 定义变量保存字符串长度
        int left = 0; // 左边缘
        int right = 0; // 右边缘

        while (right < len) {
            nums[s[right] - 'A']++; // 当前字符出现次数
            maxn = max(maxn, nums[s[right] - 'A']); // 每遍历一个字符要求出滑动窗口中出现次数最多的字母的次数
            if (right - left + 1 - maxn > k) { // 这儿要好好理解，滑动窗口长度减去最多次数，从小于k，到等于k，再到大于k，大于k了，则要左边缘右移了
                nums[s[left] - 'A']--; // 左边缘字母出现次数减一，相当于滑动窗口左边缘右移
                left++; // 这句配合上句，才是完整的左边缘右移
            }
            right++; // 右边缘负责开路，不断往右走
        }

        return right - left; // 这儿没有+1了，因为right已经多了一次++了，此时的滑动窗口长度是答案了
    }
};

int main(int argc, char** argv) {
    string s = "ABAB";
    int k = 2;

    Solution sol;
    int res = sol.characterReplacement(s, k);

    cout << res << endl;

    return 0;
}