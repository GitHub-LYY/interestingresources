/*
** Author: Yangyang Liu
** Date: 2023-01-29
** Description: 331. 验证二叉树的前序序列化
** link: https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/
** reference: 官方题解
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size(); // 定义变量保存字符串长度
        int i = 0; // 定义索引遍历字符串
        int slots = 1; // 初始值一定是1，最后遍历完字符串后是0了，则true
        while (i < len) {
            if (slots == 0) { // 遍历字符串中，出现slot是0，则一定是false
                return false;
            }

            if (preorder[i] == ',') { // 当前遍历的字符是逗号
                i++;
            } else if (preorder[i] == '#') { // 当前遍历的字符串是#号
                slots--; // #号，则减一
                i++; // 不要忘了索引往后走
            } else { // 当前遍历到了数值了，把数值遍历完，槽多一
                while (i < len && preorder[i] != ',') { // 把一个数值遍历出来
                    i++;
                }
                slots++; // slot = slot - 1 + 2;是数值了，则消耗一个槽，多两个槽
            }
        }

        return slots == 0; 
    }
};

int main(int argc, char** argv) {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";

    Solution s;
    bool res = s.isValidSerialization(preorder);

    if (res == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}