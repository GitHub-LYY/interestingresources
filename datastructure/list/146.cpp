/*
** Author: Yangyang Liu
** Date: 2022-08-10
** Description: 146. LRU 缓存
** link: https://leetcode.cn/problems/lru-cache/
** reference: LeetCode官方题解
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// 双向链表节点定义
struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache; // 定义LRUCache对象的成员变量，哈希表内部有双向链表
    DLinkedNode* dummyHead; // 定义虚拟头节点方便操作
    DLinkedNode* dummyTail; // 定义虚拟尾节点方便操作
    int size; // 定义变量保存当前缓存的大小，为后边判断是否超出容量做准备
    int capacity; // 定义变量保存缓存的容量，这是题目给定的，没有商量

public:
    LRUCache(int _capacity) : size(0), capacity(_capacity) {
        dummyHead = new DLinkedNode(); // 初始化虚拟头节点
        dummyTail = new DLinkedNode(); // 初始化虚拟尾节点
        dummyHead->next = dummyTail; // 一开始把虚拟头节点指向虚拟尾节点
        dummyTail->prev = dummyHead; // 一开始把虚拟尾节点指向虚拟头节点
    }

    int get(int key) {
        // 如果缓存中key没有找到，则返回-1
        if (cache.count(key) == 0) {
            return -1;
        }

        // 如果缓存汇总key找到了，则把这个节点移动到链表的头部，且返回这个节点的值
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        // 如果缓存中key不存在，则创建一个新的节点，插入到链表的头部
        if (cache.count(key) == 0) {
            DLinkedNode* node = new DLinkedNode(key, value); // 创建新节点
            addToHead(node); // 把新节点插入到链表的头部
            cache[key] = node; // 把新节点插入到哈希表中

            // 判断是否超出容量限制
            size++;
            if (size > capacity) {
                DLinkedNode* removedNode = removeTail(); // 删除链表的尾部节点
                cache.erase(removedNode->key); // 删除哈希表中对应的项
                delete removedNode; // 释放内存
                size--; // 更新缓存的大小
            }
        } else {
            // 如果缓存中key存在，则把这个节点的值更新为新的值，然后把这个节点移动到链表的头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void removeNode(DLinkedNode* node) {
        // 删除双向链表的节点是处理好这个节点的前后节点的指针
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node) {
        // 把虚拟头节点和这个插入的节点串起来
        // 先处理这个节点
        node->prev = dummyHead;
        node->next = dummyHead->next;

        // 再处理虚拟头节点
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

    void moveToHead(DLinkedNode* node) {
        // 先把这个节点从链表中删除
        removeNode(node);

        // 再把这个节点添加到链表的头部
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        // 核心思想，利用虚拟尾节点删除链表的尾部节点

        // 先获取链表的尾部节点
        DLinkedNode* tailNode = dummyTail->prev;

        // 再把这个节点从链表中删除
        removeNode(tailNode);

        // 返回链表尾节点
        return tailNode;
    }
};

int main(int argc, char** argv) {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << "get key = 1:" << cache->get(1) << endl;    
    cache->put(3, 3);
    cout << "get key = 2:" << cache->get(2) << endl;
    cache->put(4, 4);
    cout << "get key = 1:" << cache->get(1) << endl;
    cout << "get key = 3:" << cache->get(3) << endl;
    cout << "get key = 4:" << cache->get(4) << endl;
    
    return 0;
}