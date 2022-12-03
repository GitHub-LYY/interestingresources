/*
** Author: Yangyang Liu
** Date: 2022-12-03
** Description: 306. 累加数
** link: https://leetcode.cn/problems/additive-number/
** reference: 代码随想录，题解区，搜索，回溯三部曲清晰框架
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(int argc, char** argv) {
    string num = "112358";

    Solution s;
    bool res = s.isAdditiveNumber(num);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}