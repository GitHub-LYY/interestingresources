/*
** Author: Yangyang Liu
** Date: 2023-02-21
** Description: 17. 电话号码的字母组合
** link: https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
** reference: 题解区，官方题解，忍者算法，理解后，自己写的
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, string> digit2letters = {{'0', ""},
                                                {'1', ""},
                                                {'2', "abc"},
                                                {'3', "def"},
                                                {'4', "ghi"},
                                                {'5', "jkl"},
                                                {'6', "mno"},
                                                {'7', "pqrs"},
                                                {'8', "tuv"},
                                                {'9', "wxyz"}}; // 数字字符-字符串哈希表
    vector<string> combinations; // 定义变量保存结果
public:
    void backtrack(const string& digits, string& combination) {
        if (combination.size() == digits.size()) { // 要收集的字符串的长度满足要求了，要收割了
            combinations.emplace_back(combination);
            return; // 直接退出，不使用if-else的else了
        }

        char digit = digits[combination.size()]; // 取出当前要的数字字符
        string letters = digit2letters[digit]; // 从哈希表中取出数字字符对应的字母字符串
        for (auto& letter : letters) { // 遍历取出的字母字符串中的每一个字母字符
            combination.push_back(letter); // 保存一条路径上的某个字母字符到结果字符串
            backtrack(digits, combination); // 在combination的基础上继续递归
            combination.pop_back(); // 回溯不要忘记弹出
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) { // 当前字符串是空的
            return combinations;
        }

        string combination; // 定义变量保存结果中的某个字符串结果
        backtrack(digits, combination);
        return combinations;
    }
};

int main(int argc, char** argv) {
    string digits = "23";

    Solution s;
    vector<string> res = s.letterCombinations(digits);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}