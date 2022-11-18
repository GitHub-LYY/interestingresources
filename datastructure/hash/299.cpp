/*
** Author: Yangyang Liu
** Date: 2022-11-18
** Description: 299. 猜数字游戏
** link: https://leetcode.cn/problems/bulls-and-cows/
** reference: 题解区，搜索，【微扰理论】模拟 - 统计计数，账号，微扰理论
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        // 定义哈希表保存两个数组的0-9字符的数量
        vector<int> countSecret(10, 0); // 0-9总10个字符
        vector<int> countGuess(10, 0);

        // 定义变量保存bull的数量
        int numBulls = 0;

        // 先遍历secret数组
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                // 满足求bull的条件

                numBulls++;
            }

            // 别忘了求0-9字符的次数
            countSecret[secret[i] - '0']++;
            countGuess[guess[i] - '0']++;
        }

        // 定义变量保存bull+cow的数量
        int numBullsCows = 0;

        // 遍历10次求总数量
        for (int i = 0; i < 10; i++) {
            numBullsCows += min(countSecret[i], countGuess[i]); // 最小次数求和
        }

        // 求出cow的数量
        int numCows = numBullsCows - numBulls;

        // 拼接字符串
        string res = to_string(numBulls) + 'A' + to_string(numCows) + 'B';

        return res;
    }
};

int main(int argc, char** argv) {
    string secret = "1807";
    string guess = "7810";

    Solution s;
    string res = s.getHint(secret, guess);

    cout << res << endl;

    return 0;
}