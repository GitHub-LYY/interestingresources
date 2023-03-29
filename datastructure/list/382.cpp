/*
** Author: Yangyang Liu
** Date: 2023-03-29
** Description: 382. 链表随机节点
** link: https://leetcode.cn/problems/linked-list-random-node/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

int main(int argc, char** argv) {
    return 0;
}