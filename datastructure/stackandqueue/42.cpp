/*
** Author: Yangyang Liu
** Date: 2022-08-07
** Description: 42. 接雨水
** link: https://leetcode.cn/problems/trapping-rain-water/
** reference: 
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trapMonotonicStack(vector<int>& height) {
        // 异常情况
        if (height.size() < 3) {
            return 0;
        }

        // 定义栈，保存数组元素的下标
        stack<int> st;

        // 首先把数组第一个元素的下标入栈
        st.push(0);

        // 定义变量保存接雨水的容量
        int capacity = 0;

        // 从下标1开始遍历数组
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) { // 下一个元素比栈顶元素小，下标入栈
                st.push(i);
            } else if (height[i] == height[st.top()]) { // 下一个元素和栈顶元素相等，先把栈顶元素弹出，再入栈当前元素下标
                st.pop();
                st.push(i);
            } else { // 下一个元素比栈顶下标对应的元素大，则有凹槽，技术容量
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top(); // 凹槽的下标
                    st.pop(); // 作用一：凹槽下标出栈，作用而：凹槽下标的前一个元素下标出栈，结束if判断和while循环
                    if (!st.empty()) {
                        int left = st.top(); // 凹槽左边界的下标
                        int right = i; // 凹槽右边界的下标
                        int h = min(height[left], height[right]) - height[mid]; // 凹槽的高度
                        int w = right - left - 1; // 凹槽的宽度
                        capacity += h * w;
                    }
                }
                st.push(i);
            }
        }

        return capacity;
    }

    int trapDynamicProgramming(vector<int>& height) {
        // 异常情况
        if (height.size() < 3) {
            return 0;
        }

        // 定义变量保存接雨水的容量
        int capacity = 0;

        // 定义数组保存每个元素左边的最大高度
        vector<int> maxLeft(height.size(), 0);

        // 定义数组保存每个元素右边的最大高度
        vector<int> maxRight(height.size(), 0);

        // 初始化数组
        maxLeft[0] = 0;
        maxRight[height.size() - 1] = 0;

        // 动态规划计算每个元素左边的最大高度
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        // 动态规划计算每个元素右边的最大高度
        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // 计算接雨水的容量
        for (int i = 0; i < height.size(); i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) {
                capacity += count;
            }
        }

        return capacity;
    }
};

int main(int argc, char** argv) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "height array is:" << endl;
    for (int i = 0; i < height.size(); i++) {
        cout << height[i] << " ";
    }
    cout << endl;

    Solution s;
    //int capacity = s.trapMonotonicStack(height);
    int capacity = s.trapDynamicProgramming(height);

    cout << "capacity is: " << capacity << endl;

    return 0;
}