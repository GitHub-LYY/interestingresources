/*
** Author: Yangyang Liu
** Date: 2022-09-20
** Description: 剑指 Offer 66. 构建乘积数组
** link: https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/
** reference: https://www.bilibili.com/video/BV1bb4y1772i/?spm_id_from=333.337.search-card.all.click
** you only live once，剑指offer说的特别好
** 20221102，238题，官方题解，空间复杂度O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArrOld(vector<int>& a) {
        // 定义left数组
        vector<int> left(a.size(), 0);

        // 定义right数组
        vector<int> right(a.size(), 0);

        // 定义结果数组
        vector<int> res(a.size(), 0);

        if (a.size() == 0) {
            return res;
        }

        // 求left数组
        left[0] = a[0];
        for (int i = 1; i < a.size(); i++) {
            left[i] = left[i - 1] * a[i];
        }

        // 求right数组
        right[right.size() - 1] = a[a.size() - 1];
        for (int i = right.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i];
        }

        // 求结果数组
        res[0] = right[1];
        res[res.size() - 1] = left[left.size() - 2];
        for (int i = 1; i < res.size() - 1; i++) {
            res[i] = left[i - 1] * right[i + 1];
        }

        return res;
    }

    vector<int> constructArr(vector<int>& a) {
        // 定义结果数组
        vector<int> res(a.size());

        // 没有，则剑指offer报错，剑指offer测试用例比LeetCode多点
        if (a.size() == 0) {
            return res;
        }

        // 第一次从前往后遍历，求出每个元素左边的乘积，保存在结果数组中
        res[0] = 1; // 第0个元素左边初始化为1，因为是做乘积运算
        for (int i = 1; i < a.size(); i++) {
            res[i] = res[i - 1] * a[i - 1]; // 每个元素（不包含这个元素）左边数字的乘积
        }

        // 定义变量保存右边的乘积，这个乘积是临时的，用一个遍历即可
        int rightMul = 1; // 最后一个元素右边乘积初始化为1
        // 第二次从后往前遍历，求出结果
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] = res[i] * rightMul; // 最后一个元素开始，先有这句，再有下句求右边乘积
            rightMul *= a[i]; // 巧妙
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> a = {1, 2, 3, 4, 5};

    Solution s;
    vector<int> res = s.constructArr(a);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}