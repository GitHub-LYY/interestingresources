/*
** Author: Yangyang Liu
** Date: 2023-01-02
** Description: 430. 扁平化多级双向链表
** link: https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/
** reference: https://www.bilibili.com/video/BV1X34y1o7m6/?spm_id_from=333.337.search-card.all.click&vd_source=2359173fba44be579729aa03546398fa
** B站up，锦鲤的如意喵，说的特别好
*/

# include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        // 链表为空
        if (head == nullptr) {
            return head;
        }

        // 定义节点遍历链表
        Node* node = head;

        while (node) {
            // 节点不是空，则遍历

            if (node->child) { // 孩子节点不是空，则要操作了
                Node* next = node->next; // 临时保存当前有孩子节点的下一个节点备用
                node->next = node->child; // 当前节点next指向它的child节点
                node->next->prev = node; // 相互指向对方
                node->child = nullptr; // 不要忘了当前节点的孩子节点置空，因为孩子节点已经成为它的next节点了
                
                // 求出当前节点的原来的孩子节点带领的链表的最后一个节点
                Node* child = node->next; // 定义节点用来遍历原来孩子节点带领的链表
                Node* endChild = nullptr; // 定义节点保存最后一个节点
                while (child) { // 遍历链表的条件
                    endChild = child; // 一开始忘写了
                    child = child->next;
                }
                endChild->next = next; // 求出了最后一个节点
                // 把上边求出的最后一个节点和当前遍历节点原来的最后一个节点拼接
                if (next) { // 原来的next节点必须不是空的才能修改它的指向节点
                    next->prev = endChild;
                }
            }

            node = node->next;
        }

        return head;
    }
};

int main(int argc, char **argv) {
    return 0;
}