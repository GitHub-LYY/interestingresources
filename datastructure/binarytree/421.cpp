/*
** Author: Yangyang Liu
** Date: 2023-03-20
** Description: 421. 数组中两个数的最大异或值
** link: https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
** reference: https://www.bilibili.com/video/BV1jv41157Mx/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** b站，up，奇艺儿。直接读官方题解的前缀树方法的代码，代码比题解容易理解，但是代码有一些细节不是容易理解，
** 看b站的这个视频，理解了
*/

#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    Trie* left = nullptr;; // 0节点
    Trie* right = nullptr; // 1节点
    Trie() {}
};

class Solution {
private:
    Trie* root = new Trie(); // 前缀树，一开始忘记new了，报段错误
    int HIGH_BIT = 30; // 共31位，索引最高位是30
public: 
    void add(int num) {
        Trie* cur = root; // 哨兵节点

        for (int i = HIGH_BIT; i >= 0; i--) { // 从最高位开始，前缀树从上到下是从最高位开始的
            int bit = (num >> i) & 1; // 遍历31位的每一位

            if (bit == 0) { // 往左的0走
                if (!cur->left) { // 发现左边的0节点没有，则创建后再走到它
                    cur->left = new Trie();
                }
                cur = cur->left; // 走到左的0节点
            } else { // 往右的1走
                if (!cur->right) { // 发现右边的1节点没有，则创建后走到它
                    cur->right = new Trie();
                }
                cur = cur->right; // 哨兵节点走
            }
        }

        return;
    }

    int check(int num) {
        Trie* cur = root; // 哨兵节点从根节点走
        int x = 0;

        for (int i = HIGH_BIT; i >= 0; i--) { // 从当前数的最高位走
            int bit = (num >> i) & 1; // 求出每一位的是0还是1

            if (bit == 0) { // 这一位是0，希望数上同一层有1
                if (cur->right) { // 如果这一层的1节点存在
                    cur = cur->right; // 哨兵走到这
                    x = x * 2 + 1; // 意思是x左移一位再加一，是把x的第i位置为1
                } else {
                    cur = cur->left; // 这一层的1节点不存在，则走到0节点喽
                    x = x * 2; // 左移一位，x的第i为置为0
                }
            } else { // 这一位是1，希望树上这一层有0
                if (cur->left) { // 如果这一层的0节点存在，则能异或为1了
                    cur = cur->left; // 哨兵走到0节点
                    x = x * 2 + 1; // 把x的第i位置为1
                } else { // 这一层的0节点不存在，则不能异或位1了
                    cur = cur->right; // 哨兵走到1节点
                    x = x * 2; // x的第i为置0
                }
            }
        }

        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size(); // 数组长度
        int x = 0; // 异或的结果

        for (int i = 1; i < len; i++) {
            add(nums[i - 1]); // nums[0],nums[1],...nums[len-2]插入前缀树

            x = max(x, check(nums[i])); // 巧妙
        }

        return x;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {3, 10, 5, 25, 2, 8};

    Solution s;
    int res = s.findMaximumXOR(nums);

    cout << res << endl;

    return 0;
}