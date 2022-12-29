/*
** Author: Yangyang Liu
** Date: 2022-12-29
** Description: 71. 简化路径
** link: https://leetcode.cn/problems/simplify-path/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(string path, char delim) {
        // 定义变量保存结果
        vector<string> names;

        // 定义变量保存中间要保存的某个字符串
        string curStr;

        for (char ch : path) {
            // 每次遍历一个字符

            if (ch == delim) {
                // 当前遍历的字符是分隔符了

                names.push_back(curStr);
                curStr.clear(); // 别忘了clear
            } else {
                // 当前遍历的不是分隔符则暂时保存

                curStr += ch;
            }
        }

        // 最后别忘了再插入最后的字符串
        names.push_back(curStr);

        return names;
    }
    string simplifyPath(string path) {
        // 定义变量保存分割开的字符串
        vector<string> names = split(path, '/');

        // 定义栈保存字符串
        vector<string> st; // 使用vector模拟栈

        for (string str : names) {
            // 遍历分隔开的字符串

            if (str == "..") {
                // 这是上级目录
                
                if (!st.empty()) {
                    // 栈必须非空才能出栈

                    st.pop_back();
                }
            } else if (!str.empty() && str != ".") {
                // 不是这两种情况，则一定是目录名了

                st.push_back(str);
            }
        }

        // 定义变量保存结果
        string res;

        if (st.empty()) {
            // 根目录

            res = "/";
        } else {
            // 把目录按标准格式拼接

            for (string str : st) {
                res += "/" + str; // 从前往后拼接，使用for方便
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string path = "/home/";

    Solution s;
    string res = s.simplifyPath(path);

    cout << res << endl;

    return 0;
}