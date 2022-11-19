/*
** Author: Yangyang Liu
** Date: 2022-11-19
** Description: 412. Fizz Buzz
** link: https://leetcode.cn/problems/fizz-buzz/
** reference: 自己理解后写的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // 定义变量保存结果
        vector<string> answer;

        // 遍历1-n
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                // i是3和5的倍数

                answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                // i是3的倍数

                answer.push_back("Fizz");
            } else if (i % 5 == 0) {
                // i是5的倍数

                answer.push_back("Buzz");
            } else {
                // 以上不满足

                answer.push_back(to_string(i));
            }
        }

        return answer;
    }
};

int main(int argc, char** argv) {
    int n = 3;

    Solution s;
    vector<string> res = s.fizzBuzz(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}