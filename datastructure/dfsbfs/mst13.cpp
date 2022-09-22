/*
** Author: Yangyang Liu
** Date: 2022-09-22
** Description: 面试题13. 机器人的运动范围
** link: https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/?favorite=xb9nqhhg
** reference: 题解区，官方题解，评论区，作者，腌菜读作梦想，深度优先搜索DFS，写的很好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // 定义visit数组记录是否已经访问过当前的格子了
    vector<vector<bool>> visit; // 这儿不可以使用m，n来初始化

    // 定义变量保存结果
    int count = 0;
public:
    int getSum(int num) {
        // 取出每一位的数进行求和运算

        int sum = 0;

        while (num) {
            // num不位0，则一直求和

            sum += num % 10; // 求最后一位的和

            num /= 10; // 舍弃最后一位
        }

        return sum;
    }

    void dfs(int m, int n, int k, int i, int j) {
        // i，j是访问的格子的坐标

        if (i < 0 || i >= m || j < 0 || j >= n || visit[i][j] || (getSum(i) + getSum(j)) > k) {
            return;
        }

        visit[i][j] = true;
        count++; // 数量加一

        // 递归右边和下边
        dfs(m, n, k, i + 1, j);
        dfs(m, n, k, i, j + 1);

        return;
    }

    int movingCount(int m, int n, int k) {
        visit = vector<vector<bool>>(m, vector<bool>(n, false));

        dfs(m, n, k, 0, 0);

        return count;
    }
};

int main(int argc, char** argv) {
    int m = 2; 
    int n = 3;
    int k = 1;

    Solution s;
    int res = s.movingCount(m, n, k);

    cout << res << endl;

    return 0;
}