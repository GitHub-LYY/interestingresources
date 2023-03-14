/*
** Author: Yangyang Liu
** Date: 2023-03-14
** Description: 137. 只出现一次的数字 II
** link: https://leetcode.cn/problems/single-number-ii/
** reference: https://www.bilibili.com/video/BV1VR4y1L7gu?spm_id_from=333.337.search-card.all.click
** b站up，YouOnly_LiveOnce，宝藏up，剑指offer系列特别好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> binarySumVec(32); // 32位的每一位的和

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) { // 当前位是1了，则要求和
                    binarySumVec[j]++;
                }
            }
        }

        int res = 0; // 结果
        for (int i = 0; i < 32; i++) {
            binarySumVec[i] %= 3; // 对3取模
            res |= (binarySumVec[i] << i); // 做或操作转换十进制
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {2, 2, 3, 2};

    Solution s;
    int res = s.singleNumber(nums);

    cout << res << endl;

    return 0;
}