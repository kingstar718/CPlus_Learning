//
// Created by wujinxing on 2019/10/29.
// 7.9 递归
// 7.16 7.17 程序清单合并
//
#include <iostream>

void countdown(int n);

int main() {
    countdown(4);
    return 0;
}

void countdown(int n) {
    using namespace std;
    cout << "Counting down ... " << n << endl;
    if (n > 0)
        countdown(n - 1);
    cout << n << ": Kaboom!\n";
}