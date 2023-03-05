/*
** Author: Yangyang Liu
** Date: 2023-03-05
** Description: 542. 01 矩阵
** link: https://leetcode.cn/problems/01-matrix/
** reference: https://www.bilibili.com/video/BV1dY41147w2/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 自己理解后写的
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(); // 行数
        int col = mat[0].size(); // 列数
        queue<pair<int, int>> que; // 队列保存坐标
        int distance = 1; // 距离，0和1的距离
        vector<int> dir_row = {1, 0, -1, 0}; 
        vector<int> dir_col = {0, 1, 0, -1};

        // 遍历矩阵，求出0的坐标保存在队列中
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) { // 当前格子中是0
                    que.push(make_pair(i, j));
                }
                if (mat[i][j] == 1) {
                    mat[i][j] = -1;
                }
            }
        }

        while (!que.empty()) {
            int size = que.size(); // 当前层的0

            for (int i = 0; i < size; i++) {
                int x = que.front().first; // 横坐标
                int y = que.front().second; // 纵坐标
                que.pop(); // 不要忘了弹出队列

                // 开始用distance污染下一层
                for (int j = 0; j < 4; j++) {
                    // 求出四周的格子的坐标
                    int xx = x + dir_row[j]; 
                    int yy = y + dir_col[j];

                    if (xx >= 0 && xx < row && yy >= 0 && yy < col && mat[xx][yy] == -1) { // 污染下一层
                        mat[xx][yy] = distance;
                        que.push(make_pair(xx, yy)); // 下一层格子坐标入队
                    }
                }
            }

            distance++; // 下一层了
        }

        return mat;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution s;
    vector<vector<int>> res = s.updateMatrix(mat);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}