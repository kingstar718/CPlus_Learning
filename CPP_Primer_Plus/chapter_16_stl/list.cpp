//
// Created by wujinxing on 2019/11/11.
//

#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

void outInt(int n) { std::cout << n << " "; }

int main() {
    using namespace std;

    list<int> one(5, 2); // list of 5 2s

    int stuff[5] = {1, 2, 3, 4, 5};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);

    int more[6] = {6, 7, 8, 9, 10, 11};
    list<int> three;
    three.insert(three.end(), more, more + 6);

    cout <<"List one ";
    for_each(one.begin(), one.end(), outInt);
    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outInt);
    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outInt);

    three.remove(2);
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outInt);
}