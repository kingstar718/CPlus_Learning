//
// Created by wujinxing on 2019/9/29.
//
#include <string>

using namespace std;
using std::string;

int def() {

    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c'); //s4的内容是cccccccccc

    string s5 = "hello" + s3; //必须确保每个加法运算符+的两侧的运算对象至少有一个是string

    string str("str string");
    for (auto c: str)
        cout << c << endl;
    return 0;
}

int getLine() {

    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
}