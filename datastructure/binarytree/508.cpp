/*
** Author: Yangyang Liu
** Date: 2023-01-20
** Description: 508. 出现次数最多的子树元素和
** link: https://leetcode.cn/problems/most-frequent-subtree-sum/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> sum2num; // 和-次数哈希表
    int maxCount = 0;
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) { // 空节点，和是0
            return 0;
        }

        int sum = root->val + dfs(root->left) + dfs(root->right); // 树的和

        sum2num[sum]++; // sum出现次数多了一次
        maxCount = max(maxCount, sum2num[sum]); // 副产品，求出最大次数

        return sum; // 这才是正业，输出和
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res; // 定义变量保存结果

        for (auto keyvalue : sum2num) {
            int sum = keyvalue.first; // 取出和
            int num = keyvalue.second; // 取出次数
            if (num == maxCount) { // 遍历哈希表，当前次数是最大次数，则把对应的和放入结果
                res.emplace_back(sum);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    Solution s;
    vector<int> res = s.findFrequentTreeSum(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}