/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 剑指 Offer 05. 替换空格
** link: https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
** reference: 
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // 定义变量保存空格数量
        int spaceCount = 0;

        // 求出空格数量
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                spaceCount++;
            }
        }

        // 保存旧字符串的长度
        int oldSize = s.size();

        // 扩容
        s.resize(oldSize + spaceCount * 2);

        // 保存新字符串的长度
        int newSize = s.size();

        // 定义i指向旧字符串的末尾，j指向新字符串的末尾
        int i = oldSize - 1;
        int j = newSize - 1;

        // 从后往前遍历
        while (i < j) {
            // 如果是空格，替换为%20
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
                i--;
            } else { // 不是空格，把i位置的字符替换掉j位置的字符
                s[j] = s[i];
                j--;
                i--;
            }
        }

        return s;
    }
};

int main(int argc, char** argv) {
    string s = "We are happy.";

    cout << "before replace: " << s << endl;
    
    Solution sol;
    string res = sol.replaceSpace(s);

    cout << "after replace: " << res << endl;

    return 0;
}