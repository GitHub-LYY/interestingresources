/*
** Author: Yangyang Liu
** Date: 2023-03-18
** Description: 380. O(1) 时间插入、删除和获取随机元素
** link: https://leetcode.cn/problems/insert-delete-getrandom-o1/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> num2index; // 数字-动态数组索引哈希表
public:
    RandomizedSet() {
        srand((unsigned)time(NULL)); // 参考官方题解
    }

    bool insert(int val) {
        if (num2index.count(val)) { // 已经存在了，则false
            return false;
        }

        int len = nums.size(); // 此时的长度是插入后的索引
        nums.emplace_back(val); // 插入尾部
        num2index[val] = len; // 哈希表存储
        return true; // 插入成功
    }

    bool remove(int val) {
        if (!num2index.count(val)) { // 不存在
            return false;
        }

        int index = num2index[val]; // 要被覆盖的下标位置
        int last = nums.back(); // 取出最后一个数
        nums[index] = last; // 覆盖当前要删除的数
        num2index[last] = index; // 哈希表
        nums.pop_back(); // 数组中删除最后一个数
        num2index.erase(val); // 哈希表删除
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

int main(int argc, char** argv) {
    return 0;
}