/*
** Author: Yangyang Liu
** Date: 2023-01-03
** Description: 202. 快乐数
** link: https://leetcode.cn/problems/happy-number/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;

        while (n > 0) {
            int d = n % 10; // 不断取出n的最后一位的值
            n /= 10;
            totalSum += d * d;
        }

        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int> uset;

        while (n != 1 && uset.find(n) == uset.end()) { // 第二个条件是set中没有n，则没有环
            uset.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

int main(int argc, char** argv) {
    int n = 19;

    Solution s;
    bool res = s.isHappy(n);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}