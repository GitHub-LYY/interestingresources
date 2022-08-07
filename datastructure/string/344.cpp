/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 344. 反转字符串
** link: https://leetcode.cn/problems/reverse-string/
** reference: 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 定义双指针
        int i = 0;
        int j = s.size() - 1;

        // 双指针交换
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main(int argc, char** argv) {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    cout << "before reverse: " << endl;
    for (auto c : s) {
        cout << c << " ";
    }

    Solution sol;
    sol.reverseString(s);

    cout << "after reverse: " << endl;
    for (auto c : s) {
        cout << c << " ";
    }

    return 0;
}