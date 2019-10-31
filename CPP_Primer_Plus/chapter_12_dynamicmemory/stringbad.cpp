//
// Created by wujinxing on 2019/10/31.
//

#include "stringbad.h"
#include <cstring>

using std::cout;

// 不能再类声明中初始化静态成员变量
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s) {

    len = std::strlen(s);   // set size
    str = new char[len + 1];  // allot storage
    // 如何指向 不能写成str = s，只保存了地质，而没有创建字符串副本
    std::strcpy(str, s);    //initialize pointer
    num_strings++;  // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n";
}

StringBad::StringBad() {

    len = 4;   // set size
    str = new char[4];  // allot storage
    std::strcpy(str, "C++");    //initialize pointer
    num_strings++;  // set object count
    cout << num_strings << ": \"" << str
         << "\" default object created\n";
}

StringBad::~StringBad() {

    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[]str;
}

std::ostream &operator<<(std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}