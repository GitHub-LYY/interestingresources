/*
** Author: Yangyang Liu
** Date: 2022-08-20
** Description: 11. 盛最多水的容器
** link: https://leetcode.cn/problems/container-with-most-water/
** reference: 题解区，搜索，【忍者算法】全网最清晰易懂的讲解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 定义变量保存左右边界
        int left = 0;
        int right = height.size() - 1;

        // 定义变量保存最大面积
        int maxArea = 0;

        // 两个指针往中间走
        while (left < right) {
            // 计算当前面积
            int area = (right - left) * min(height[left], height[right]);

            // 更新最大面积
            maxArea = max(maxArea, area);

            // 移动指针
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main(int argc, char** argv) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;
    int maxArea = s.maxArea(height);

    cout << "maxArea:" << maxArea << endl;

    return 0;
}