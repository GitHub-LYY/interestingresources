/*
** Author: Yangyang Liu
** Date: 2023-01-07
** Description: 554. 砖墙
** link: https://leetcode.cn/problems/brick-wall/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> right2num; // 砖块右侧位置-出现次数，不包括最后的右侧
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0; // 累加砖块右侧位置
            for (int j = 0; j < wall[i].size() - 1; j++) { // 遍历每一层
                sum += wall[i][j]; // 每个数是砖块宽度
                right2num[sum]++;
            }
        }

        

        int maxCount; // 定义变量保存右侧出现次数最多的数量
        for (auto keyvalue : right2num) { // 遍历哈希表
            int value = keyvalue.second; // 取出次数
            maxCount = max(maxCount, value);
        }

        return wall.size() - maxCount;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};

    Solution s;
    int res = s.leastBricks(wall);

    cout << res << endl;

    return 0;
}