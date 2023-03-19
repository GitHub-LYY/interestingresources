/*
** Author: Yangyang Liu
** Date: 2023-03-19
** Description: 208. 实现 Trie (前缀树)
** link: https://leetcode.cn/problems/implement-trie-prefix-tree/
** reference: 题解区，搜索，208. 实现 Trie (前缀树)，作者，sy4b，先把这个作者的视频理解了，再去
** 学习官方题解，也理解了
*/

#include <iostream>

using namespace std;

class Trie {
private:
    vector<Trie*> children; // 孩子节点
    bool isEnd; // 标记当前节点是否是一个单词的结束了

    Trie* prefixSearch(string prefix) {
        Trie* node = this; // 哨兵节点，先定位在当前节点

        for (char ch : prefix) { // 遍历字符串的每个字符
            int index = ch - 'a'; // 字符在字母表的索引

            if (node->children[index] == nullptr) {
                return nullptr; // 一开始这写错了
            }

            node = node->children[index]; // 哨兵节点走
        }

        return node; // 输出最后一个节点
    }
public:
    Trie() : children(26), isEnd(false) { // 直接初始化了

    }

    void insert(string word) {
        Trie* node = this; // 当前节点
        for (char ch : word) { // 遍历单词的每个字符
            int index = ch - 'a'; // 当前字符在字母表的索引

            if (node->children[index] == nullptr) { // 当前节点的这个字符对应的孩子节点是空的，则创建
                node->children[index] = new Trie();
            }

            node = node->children[index]; // 哨兵节点往下走，最后落在单词最后一个字符的节点位置
        }

        node->isEnd = true; // 当前节点是单词的最后一个字符了
    }

    bool search(string word) {
        Trie* node = this->prefixSearch(word); // 搜索出最后一个字符的节点
        return node != nullptr && node->isEnd == true; // 满足两个条件
    }

    bool startsWith(string prefix) {
        Trie* node = this->prefixSearch(prefix); // 搜索出最后一个字符的节点
        return node != nullptr; // 满足一个条件
    }
};

int main(int argc, char** argv) {
    return 0;
}