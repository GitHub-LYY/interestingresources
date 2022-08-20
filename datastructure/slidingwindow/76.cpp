/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 76. 最小覆盖子串
** link: https://leetcode.cn/problems/minimum-window-substring/
** reference: 题解区，搜索，最小覆盖子串 | 图解滑动窗口 | 最通俗易懂的讲解【c++/java版本】，作者，林小鹿
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 定义s和t的哈希表
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        // 把t的字符保存进其哈希表
        for (char c : t) {
            tMap[c]++;
        }

        // 定义变成保存最小子串
        string str;

        // 定义变量保存匹配的字符个数
        int count = 0;

        // 定义变量保存窗口的左右边界
        int left = 0;
        int right = 0;

        // 开始滑动窗口
        while (right < s.size()) {
            // 进来第一件事情是把s的当前字符放入哈希表
            sMap[s[right]]++;

            // 判断当前窗口中当前字符的个数，小于t的，则t中也有这个字符，匹配
            if (sMap[s[right]] <= tMap[s[right]]) {
                count++; // 比较巧妙，tmap初始值为0，小于它，则它一定有这个字符
            }

            // 该收缩窗口了
            while (sMap[s[left]] > tMap[s[left]]) {
                // 进入这个循环，有两种情况，第一是t没有这个字符，第二是s的这个字符个数多了

                sMap[s[left]]--; // 哈希表的这个字符数量减去一
                left++;
            }

            // 更新最小子串
            if (count == t.size()) {
                // 进入if，则已经满足匹配了，是否是最小的，下边继续判断

                if (str.empty() || (right - left + 1) < str.size()) {
                    // 第一个条件在第一次str为空的时候才用，后边str不为空，执行第二个条件

                    str = s.substr(left, right - left + 1);
                }
            }

            // 别忘了窗口扩展
            right++;
        }

        return str;
    }
};

int main(int argc, char** argv) {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution sol;
    string str = sol.minWindow(s, t);

    cout << "min window: " << str << endl;

    return 0;
}