/*
** Author: Yangyang Liu
** Date: 2022-08-28
** Description: 剑指 Offer 31. 栈的压入、弹出序列
** link: https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
** reference: 
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 定义栈来保存pushed的入栈
        stack<int> st;

        // 定义指针指向popped数组
        int j = 0;

        // 遍历pushed数组
        for (int i = 0; i < pushed.size(); i++) {
            // 首先把当前元素入栈
            st.push(pushed[i]);

            // 接下来判断栈顶元素是否和popped数组所指的元素相等
            while (!st.empty() && st.top() == popped[j]) {
                // 相等则出栈，j往后走

                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

int main(int argc, char** argv) {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    Solution s;
    bool res = s.validateStackSequences(pushed, popped);

    cout << "is stack sequence?" << res << endl;

    return 0;
}