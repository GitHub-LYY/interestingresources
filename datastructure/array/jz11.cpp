/*
** Author: Yangyang Liu
** Date: 2022-08-01
** Description: 剑指 Offer 11. 旋转数组的最小数字
** link: https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
** reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 使用排序
    int minArraySort(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
    
    // 使用遍历
    int minArrayTraversal(vector<int>& numbers) {
        // 定义一个变量保存最小值
        int minNum = INT32_MAX;
        // 遍历数组，不断把最小值保存到变量中
        for (int i = 0; i < numbers.size(); i++) {
            if (minNum > numbers[i]) {
                minNum = numbers[i];
            } else {
                continue;
            }
        }

        // 遍历完数组，返回最小值
        return minNum == INT32_MAX ? -5001 : minNum;
    }
};

int main(int argc, char** argv) {
    vector<int> numbers = {3, 4, 5, 1, 2};

    cout << "numbers:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    Solution s;
    int res = s.minArrayTraversal(numbers);

    cout <<"The min number is: " << res << endl;

    return 0;
}