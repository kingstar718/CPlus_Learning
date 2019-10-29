//
// Created by wujinxing on 2019/10/29.
// 8.2 引用变量
// 8.2 程序清单
//
#include <iostream>

int main() {
    using namespace std;
    int rats = 101;
    int &rodents = rats; // rodents is a reference
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    // ------------
    int *prat = &rats;
    cout << "prat = " << prat;
    cout << ", *prat = " << *prat;
    cout << ", &prat = " << &prat;
    cout << ", &*prat = " << &*prat << endl;

    return 0;
}
