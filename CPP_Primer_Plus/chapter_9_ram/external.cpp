//
// Created by wujinxing on 2019/10/30.
// 9.5 程序清单
// 9.2 全局变量与局部变量
// g++ external.cpp support.cpp 即可得出结果
//
#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);

void local();

int main() {
    cout << "Global warming is" << warming << "degrees.\n";
    update(0.1);
    cout << "Global warming is" << warming << "degrees.\n";
    local();
    cout << "Global warming is" << warming << "degrees.\n";
    return 0;
}

