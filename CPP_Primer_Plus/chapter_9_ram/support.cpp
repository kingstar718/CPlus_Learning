//
// Created by wujinxing on 2019/10/30.
// 9.6 程序清单
// 9.2 全局变量与局部变量
//

#include <iostream>

extern double warming;

void update(double dt);

void local();

using std::cout;

void update(double dt) {
    extern double warming;
    warming += dt;

    cout << "Update global warming to " << warming;
    cout << " degrees.\n";
}

void local() {
    double warming = 0.8;
    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}