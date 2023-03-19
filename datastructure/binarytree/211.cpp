/*
** Author: Yangyang Liu
** Date: 2023-03-19
** Description: 211. 添加与搜索单词 - 数据结构设计
** link: https://leetcode.cn/problems/design-add-and-search-words-data-structure/
** reference: 官方题解，读题解，读代码，容易理解
*/

#include <iostream>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children; // 前缀树孩子节点
    bool isEnd; // 标记当前节点是否是单词的最后一个字符
    TrieNode() {
        this->children = vector<TrieNode*>(26, nullptr); // 孩子节点初始化
        this->isEnd = false; // 标记初始化
    }
};

class WordDictionary {
private:
    TrieNode* trie; // 定义前缀树
public:
    WordDictionary() {
        trie = new TrieNode(); // 前缀树初始化
    }

    void insert(string word, TrieNode* root) {
        TrieNode* node = root; // 哨兵节点
        for (char ch : word) { // 遍历字符串的每个字符
            int index = ch - 'a'; // 字符在字母表的索引

            if (node->children[index] == nullptr) { // 当前字符对应的节点没有，则创建
                node->children[index] = new TrieNode();
            }

            node = node->children[index]; // 哨兵节点走
        }

        node->isEnd = true; // 此时的哨兵节点是单词的最后一个字符的节点了，进行标记
    }

    void addWord(string word) {
        insert(word, trie); // 单词插入前缀树
    }

    bool dfs(string word, int i, TrieNode* node) {
        if (i == word.size()) { // 此时的索引到达了单词的长度，对应的前缀树的节点刚好是单词的最后一个字符的节点
            return node->isEnd; // 不是true，是这个标记，一开始写错了
        }

        char ch = word[i]; // 当前字符
        if (ch >= 'a' && ch <= 'z') { // 当前字符是字母
            TrieNode* child = node->children[ch - 'a']; // 取出孩子节点
            if (child != nullptr && dfs(word, i + 1, child)) { // 继续下一个字符，第三个参数是child，写错了，不是node了
                return true;
            }
        } else if (ch == '.') { // 当前字符是.，要遍历26个孩子，一个匹配了，则true；必须要写else if，否则报错
            for (int k = 0; k < 26; k++) { // 循环内部把上边的基本copy一下
                TrieNode* child = node->children[k]; // 取出孩子节点
                if (child != nullptr && dfs(word, i + 1, child)) { // 第三个参数是child，不是node了
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(word, 0, trie); // 深度优先
    }
};

int main(int argc, char** argv) {
    return 0;
}