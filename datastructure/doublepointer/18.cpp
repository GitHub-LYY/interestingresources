/*
** Author: Yangyang Liu
** Date: 2023-01-08
** Description: 18. 四数之和
** link: https://leetcode.cn/problems/4sum/
** reference: 题解区，官方题，三数之和、四数之和要一块学，类似
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 必须排序
        int len = nums.size(); // 数组长度
        if (nums.size() < 4) {
            return res;
        }

        for (int first = 0; first < len - 3; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) { // 去掉重复的first
                continue;
            }
            if ((long)nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) { // 右边的数字更大，一定求不出了
                break;
            }
            if ((long)nums[first] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) { // 此时的小，则直接右移
                continue;
            }

            for (int second = first + 1; second < len - 2; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) { // 去掉重复的second
                    continue;
                }
                if ((long)nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) { // 右边的数字更大声，一定求不出了
                    break;
                }
                if ((long)nums[first] + nums[second] + nums[len - 1] + nums[len - 2] < target) { // 此时的小，则直接右移
                    continue;
                }
                int third = second + 1;
                int fourth = len - 1; // fourth不能放在second之前

                while (third < fourth) { // 遍历third了
                    long sum = (long)nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) { // 满足条件
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]}); // 插入结果了
                        while (third < fourth && nums[third] == nums[third + 1]) { // 去掉重复的third
                            third++;
                        }
                        third++; // 不要忘记这儿还有一个++操作才是走到不重复的数字了
                        while (fourth > third && nums[fourth] == nums[fourth - 1]) { // 去掉重复的fourth
                            fourth--; // fourth也要走，因为此时的fourth位置一定不满足了，因为third也走了
                        }
                        fourth--;
                    } else if (sum > target) {
                        fourth--;
                    } else {
                        third++;
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution s;
    vector<vector<int>> res = s.fourSum(nums, target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}