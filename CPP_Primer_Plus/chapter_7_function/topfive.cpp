//
// Created by wujinxing on 2019/10/29.
// 清单 7.15
// chapter 7.7 函数和string对象
//
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5;

void display(const string sa[], int n);

int main() {
    string list[SIZE];
    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list:\n";
    display(list, SIZE);

    return 0;
}

void display(const string sa[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << sa[i] << endl;
    }
}
