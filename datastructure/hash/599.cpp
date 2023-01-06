/*
** Author: Yangyang Liu
** Date: 2023-01-06
** Description: 599. 两个列表的最小索引总和
** link: https://leetcode.cn/problems/minimum-index-sum-of-two-lists/
** reference: 题解区，官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> name2index; // 餐厅名字-索引哈希表
        for (int i = 0; i < list1.size(); i++) { // 填充哈希表
            name2index[list1[i]] = i;
        }

        vector<string> res; // 定义变量保存结果
        int indexSum = INT_MAX; // 定义变量保存最小索引和
        for (int i = 0; i < list2.size(); i++) {
            if (name2index.count(list2[i]) > 0) { // 有共同的餐厅了
                int j = name2index[list2[i]]; // 求出索引
                if (i + j < indexSum) {
                    res.clear(); // 先把结果置空
                    res.push_back(list2[i]); // 再把当前餐厅插入结果
                    indexSum = i + j; // 更新索引和
                } else if (i + j == indexSum) { // 是最小索引和，继续插入结果
                    res.push_back(list2[i]); 
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    Solution s;
    vector<string> res = s.findRestaurant(list1, list2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}