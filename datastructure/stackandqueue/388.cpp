/*
** Author: Yangyang Liu
** Date: 2022-12-30
** Description: 388. 文件的最长绝对路径
** link: https://leetcode.cn/problems/longest-absolute-file-path/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        // 定义变量保存结果
        int res = 0;

        // 定义变量保存字符串的长度
        int n = input.size();

        // 定义索引指针
        int pos = 0;

        // 定义栈保存路径长度
        stack<int> st;

        while (pos < n) {
            // 变量字符串的经典循环操作

            // 定义变量保存depth
            int depth = 1; // 初始depth为1
            while (pos < n && input[pos] == '\t') {
                depth++; // 多了一级
                pos++; // 别忘了pos++
            }

            // 是目录名或者文件名了，开始收集信息
            // 定义变量保存长度
            int len = 0;
            // 定义变量保存是否是文件名
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                // 不是\n，在这了，一定是字符串了，要么是目录名，要么是文件名

                if (input[pos] == '.') {
                    // 出现了.，则一定是文件名了

                    isFile = true;
                }

                len++; // 长度
                pos++; // 索引别忘了++
            }
            pos++; // 别忘了这要pos++

            while (st.size() >= depth) { // 一开始少些了=
                // 栈的大小比depth还大，要弹出栈顶，求长度

                st.pop();
            }
            if (!st.empty()) {
                // 此时栈非空，则栈顶+当前的长度+1是此时的长度了

                len += st.top() + 1;
            }
            if (isFile) {
                // 是文件名，则要求结果了

                res = max(res, len);
            } else {
                // 是目录名，插入栈

                st.push(len);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";

    Solution s;
    int res = s.lengthLongestPath(input);

    cout << res << endl;

    return 0;
}