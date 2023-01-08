/*
** Author: Yangyang Liu
** Date: 2023-01-07
** Description: 609. 在系统中查找重复文件
** link: https://leetcode.cn/problems/find-duplicate-file-in-system/
** reference: 题解区，官方题解解释后没有代码，理解了，搜索，简单高效，执行用时超过99%、内存消耗超过95%
** 作者，zumin
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> str2vec; // 字符串-字符串数组哈希表
        for (auto str : paths) { // 遍历字符串
            int space = str.find(' '); // 求出第一个空格的位置
            string path = str.substr(0, space) + '/'; // 取出路径，最后加上/为了下边拼接文件名
            int leftBracket = str.find('(', space); // 从第一个空格开始求出第一个小括号的位置
            while(leftBracket != -1) { // 在当前字符串中仍有小括号，则意味着有文件没有遍历完
                string fileName = str.substr(space + 1, leftBracket - space - 1); // 取出文件名
                int rightBracket = str.find(')', leftBracket); // 求出当前左括号匹配的右括号
                str2vec[str.substr(leftBracket + 1, rightBracket - leftBracket - 1)].emplace_back(path + fileName); // 哈希表插入一条记录

                leftBracket = str.find('(', rightBracket + 1); // 求出下一个左括号
                space = rightBracket + 1; // 更新此时的空格位置方便求出下一个文件名
            }
        }

        vector<vector<string>> res;
        for (auto keyvalue : str2vec) { // 遍历哈希表
            if (keyvalue.second.size() >= 2) { // value有大于一条记录，意味着有重复了
                res.emplace_back(keyvalue.second);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};

    Solution s;
    vector<vector<string>> res = s.findDuplicate(paths);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}