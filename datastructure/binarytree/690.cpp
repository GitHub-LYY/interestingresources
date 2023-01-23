/*
** Author: Yangyang Liu
** Date: 2023-01-23
** Description: 690. 员工的重要性
** link: https://leetcode.cn/problems/employee-importance/
** reference: 官方题解，层序遍历
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee() : id(0), importance(0), subordinates(vector<int> ()) {}
    Employee(int _id, int _importance, vector<int> _subordinates) : id(_id), importance(_importance), subordinates(_subordinates) {}
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id2employee; // 员工编号-员工信息哈希表
        for (auto employee : employees) { // 遍历所有员工，填充哈希表
            id2employee[employee->id] = employee;
        }

        int res = 0; // 定义变量保存结果
        queue<int> que; // 定义队列保存员工的编号
        que.push(id); // 二叉树根节点入队
        while (!que.empty()) {
            int idTmp = que.front(); // 从队列取出员工编号
            que.pop();
            Employee* em = id2employee[idTmp]; // 从哈希表取出当前员工的信息
            res += em->importance; // 累加求出重要性
            for (auto subId : em->subordinates) { // 遍历当前节点的所有子节点，入队
                que.push(subId);
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Employee* employee1 = nullptr;
    employee1->id = 1;
    employee1->importance = 5;
    employee1->subordinates = (vector<int>){2, 3};
    Employee* employee2 = nullptr;
    employee2->id = 2;
    employee2->importance = 3;
    employee2->subordinates = (vector<int>){};
    Employee* employee3 = nullptr;
    employee3->id = 3;
    employee3->importance = 3;
    employee3->subordinates = (vector<int>){};
    vector<Employee*> employees;
    employees.emplace_back(employee1);
    employees.emplace_back(employee2);
    employees.emplace_back(employee3);
    int id = 1;

    Solution s;
    int res = s.getImportance(employees, id);

    cout << res << endl;

    return 0;
}