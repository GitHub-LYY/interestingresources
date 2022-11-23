/*
** Author: Yangyang Liu
** Date: 2022-11-23
** Description: 443. 压缩字符串
** link: https://leetcode.cn/problems/string-compression/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // 定义指针
        int write = 0; // 从0位置开始写
        int read = 0; // 从0开始遍历
        int left = 0; // 一开始最左边的边界

        // 遍历
        while (read < chars.size()) {
            if (read == chars.size() - 1 || chars[read] != chars[read + 1]) {
                // 每次read指到一组相同字符末尾的时候，要处理了

                chars[write++] = chars[read]; // 直接在原始数组上修改，修改完别忘记write++了
                int len = read - left + 1; // 左闭右闭，因此要+1才是长度
                if (len > 1) {
                    // 1不用处理，大于1需要求出长度

                    // 保存现场
                    int anchor = write; // 一开始忘记写，必须

                    while (len > 0) {
                        // 2-9也适用，这儿本质是处理大于等于两位数的情况

                        chars[write++] = len % 10 + '0'; // 不断求数字的最后一位数字
                        len /= 10; // 去除最后一位
                    }
                    reverse(&chars[anchor], &chars[write]); // 别忘了数字插入是逆序，因此要再逆序一次，刚好是左闭右开，右边界是write
                }

                // 左边界要改变了，一开始忘记了，错的
                left = read + 1;
            }

            // 别忘记read++了
            read++;
        }

        return write;
    }
};

int main(int argc, char** argv) {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    Solution s;
    int res = s.compress(chars);

    cout << res << endl;

    return 0;
}