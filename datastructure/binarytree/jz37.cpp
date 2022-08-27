/*
** Author: Yangyang Liu
** Date: 2022-08-27
** Description: 剑指 Offer 37. 序列化二叉树
** link: https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/
** reference: 题解区，搜索，【C++】DFS（前序遍历，递归）/BFS（层序遍历，迭代）（注释版），作者：骄阳似我，层序遍历版本
*/

#include <iostream>

using namespace std;

// 树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 定义队列保存树节点
        queue<TreeNode*> que;

        // 定义变量保存序列化结果
        string res;

        // 如果根节点不为空，入队
        if (root != nullptr) {
            que.push(root);
        }

        // 层序遍历
        while (!que.empty()) {
            // 保存每一层的节点个数
            int size = que.size();

            // 遍历每一层的节点
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node != nullptr) {
                    // 如果节点不为空，把节点值加入序列化结果中，把左右子节点加入队列
                    res += to_string(node->val) + ",";
                    que.push(node->left);
                    que.push(node->right);
                } else {
                    // 如果节点为空，则把none加入序列化结果中

                    res += "None,"; // 第一版，忘记写逗号了，报错
                }
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 如果输入为空，则树也为空
        if (data.empty()) {
            return nullptr;
        }

        // 把树的每个节点值从输入字符串中分割出来
        // 由于涉及到频繁的插入操作，因此使用list链表来存放节点值
        list<string> dataArray;
        string str; // 中间变量，用来暂时保存分割出来的每个树节点值
        for (char c : data) {
            if (c == ',') {
                // 每个树节点值之间使用的是逗号分隔的

                dataArray.push_back(str); // 逗号前已经分割出一个节点值了，把它加入链表中
                str.clear(); // 完成使命，清空中间变量
            } else {
                // 刚开始没有逗号，所以刚开始要把节点值加入链表

                str += c;
            }
        }

        // 以上逻辑没有把最后一个节点值加入链表，所以单独处理
        if (str.size() != 0) { // 上边写的None后边有逗号，所以这儿必须判断尺寸
            dataArray.push_back(str);
        }

        // 定义队列保存树节点
        queue<TreeNode*> que;

        // 如果dataArray第一个元素只为None，则树为空
        if (dataArray.front() == "None") {
            return nullptr;
        }

        // 求出根节点
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.pop_front(); // 保证下边的循环是从第二层节点开始的

        // 根节点入队
        que.push(root);

        // 循环
        while (!que.empty() && !dataArray.empty()) {
            // 保存每一层的节点个数
            int size = que.size();

            // 遍历每一层的节点
            for (int i = 0; i < size && !dataArray.empty(); i++) {
                TreeNode* node = que.front();
                que.pop();

                // 插入根节点的左子节点
                if (dataArray.front() != "None") {
                    node->left = new TreeNode(stoi(dataArray.front()));
                    que.push(node->left);
                }
                dataArray.pop_front(); // 是否为none都必须pop

                // 插入根节点的右子节点
                if (dataArray.front() != "None") {
                    node->right = new TreeNode(stoi(dataArray.front()));
                    que.push(node->right);
                }
                dataArray.pop_front();
            }
        }

        return root;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec s;
    string res = s.serialize(root);
    TreeNode* node = s.deserialize(res);

    return 0;
}