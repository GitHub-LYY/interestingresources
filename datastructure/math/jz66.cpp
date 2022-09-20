/*
** Author: Yangyang Liu
** Date: 2022-09-20
** Description: 剑指 Offer 66. 构建乘积数组
** link: https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/
** reference: https://www.bilibili.com/video/BV1bb4y1772i/?spm_id_from=333.337.search-card.all.click
** you only live once，剑指offer说的特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
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