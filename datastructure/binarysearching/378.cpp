/*
** Author: Yangyang Liu
** Date: 2023-03-14
** Description: 378. 有序矩阵中第 K 小的元素
** link: https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/
** reference: https://www.bilibili.com/video/BV1kK411n7Bi/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
* b站up，子烁爱学习，视频理解后，再读官方题解
* 题解区，官方题解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1; // 左下角横坐标
        int j = 0; // 左下角纵坐标
        int num = 0; // 左上角数量

        while (i >= 0 && j < n) { // 没有越界
            if (matrix[i][j] <= mid) { // 往右边试探
                num += i + 1; // 一列的数量
                j++; // 往右走
            } else { // 往上试探
                i--; // 往上走
            }
        }

        return num >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); // 方阵的行数、列数
        int left = matrix[0][0]; // 矩阵左上角
        int right = matrix[n - 1][n - 1]; // 矩阵右下角

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(matrix, mid, k, n)) { // 左上角的数量大于等于k
                right = mid;
            } else { // 左上角的数量小于k
                left = mid + 1;
            }
        }

        return left;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    Solution s;
    int res = s.kthSmallest(matrix, k);

    cout << res << endl;

    return 0;
}