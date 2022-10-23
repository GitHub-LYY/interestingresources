/*
** Author: Yangyang Liu
** Date: 2022-10-23
** Description: 661. 图片平滑器
** link: https://leetcode.cn/problems/image-smoother/
** reference: https://www.bilibili.com/video/BV1Fh411h7TZ/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** up，搜索，IT精品课程传送门，说的特别好，这个up
** 官方题解不容易理解，这个容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // 直接使用int类型的数定义方向数组
        int dir[8][2] = {
            {1, 0}, // 下
            {-1, 0}, // 上
            {0, -1}, // 左
            {0, 1}, // 右
            {-1, 1}, // 右上
            {-1, -1}, // 左上
            {1, -1}, // 左下
            {1, 1} // 右下
        }; // 8个方向

        // 计算img的行数和列数
        int numRow = img.size();
        int numCol = img[0].size();

        // 定义变量保存结果
        vector<vector<int>> res(numRow, vector<int>(numCol));

        // 遍历每一个格子
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                // 遍历每一个格子前，定义变量sum和count来求这个格子的平滑值
                int sum = img[i][j];
                int count = 1; // 自己是一个

                // 遍历周围的8个格子
                for (int k = 0; k < 8; k++) {
                    // 求出每个方向格子的坐标
                    int x = i + dir[k][0];
                    int y = j + dir[k][1]; // 纵坐标

                    // 计算出某个方向的格子的坐标后，先判断这个格子有没有越界
                    if (x < 0 || x >= numRow || y < 0 || y >= numCol) { // x，y有等号，否则段错误
                        continue; // 直接继续下一个没有被遍历的格子
                    }

                    sum += img[x][y];
                    count++;
                }

                // 该收割了
                res[i][j] = sum / count; // 当前格子的平滑值
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    Solution s;
    vector<vector<int>> res = s.imageSmoother(img);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}