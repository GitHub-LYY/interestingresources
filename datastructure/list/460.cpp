/*
** Author: Yangyang Liu
** Date: 2022-08-10
** Description: 460. LFU 缓存
** link: https://leetcode.cn/problems/lfu-cache/
** reference: LeetCode官方题解，双哈希法
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

// 链表节点定义，因为STL的list实现了双向链表，这儿的链表节点不用自己实现前后指针，只用实现最基本且必须的数据结构
struct Node {
    int key;
    int value;
    int freq;
    Node(int _key, int _value, int _freq) : key(_key), value(_value), freq(_freq) {}
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
        list<Node>::iterator nodeIt = itOfKeyTable->second; // itOfKeyTable迭代器是二维的，第二个维度才是Node节点的迭代器
        int cacheVal = nodeIt->value; // 这个是要返回的缓存的值，拿到这个值之后需要做一些操作，最后才返回这个拿到的值
        int cacheFreq = nodeIt->freq; // 根据这个值定位freqTable中的链表，做更新操作，具体操作看下边

        // 从freqTable中删除这个缓存节点
        freqTable[cacheFreq].erase(nodeIt); // erase的调用者是list双向链表，删除这个缓存节点
        // 如果刚才删除的链表只有一个缓存节点，则链表已经被删除了，需要把freqTable这个哈希表对应的记录也删除，且minFreq要+1
        if (freqTable[cacheFreq].size() == 0) { // 链表已经空了，则删除哈希表中的这个记录，且更新minFreq
            freqTable.erase(cacheFreq);
            if (cacheFreq == minFreq) {
                // 如果刚才删除的链表只有一个缓存节点，且这个缓存节点的频次就是minFreq，那么minFreq要+1
                minFreq++;
            }
        }

        // 把这个缓存节点插入到freqTable的freq+1位置的链表的头结点，且更新keyTable对应节点的指向
        freqTable[cacheFreq + 1].push_front(Node(key, cacheVal, cacheFreq + 1)); // 把这个缓存节点再插入到freqTable的freq+1位置的链表的头结点
        keyTable[key] = freqTable[cacheFreq + 1].begin(); // 更新keyTable对应节点的指向

        // 到此，该更新的已经完毕，返回key对应的缓存的值
        return cacheVal;
    }

    void put(int key, int value) {
        // 如果容量为0，则直接返回-1
        if (capacity == 0) {
            return;
        }

        // 定位key对应的缓存节点
        auto itOfKeyTable = keyTable.find(key);

        // 此时还不确定key对应的缓存节点是否存在，因此这儿不能取出itOfKeyTable变量的第二维迭代器，只能在if判断中取出

        // 如果keyTable中没有这个key，则说明是一个新的缓存，需要插入到缓存中
        if (itOfKeyTable == keyTable.end()) {
            // 遍历完没有对应的key

            if (keyTable.size() == capacity) {
                // 删除一定是keyTable和freqTable都删除才行，第一次写，忘记删除keyTable的记录了
                auto itRemove = freqTable[minFreq].back(); // 从freqTable中取出要删除的缓存节点的迭代器，方便keyTable对应缓存节点的删除

                // 删除keyTable中对应的记录
                keyTable.erase(itRemove.key);

                // 上边是keyTable的哈希记录删除了，接下来是freqTable的哈希记录删除操作

                // 容量已经满了，需要删除一个缓存节点
                freqTable[minFreq].pop_back(); // 删除频率最小的那个链表的尾节点，这儿体现了LFU和LRU的使用
                
                if (freqTable[minFreq].size() == 0) {
                    // 如果刚才删除的链表只有一个缓存节点，则链表已经被删除了，需要把freqTable这个哈希表对应的记录也删除，且minFreq要+1
                    freqTable.erase(minFreq);

                    // 这儿不用更新minFreq变量，因为下边马上该插入新的缓存节点了，那时候minFreq被更新为1，这儿不用
                }
            }

            // 能来到这儿，则说明容量没有慢，直接插入到缓存中
            freqTable[1].push_front(Node(key, value, 1)); // 新插入的缓存节点的freq一定是一
            keyTable[key] = freqTable[1].begin(); // 更新keyTable对应节点的指向
            minFreq = 1; // 新插入节点后，最小的频率一定是一
        } else {
            // 能来到这儿，说明keyTable中有这个key，此时只需更新对应的value值即可

            // 和get函数的类似
            auto itUpdate = itOfKeyTable->second; // 取出keyTable对应的缓存节点的迭代器的第二个维度的迭代器
            int cacheFreq = itUpdate->freq; // 取出要更新的缓存节点的频次
            freqTable[cacheFreq].erase(itUpdate); // 先从freqTable中删除这个缓存节点
            if (freqTable[cacheFreq].size() == 0) { // 删除完刚才的缓存节点后，链表空了
                freqTable.erase(cacheFreq); // 删除freqTable哈希表中对应的哈希记录
                if (cacheFreq == minFreq) {
                    minFreq++;
                }
            }

            // 把这个缓存节点插入到freqTable的freq+1位置的链表的头结点，且更新keyTable对应节点的指向
            freqTable[cacheFreq + 1].push_front(Node(key, value, cacheFreq + 1)); // 把这个缓存节点再插入到freqTable的freq+1位置的链表的头结点
            keyTable[key] = freqTable[cacheFreq + 1].begin(); // 更新keyTable对应节点的指向

            // 到此，更新完value的值了，该更新的也完毕了，没有返回值
        }
    }
};

int main(int argc, char** argv) {
    LFUCache* lfu = new LFUCache(2); // LeetCode的例子只是参考
    lfu->put(1, 1); // LeetCode用的是.
    lfu->put(2, 2);
    cout <<"get(1): " << lfu->get(1) << endl;
    lfu->put(3, 3);
    cout <<"get(2): " << lfu->get(2) << endl;
    cout <<"get(3): " << lfu->get(3) << endl;
    lfu->put(4, 4);
    cout <<"get(1): " << lfu->get(1) << endl;
    cout <<"get(3): " << lfu->get(3) << endl;
    cout <<"get(4): " << lfu->get(4) << endl;
    
    return 0;
}