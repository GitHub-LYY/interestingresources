/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 470. 用 Rand7() 实现 Rand10()
** link: https://leetcode.cn/problems/implement-rand10-using-rand7/
** reference: 题解区，搜索，从最基础的讲起如何做到均匀的生成随机数
** note: 本题不在本地运行了，直接提交到leetcode上，输出答案与预期不一样也行
*/

#include <iostream>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution {
public:
    int rand10() {
        // 使用永久循环
        while (true) {
            // 等概率生成1-49范围的随机数
            int num = (rand7() - 1) * 7 + rand7();

            // 拒绝采样，变为1-40范围的随机数
            if (num <= 40) {
                return num % 10 + 1;
            }
        }
    }
};

int main(int argc, char** argv) {
    return 0;
}