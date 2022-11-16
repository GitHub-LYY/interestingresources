/*
** Author: Yangyang Liu
** Date: 2022-11-16
** Description: 535. TinyURL 的加密与解密
** link: https://leetcode.cn/problems/encode-and-decode-tinyurl/
** reference: 题解区，官方题解，方法一，使用id
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, string> database; // 存放id对应的longurl的数据库
    int id; // 使用id作为key
public:
    // 构造函数初始化id
    Solution () {
        id = 0;
    }

    string encode(string longUrl) {
        // id进来先++
        id++;

        // 把id对应的这个longurl放入数据库
        database[id] = longUrl;

        return "https://tinyurl.com/" + to_string(id);
    }

    string decode(string shortUrl) {
        // 求出id所在的位置
        int i = shortUrl.rfind('/') + 1; // '/'的下一个位置

        // 求出id
        int key = stoi(shortUrl.substr(i, int(shortUrl.size()) - i));

        return database[key]; // 数据库保存的是longurl
    }
};

int main(int argc, char** argv) {
    string url = "https://leetcode.com/problems/design-tinyurl";
    Solution* obj = new Solution();
    string tiny = obj->encode(url);
    string ans = obj->decode(tiny);

    cout << tiny << endl;
    cout << ans << endl;

    return 0;
}