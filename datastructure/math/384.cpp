/*
** Author: Yangyang Liu
** Date: 2023-03-31
** Description: 384. 打乱数组
** link: https://leetcode.cn/problems/shuffle-an-array/
** reference: 题解区，官方题解
*/

#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> nums;
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); i++) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

int main(int argc, char** argv) {
    return 0;
}