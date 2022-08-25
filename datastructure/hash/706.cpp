/*
** Author: Yangyang Liu
** Date: 2022-08-25
** Description: 706. 设计哈希映射
** link: https://leetcode.cn/problems/design-hashmap/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769; // 哈希表数组大小
    static int hash(int key) {
        return key % base;
    }
public:
    MyHashMap() : data(base) {}

    void put(int key, int value) {
        int index = hash(key);

        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                it->second = value; // key已经存在映射中了，则更新对应的value值
                return; // 更新完立即return
            }
        }

        // 来到这儿，则映射不存在key，插入这个键值对
        data[index].push_back(make_pair(key, value));

        return;
    }

    int get(int key) {
        int index = hash(key);

        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                // key存在映射中了，则返回value值

                return it->second;
            }
        }

        // 来到这儿，则不存在key
        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                // 存在key的映射，则删除

                data[index].erase(it);
                return; // 删除完立即返回
            }
        }

        // 来到这儿，则不存在
        return;
    }
};

int main(int argc, char** argv) {
    MyHashMap myHashMap = new MyHashMap();
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    myHashMap.get(1);
    myHashMap.get(3);
    myHashMap.put(2, 1);
    myHashMap.get(2);
    myHashMap.remove(2);
    myHashMap.get(2);
    return 0;
}