/*
** Author: Yangyang Liu
** Date: 2023-03-03
** Description: 241. 为运算表达式设计优先级
** link: https://leetcode.cn/problems/different-ways-to-add-parentheses/
** reference: 题解区，搜索，【宫水三叶】DFS 运用题，评论区，吃饭用晚，C++版本的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 输出字符串s的left-right范围内的结果
     */
    vector<int> dfs(string& s, int left, int right) {
        vector<int> res; // 定义变量保存结果

        for (int i = left; i <= right; i++) {
            if (s[i] >= '0' && s[i] <= '9') { // 当前字符是数字字符，则不用做事情，直接遍历下一个字符
                continue;
            } else { // 是运算符
                vector<int> leftRes = dfs(s, left, i - 1); // 递归求出i左边的结果
                vector<int> rightRes = dfs(s, i + 1, right); // 递归求出i右边的结果

                for (int oneOfLeftRes : leftRes) {
                    for (int oneOfRightRes : rightRes) {
                        int tmp = 0; // 定义临时遍历保存结果插入结果数组

                        if (s[i] == '+') { // 加号运算
                            tmp = oneOfLeftRes + oneOfRightRes;
                        }
                        if (s[i] == '-') { // 减号运算
                            tmp = oneOfLeftRes - oneOfRightRes;
                        }
                        if (s[i] == '*') { // 乘号运算
                            tmp = oneOfLeftRes * oneOfRightRes;
                        }
                        res.emplace_back(tmp); // 插入结果
                    }
                }
            }
        }

        if (res.empty()) { // 空，则意味着上边的for没有执行，当前的左边或者右边是一个数值
            int tmp = 0; // 定义临时变量
            for (int i = left; i <= right; i++) { // 大于一位的数值的求法
                tmp = tmp * 10 + (s[i] - '0');
            }
            res.emplace_back(tmp); // 插入结果
        }

        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        int len = expression.size(); // 求出字符串的长度
        return dfs(expression, 0, len - 1);
    }
};

int main(int argc, char** argv) {
    string expression = "2-1-1";

    Solution s;
    vector<int> res = s.diffWaysToCompute(expression);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}