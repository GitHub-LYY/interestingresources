/*
** Author: Yangyang Liu
** Date: 2022-08-13
** Description: 15. 三数之和
** link: https://leetcode.cn/problems/3sum/
** reference: 代码随想录
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 定义变量保存结果
        vector<vector<int>> res;

        // 如果数组长度小于3，直接返回
        if (nums.size() < 3) {
            return res;
        }

        // 使用双指针必须对数组排序
        sort(nums.begin(), nums.end());

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 如果遍历的第一个元素大于0，则一定不存在三数之和等于0的情况
            if (nums[i] > 0) {
                break;
            }

            // 对a+b+c=0，此时i指向的是a，先对a去重，必须使用下边的去重逻辑
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 定义left指针和right指针
            int left = i  + 1; // left在i+1的位置
            int right = nums.size() - 1;

            while (left < right) { // left不能等于right，如果left等于right，则凑不够三个数了
                // 如果三个指针所指元素之和大于0，则right指针左移
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    // 如果三个指针所指元素之和小于0，则left指针右移

                    left++;
                } else {
                    // 如果三个指针所指元素之和等于0，则将结果保存到res中，b和c去重

                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        // b去重

                        left++; // 此时left指向的还是b，下边必须再减一次，才是去重完成
                    }
                    left++;

                    while (left , right && nums[right] == nums[right - 1]) {
                        // c去重

                        right--;
                    }
                    right--;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution s;
    vector<vector<int>> res = s.threeSum(nums);

    cout << "a+b+c=0 is:" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}