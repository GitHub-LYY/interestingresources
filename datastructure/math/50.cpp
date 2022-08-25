/*
** Author: Yangyang Liu
** Date: 2022-08-25
** Description: 50. Pow(x, n)
** link: https://leetcode.cn/problems/powx-n/
** reference: 官方题解第二种方法
*/

#include <iostream>

using namespace std;

class Solution {
private:
    double pow(double x, long long N) {
        double ans = 1.0;

        double xContri = x;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= xContri;
            }

            xContri *= xContri;

            N /= 2;
        }

        return ans;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? pow(x, N) : 1.0 / pow(x, -N); // 必须判断，否则本地也报错
    }
};

int main(int argc, char** argv) {
    double x = 2.0;
    int n = 10;

    Solution s;
    double res = s.myPow(x, n);

    cout << "res:" << res << endl;

    return 0;
}