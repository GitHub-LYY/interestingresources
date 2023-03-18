/*
** Author: Yangyang Liu
** Date: 2023-03-18
** Description: 676. 实现一个魔法字典
** link: https://leetcode.cn/problems/implement-magic-dictionary/
** reference: 题解区，官方题解，方法一
*/

#include <iostream>

using namespace std;

class MagicDictionary {
private:
    vector<string> words; // 字符串数组存放字典
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        words = dictionary; // 字典赋值
    }

    bool search(string searchWord) {
        for (auto str : words) { // 遍历字符串数组中的每个字符串和当前要搜索的字符串进行匹配
            if (str.size() != searchWord.size()) { // 长度不等，则一定不行
                continue; // 不是return false
            }

            // 来到这儿，则一定长度是相等的了，继续判断是否差一个字母
            int diff = 0; // 两个字符串相差的字母数量
            for (int i = 0; i < str.size(); i++) { // 遍历字符串中的每个字符
                if (str[i] != searchWord[i]) { // 字符不等
                    diff++;

                    if (diff > 1) { // 紧接着判断相差字符是否大于1了
                        break; // 继续对比下一个单词
                    }
                }
            }

            if (diff == 1) { // 这儿的diff可能等于0
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    return 0;
}