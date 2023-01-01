/*
** Author: Yangyang Liu
** Date: 2023-01-01
** Description: 394. 字符串解码
** link: https://leetcode.cn/problems/decode-string/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getDigit(string &s, int &ptr) {
        string res; // 定义结果

        while (isdigit(s[ptr])) {
            res += s[ptr];
            ptr++;
        }

        return res;
    }
    string getString(vector<string>& vec) {
        string res;

        for (auto str : vec) {
            res += str;
        }

        return res;
    }
    string decodeString(string s) {
        // 定义变量保存索引用来遍历字符串
        int ptr = 0;

        // 使用vector模拟栈
        vector<string> stk;

        while (ptr < s.size()) {
            if (isdigit(s[ptr])) {
                string str = getDigit(s, ptr);

                // 取完完整数值以后，插入栈
                stk.push_back(str);
            } else if (isalpha(s[ptr]) || s[ptr] == '[') {
                // [、字符串要入栈

                stk.push_back(string(1, s[ptr++])); // 转换字符为字符串再入栈
            } else {
                // 是]

                ptr++; // 先把索引往后走一个，不要忘了

                // 取出括号中的字符串
                // 定义字符串数组临时保存取出的字符串
                vector<string> tmpVec;
                while (!stk.empty() && stk.back() != "[") {
                    // 到[则意味着取完了字符串了

                    string tmp = stk.back(); // 用的是vector模拟的栈，是back，没有top函数
                    stk.pop_back(); // 弹出栈顶
                    tmpVec.push_back(tmp);
                }
                reverse(tmpVec.begin(), tmpVec.end()); // 逆序才是取出的字符串的原始字符串

                // 字符串取完后，此时栈顶一定是[了，弹出
                stk.pop_back();

                // 此时的栈顶一定是数值了
                int repTimes = stoi(stk.back()); // 一开始忘记stoi了，错的
                stk.pop_back();

                // 定义字符串保存重复后的字符串和要被重复的原始字符串
                string t;
                string o = getString(tmpVec); // 参数是vector<string>类型的
                // 把o重复数值的次数保存在t中
                while (repTimes--) {
                    t += o;
                }
                stk.push_back(t); // 把重复完的t插入栈
            }
        }

        return getString(stk); // 此时的stk字符串数组全部是字符串了，拼接后是结果了
    }
};

int main(int argc, char **argv) {
    string s = "3[a]2[bc]";

    Solution sol;
    string res = sol.decodeString(s);

    cout << res << endl;

    return 0;
}