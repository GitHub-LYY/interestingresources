/*
** Author: Yangyang Liu
** Date: 2022-11-13
** Description: 49. 字母异位词分组
** link: https://leetcode.cn/problems/group-anagrams/
** reference: 题解区，方法一
** push_back方法也能插入一个vector，本题自己写的是这种
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 定义哈希表
        unordered_map<string, vector<string>> umap; // key是string，data是vector<string>

        // 遍历字符串数组
        for (auto str : strs) {
            // 先做排序
            string key = str;
            sort(key.begin(), key.end());

            // 根据key插入data
            umap[key].push_back(str); // 使用push_back也行
        }

        // 定义变量保存结果
        vector<vector<string>> res;

        // 遍历哈希表
        for (auto it = umap.begin(); it != umap.end(); it++) {
            res.push_back(it->second); // 使用push_back也行，官方题解用的是emplace_back
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(strs);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}