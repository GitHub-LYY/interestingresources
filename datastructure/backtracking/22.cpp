/*
** Author: Yangyang Liu
** Date: 2022-08-22
** Description: 22. 括号生成
** link: https://leetcode.cn/problems/generate-parentheses/
** reference: 题解区，搜索，【忍者算法】全网最清晰易懂的讲解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;

    void backtracking(string& s, int num, int leftCount, int rightCount) {
        if (s.size() == 2 * num) {
            res.push_back(s);
            return;
        }

        if (leftCount < num) {
            s.push_back('(');
            leftCount += 1;
            backtracking(s, num, leftCount, rightCount);
            leftCount -= 1;
            s.pop_back();
        }

        if (rightCount < leftCount) {
            s.push_back(')');
            rightCount += 1;
            backtracking(s, num, leftCount, rightCount);
            rightCount -= 1;
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        res.clear();
        string s;
        backtracking(s, n, 0, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    vector<string> res = s.generateParenthesis(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}