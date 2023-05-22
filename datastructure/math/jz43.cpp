/*
** Author: Yangyang Liu
** Date: 2022-09-10,20230522
** Description: 剑指 Offer 43. 1～n 整数中 1 出现的次数
** link: https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/?favorite=xb9nqhhg
** reference: https://www.bilibili.com/video/BV1uJ411573j?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** 说的特别好，作者，Akarinnnn_
** 20230522，题解区，搜索，思路+多语言代码10分钟讲清楚！
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class SolutionOld {
public:
    int countDigitOne(int n) {
        // 如果n为负数，则直接返回0
        if (n < 0) {
            return 0;
        }
        
        // 定义变量保存数字n转换为的字符串，方便取每一位的数字
        string str = to_string(n);

        // 定义变量保存结果
        int count = 0;

        // 把str逆序，方便从低位开始遍历
        reverse(str.begin(), str.end());

        for (int i = 0; i < str.size(); i++) {
            // 这个循环中始终以百位为例子进行思考，其他的类似的

            // 求出百位左边的数字
            int left = n / pow(10, i + 1); // pow返回是浮点型，转换为int类型
            int right = pow(10, i); // 右边是从00 - 99共100种情况

            // 收割第一类的结果
            count += left * right;

            // ------ //

            // 取出百位的数字，看看和一的关系来求结果
            int digit = str[i] - '0'; // 从字符转换为数字

            if (digit > 1) {
                // 大于1则百位后边有00-99共100种情况

                count += pow(10, i); // 这一开始写为100了，这是以百位举例子，不是100啊
            } else if (digit == 1) {
                // 等于1则百位后边有right+1种情况

                count += n % int(pow(10, i)) + 1; // 这的int强制类型转换不能没有，否则报错，上边的不用有
            } else {
                // 小于1则有0种情况

                count += 0;
            }
        }

        return count;
    }
};

class Solution {
   public:
    int countDigitOne(int n) {
        // "1"出现的次数 = sum ("1"在各个计数位上出现的次数)
        // 从个位开始向最高位统计
        // 3101592
        // 将数字拆分为[a...][cur][b...]
        // cur 为当前位
        long base = 1;
        int res = 0;
        while (base <= n) {
            // 计算 a..., cur, b...
            int a, cur, b;
            a = n / base / 10;
            cur = (n / base) % 10;
            b = n % base;
            // 将当前位设为1，考察其他部分的变化范围
            if (cur > 1) {
                // 一、cur > 1，
                //          [3101 ] 5 [92]
                // 变化范围：[0-3101] 1 [0-99]
                // 总个数：   (a+1)  *  base
                res += (a + 1) * base;
            } else if (cur == 1) {
                // 二、cur == 1，
                //             [310] 1 [592]
                // 1、变化范围 [0-309] 1 [0-999]
                //              a    *  base
                // 2、变化范围 [310]   1 [0-592]
                //               1   *   (b+1)
                // 总个数：a *base + (b + 1)
                res += a*base + b + 1;

            } else {
                // 三、cur < 1，
                //           [31] 0 [1592]
                // 变化范围 [0-30] 1 [0-9999]
                // 总个数    a     *   base
                res += a * base;
            }
            // 统计更高一位
            base *= 10;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    int n = 12;

    Solution s;
    int res = s.countDigitOne(n);

    cout << res << endl;

    return 0;
}