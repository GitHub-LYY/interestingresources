/*
** Author: Yangyang Liu
** Date: 2023-02-01
** Description: 652. 寻找重复的子树
** link: https://leetcode.cn/problems/find-duplicate-subtrees/
** reference: 官方题解
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    unordered_map<string, TreeNode*> str2node; // 字符串-子树哈希表
    unordered_set<TreeNode*> nodeUset; // 保存去重后的重复的子树
public:
    /*
     * 作用：二叉树的序列化
     * root: 子树
     * 输出：序列化后的字符串
     */
    string dfs(TreeNode* root) {
        if (!root) { // 遍历到空节点，字符串中也是空
            return "";
        }

        // 单纯的二叉树的序列化，这已经可以直接输出了，但是现在的序列有用，因此先保存一下
        string serial = to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";

        auto it = str2node.find(serial); // 官方题解放在if()括号中，则编译器有warning，放在外边，没有warning了
        if (it != str2node.end()) { // 存在重复的子树
            nodeUset.insert(it->second); // 收割
        } else { // 哈希表中没有出现，则插入哈希表
            str2node[serial] = root;
        }

        return serial;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {nodeUset.begin(), nodeUset.end()};
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    Solution s;
    vector<TreeNode*> res = s.findDuplicateSubtrees(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i]->val << " ";
    }

    return 0;
}