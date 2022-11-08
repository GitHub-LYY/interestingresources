/*
** Author: Yangyang Liu
** Date: 2022-11-08
** Description: 58. 最后一个单词的长度
** link: https://leetcode.cn/problems/length-of-last-word/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // 定义索引，从最后开始
        int index = s.size() - 1;

        // 排除最后边的空格
        while (index >= 0 && s[index] == ' ') {
            index--;
        }

        // 定义变量保存最后一个单词的长度
        int len = 0;
        
        // 继续从index的位置往前遍历
        while (index >= 0 && s[index] != ' ') {
            len++;
            index--;
        }

        return len;
    }
};

int main(int argc, char** argv) {
    string s = "Hello World";

    Solution sol;
    int res = sol.lengthOfLastWord(s);

    cout << res << endl;
    
    return 0;
}