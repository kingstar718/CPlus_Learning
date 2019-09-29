//
// Created by wujinxing on 2019/9/29.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using std::vector;

/**
 * vector表示对象集合，所有对象的类型都相同，每个对象都有对应的索引
 */
int demo1() {
    vector<int> iVec;
    vector<vector<string>> file;
    vector<int> iVec2(iVec); //将iVec的元素拷贝给iVec2
    vector<int> iVec3 = {1, 2, 3, 4, 5};
    vector<string> sVec{"a", "ab", "abc"};
    for (auto s:sVec)
        cout << s << endl;

    //添加元素
    for (int i = 0; i < 100; ++i) {
        iVec.push_back(i);
    }
    for (auto i: iVec)
        cout << i;

    for (auto &i: iVec) //这里使用引用
        i *= i;
    for (auto i: iVec)
        cout << i << " ";
    return 0;
}

int iter() {
    string s("some string");
    //首字母改大写
    if (s.begin() != s.end()) {
        auto it = s.begin();  //it表示s的第一个字符
        *it = toupper(*it);  //将当前字符改成大写形式
    }
    cout << s.data() <<endl;
    return 0;
}