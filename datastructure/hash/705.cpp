/*
** Author: Yangyang Liu
** Date: 2022-08-24
** Description: 705. 设计哈希集合
** link: https://leetcode.cn/problems/design-hashset/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class MyHashSet {
private:
    vector<list<int>> data; // data是一个列表，列表中的每一个元素是一个双向链表，链表的元素是int类型的
    static const int base = 769; // 哈希数组大小，不写static const报错
    static int hash(int key) {
        return key % base;
    }
public:
    MyHashSet() :data(base) {}

    void add(int key) {
        int index = hash(key);

        // 求出哈希值对应的索引后，求出了要去遍历哪一个链表
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if ((*it) == key) {
                // key已经存在集合了，不用操作

                return;
            }
        }

        // 到这儿，则是key不存在集合中，则插入集合
        data[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);

        // 求出哈希值对应的索引后，求出了要去遍历哪一个链表
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if ((*it) == key) {
                // key存在，则删除

                data[index].erase(it);
                return; // 一开始忘记写了
            }
        }

        // 不存在key，没有操作
    }

    bool contains(int key) {
        int index = hash(key);

        // 求出哈希值对应的索引后，求出了要去遍历哪一个链表
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }

        // 如果没有key，则输出false
        return false;
    }
};

int main(int argc, char** argv) {
    MyHashSet myHashSet = new MyHashSet();
    myHashSet.add(1);
    myHashSet.add(2);
    myHashSet.contains(1);
    myHashSet.contains(3);
    myHashSet.add(2);
    myHashSet.contains(2);
    myHashSet.remove(2);
    myHashSet.contains(2);
    return 0;
}