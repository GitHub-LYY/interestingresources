/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 93. 复原 IP 地址
** link: https://leetcode.cn/problems/restore-ip-addresses/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;

    bool isValid(string& s, int start, int end) {
        // 判断某一段是否合法

        if (start > end) {
            // 区间不合法

            return false;
        }

        if (s[start] == '0' && start != end) {
            // 0开头的数字不合法

            return false;
        }

        int num = 0; // 为了计算这一段的数字
        for (int i = start; i <= end; i++) {
            // 如果当前字符不是数字，则是不合法的
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }

            // 到这儿，保证字符是数字
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                // 如果数字大于255，则不合法

                return false;
            }
        }

        return true;
    }

    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                // 判断最后一段是否合法

                res.push_back(s);
            }

            // 如果不合法，也要返回
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                // 在s上插入点
                s.insert(s.begin() + i + 1, '.');

                // 点的数量加一
                pointNum++;

                // 递归
                backtracking(s, i + 2, pointNum);

                // 点的数量减去一
                pointNum--;

                // 擦除s上插入的点
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();

        if (s.size() < 4 || s.size() > 12) {
            // 如果字符串长度不合法，直接返回

            return res;
        }

        backtracking(s, 0, 0);

        return res;
    }
};

int main(int argc, char** argv) {
    string s = "25525511135";

    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}