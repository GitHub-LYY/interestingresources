/*
** Author: Yangyang Liu
** Date: 2022-08-16
** Description: 165. 比较版本号
** link: https://leetcode.cn/problems/compare-version-numbers/
** reference: 题解区，官方题解双指针法
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // 定义两个指针分别指向两个字符串的开头用来遍历两个字符串
        int i = 0;
        int j = 0;

        // 开始每轮循环
        while (i < version1.size() || j < version2.size()) {
            // 定义变量保存第一个版本号的每一段的数字
            int tmp1 = 0; // 初始化为0，如果第一个版本号的某一段没有数字，则默认为0

            for (; i < version1.size() && version1[i] != '.'; i++) {
                // 取出第一个版本号的每一段的数字

                int digit = version1[i] - '0'; // 取出当前字符对应的数字
                // 题目已经说了版本号的每一段只有数字，所以不用判断是否是数字

                tmp1 = tmp1 * 10 + digit; // 求出当前的结果
            }

            // i指针当前指向的是点号，跳过点号
            i++;

            // 第一个版本号的某一段取出了，接下来取第二个版本号的某一段

            // 定义变量保存第二个版本号的每一段的数字
            int tmp2 = 0; // 初始化为0，如果第二个版本号的某一段没有数字，则默认为0

            for (; j < version2.size() && version2[j] != '.'; j++) {
                // 取出第二个版本号的每一段的数字

                int digit = version2[j] - '0'; // 取出当前字符对应的数字
                // 题目已经说了版本号的每一段只有数字，所以不用判断是否是数字

                tmp2 = tmp2 * 10 + digit; // 求出当前的结果
            }

            // j指针当前指向的是点号，跳过点号
            j++;

            //两个版本号对应的某一段取出了，接下来判断二者大小
            if (tmp1 != tmp2) {
                return tmp1 > tmp2 ? 1 : -1;
            }
        }

        // 如果两个版本号的每一段都相等，那么就是相等的
        return 0;
    }
};

int main(int argc, char** argv) {
    string version1 = "1.01";
    string version2 = "1.001";

    Solution s;
    int res = s.compareVersion(version1, version2);

    cout << "res: " << res << endl;
    
    return 0;
}