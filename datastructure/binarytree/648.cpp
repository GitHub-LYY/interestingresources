/*
** Author: Yangyang Liu
** Date: 2023-03-19
** Description: 648. 单词替换
** link: https://leetcode.cn/problems/replace-words/
** reference: 官方题解，前缀树法，仔细读代码，能理解
*/

#include <iostream>

using namespace std;

struct Trie {
    unordered_map<char, Trie*> children; // 前缀树孩子节点
};

class Solution {
public:
    vector<string> split(string sentence, char ch) {
        int pos = 0; // 两个指针之一
        int start = 0; // 两个指针之一
        int len = sentence.size(); // 字符串长度
        vector<string> res;

        while (pos < len) {
            while (pos < len && sentence[pos] == ch) { // 空格
                pos++;
            }

            start = pos; // start指向字符串的开始位置
            while (pos < len && sentence[pos] != ch) { // 不是空格
                pos++;
            }

            if (start < len) {
                res.emplace_back(sentence.substr(start, pos - start)); // 取出一个字符串
            }
        }

        return res;
    }

    string findRoot(string word, Trie* node) {
        string root; // 词根
        Trie* cur = node; // 哨兵节点

        for (char ch : word) {
            if (cur->children.count('#')) { // 是词根了
                return root; 
            }
            if (!cur->children.count(ch)) { // 没有这个字符，则没有词根
                return word;
            }

            root.push_back(ch); // 拼接词根
            cur = cur->children[ch]; // 哨兵节点走
        }

        return root;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie(); // 定义前缀树

        for (string word : dictionary) { // 字典放入前缀树
            Trie* node = trie; // 哨兵节点
            for (char ch : word) { // 遍历每个单词的每个字符
                if (!node->children.count(ch)) { // 当前字符的节点不存在，则创建
                    node->children[ch] = new Trie();
                }
                node = node->children[ch]; // 哨兵节点走
            }
            node->children['#'] = new Trie(); // 一开始忘了
        }

        vector<string> words = split(sentence, ' '); // 字符串中的每个字符串放入字符串数组
        for (auto& word : words) { // 遍历每个字符串
            word = findRoot(word, trie); // 用词根替换
        }

        string res;
        for (int i = 0; i < words.size() - 1; i++) { // 此时已经替换为词根了
            res.append(words[i]); // 插入单词
            res.append(" "); // 插入空格
        }
        res.append(words.back()); // 插入最后一个单词
        return res;
    }
};

int main(int argc, char** argv) {
    return 0;
}