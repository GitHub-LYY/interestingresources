/*
** Author: Yangyang Liu
** Date: 2023-03-20
** Description: 677. 键值映射
** link: https://leetcode.cn/problems/map-sum-pairs/
** reference: 题解区，官方题解，方法一，暴力方法，容易理解，容易写
*/

#include <iostream>

using namespace std;

class MapSum {
private:
    unordered_map<string, int> str2val; // 字符串-值哈希表
public:
    MapSum() {

    }

    void insert(string key, int val) {
        str2val[key] = val; // 插入哈希表
    }

    int sum(string prefix) {
        int sum = 0; // 和

        for (auto keyval : str2val) { // 遍历哈希表
            if (keyval.first.substr(0, prefix.size()) == prefix) { // key的前缀和prefix相等
                sum += keyval.second;
            }
        }

        return sum;
    }
};

int main(int argc, char** argv) {
    return 0;
}