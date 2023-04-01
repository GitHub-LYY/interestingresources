/*
** Author: Yangyang Liu
** Date: 2023-04-01
** Description: 204. 计数质数
** link: 204. 计数质数
** reference: 官方题解，方法一
*/

#include <iostream>
#include <vector>

using namespace std;

class SolutionOld {
public:
    bool isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            res += isPrime(i);
        }
        return res;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    int n = 10;

    Solution s;
    int res = s.countPrimes(n);

    cout << res << endl;

    return 0;
}