/*
** Author: Yangyang Liu
** Date: 2023-02-26
** Description: 556. 下一个更大元素 III
** link: https://leetcode.cn/problems/next-greater-element-iii/
** reference: 转换为字符串后，参考31题的解法
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n); // 把数值转换为字符数组

        for (int i = str.size() - 1; i >= 0; i--) { // 两个指针中的前边的指针
            for (int j = str.size() - 1; j > i; j--) { // 两个指针中的后边的指针
                if (str[i] < str[j]) { // 前小后大
                    swap(str[i], str[j]);
                    sort(str.begin() + i + 1, str.end()); // i后边的排序
                    long res = stol(str); /// 转换为数值
                    return res > INT_MAX ? -1 : res;
                }
            }
        }

        return -1; // 来到这儿，则当前的数值是最大的，下一个是最小的了，输出-1
    }
};

int main(int argc, char** argv) {
    int n = 12;

    Solution s;
    int res = s.nextGreaterElement(n);

    cout << res << endl;

    return 0;
}