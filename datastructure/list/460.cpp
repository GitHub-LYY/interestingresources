/*
** Author: Yangyang Liu
** Date: 2022-08-10
** Description: 460. LFU 缓存
** link: https://leetcode.cn/problems/lfu-cache/
** reference: LeetCode官方题解，双哈希法
*/

#include <iostream>

using namespace std;

// 链表节点定义，因为STL的list实现了双向链表，这儿的链表节点不用自己实现前后指针，只用实现最基本且必须的数据结构
struct Node {
    int key;
    int value;
    int freq;
    Node() : key(0), value(0), freq(0) {}
};

class LFUCache {
private:
    // LFUCache对象的成员变量
    int capacity; // 定义变量保存缓存的容量，这是题目给定的，没有商量
    int minFreq; // 定义变量保存当前最小频次，这个变量是为了在删除节点时使用的
    unordered_map<int, list<Node>::iterator> keyTable; // 定义哈希表保存key及其对应的链表节点的迭代器，方便定位链表节点
    unordered_map<int, list<Node>> freqTable; // 定义哈希表保存频次及其对应的双向链表，这个是LFUCache的核心数据结构

public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        minFreq = 0;
        keyTable.clear();
        freqTable.clear();
    }

    int get(int key) {
        // 异常情况，如果容量为0，查不出来
        if (capacity == 0) {
            return -1;
        }

        // 如果keyTable中没有key，说明缓存中也没有这个key对应的缓存，返回-1
        auto itOfKeyTable = keyTable.find(key);
        if (itOfKeyTable == keyTable.end()) {
            return -1;
        }

        // 能来到这儿，则说明缓存中有这个key对应的缓存
        // 定义变量保存这个缓存的基本信息
        int cacheVal = itOfKeyTable->value; // 这个是要返回的缓存的值，拿到这个值之后需要做一些操作，最后才返回这个拿到的值
        int cacheFreq = itOfKeyTable->freq; // 根据这个值定位freqTable中的链表，做更新操作，具体操作看下边

        // 从freqTable中删除这个缓存节点
        freqTable[cacheFreq].erase(itOfKeyTable); // erase的调用者是list双向链表，删除这个缓存节点
        // 如果刚才删除的链表只有一个缓存节点，则链表已经被删除了，需要把freqTable这个哈希表对应的记录也删除，且minFreq要+1
        if (freqTable[cacheFreq].size() == 0) { // 链表已经空了，则删除哈希表中的这个记录，且更新minFreq
            
        }
    }
};

int main(int argc, char** argv) {
    return 0;
}