/*
** Author: Yangyang Liu
** Date: 2022-12-19
** Description: 393. UTF-8 编码验证
** link: https://leetcode.cn/problems/utf-8-validation/
** reference: 题解区，搜索，C++清晰简单的模拟思路，通过右移进行判断，账号，苏隐，特别好，容易理解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // 定义变量保存data首字节后有几个字节
        int dataIndex = 0;

        for (int num : data) {
            if (dataIndex == 0) {
                // 这是首字节

                if (num >> 5 == 0b110) {
                    // 判断两个字节的情况

                    dataIndex = 1; // 尾部有一个字节，总共两个字节
                } else if (num >> 4 == 0b1110) {
                    // 判断三个字节的情况

                    dataIndex = 2; // 还剩2个字节，总共三个字节
                } else if (num >> 3 == 0b11110) {
                    // 判断四个字节的情况

                    dataIndex = 3; // 还剩3个字节，总共4个字节
                } else if (num >> 7) {
                    // 为1，则一定不是

                    return false;
                }
            } else {
                // 不是首字节了

                if (num >> 6 != 0b10) {
                    // 不满足条件

                    return false;
                }
                dataIndex--; // 要计数减一了
            }
        }

        return dataIndex == 0;
    }
};

int main(int argc, char** argv) {
    vector<int> data = {197, 130, 1};

    Solution s;
    bool res = s.validUtf8(data);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}