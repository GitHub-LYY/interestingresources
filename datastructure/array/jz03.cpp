/*
** Author: Yangyang Liu
** Date: 2022-07-31
** Description: 剑指 Offer 03. 数组中重复的数字
** link: https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
** reference: 
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumberHash(vector<int>& nums) {
        // 遍历整个数组，如果此时的数字不在map中，则其value为true，否则数字在map中，这个数字是重复的
        unordered_map<int, bool> map;
        for(int num : nums) {
            if(map[num]) {
                return num;
            } 
            map[num] = true;
        }
        return -1;
    }

    int findRepeatNumberHereExchange(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] == i) { 
                // 此数字已在对应索引位置，无需交换，因此跳过
                i++;
            } else if (nums[i] == nums[nums[i]]) {
                // 索引 nums[i] 处和索引 i 处的元素值都为 nums[i] ，即找到一组重复值，返回此值 nums[i]
                return nums[i];
            } else {
                // 交换索引为 i 和 nums[i] 的元素值，将此数字交换至对应索引位置
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {

    // 测试用例
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    cout << "Before handling: " << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution s;
    int res = s.findRepeatNumberHash(nums);
    //int res = s.findRepeatNumberHereExchange(nums);

    cout << "After handling: " << endl;
    cout << res << endl;

    return 0;
}