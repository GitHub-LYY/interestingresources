/*
** Author: Yangyang Liu
** Date: 2022-09-08
** Description: 剑指 Offer 45. 把数组排成最小的数
** link: https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
** reference: 题解区，搜索，C++ 先转换成字符串再组合，评论区版本，作者，sxmayd
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    class Cmp {
    public:
        bool operator()(string s1, string s2) {
            return (s1 + s2) < (s2 + s1);
        }
    };
    string minNumber(vector<int>& nums) {
        // 定义变量保存字符串数组
        vector<string> strVec;

        // 定义变量保存结果
        string res;

        // 把nums数组转换为字符串数组
        for (auto num : nums) {
            strVec.push_back(to_string(num));
        }

        // 对字符串数组进行排序
        sort(strVec.begin(), strVec.end(), Cmp());

        // 排完序，则依次拼接
        for (auto str : strVec) {
            res += str;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {10, 2};

    Solution s;
    string res = s.minNumber(nums);

    cout << res << endl;

    return 0;
}