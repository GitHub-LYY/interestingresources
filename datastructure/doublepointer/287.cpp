/*
** Author: Yangyang Liu
** Date: 2023-01-18
** Description: 287. 寻找重复数
** link: https://leetcode.cn/problems/find-the-duplicate-number/
** reference: 官方题解，方法三，快慢指针，先搜索，287.寻找重复数，账号，Kirsche，这个题解容易理解，再去学习官方的实现
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0; // 定义快指针
        int slow = 0; // 定义慢指针
        do {
            slow = nums[slow]; // 相当于链表中的slow=cur->next
            fast = nums[nums[fast]]; // 相当于链表中的fast=cur->next->next
        } while(fast != slow);

        slow = 0; // 慢指针从头开始
        while (fast != slow) {
            slow = nums[slow]; // 走一步即可
            fast = nums[fast]; // 走一步即可
        }

        return slow;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution s;
    int res = s.findDuplicate(nums);

    cout << res << endl;

    return 0;
}