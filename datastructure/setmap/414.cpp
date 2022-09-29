/*
** Author: Yangyang Liu
** Date: 2022-09-29
** Description: 414. 第三大的数
** link: https://leetcode.cn/problems/third-maximum-number/
** reference: 官方题解，方法二，有序集合
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 定义有序集合
        set<int> s;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]); // 插入每一个数字

            // 如果数量大于3，则删除小的那个
            if (s.size() > 3) {
                // 删除有序集合的第一个数

                s.erase(s.begin());
            }
        }

        return s.size() == 3 ? *(s.begin()) : *(s.rbegin());
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 1};

    Solution s;
    int res = s.thirdMax(nums);

    cout << res << endl;

    return 0;
}