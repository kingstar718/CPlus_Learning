//
// Created by wujinxing on 2019/11/6.
// Stack类模板的使用
//

#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;

int main() {

    Stack<std::string> st;
    char ch;
    std::string po;

    cout << "Please enter A to add  purcharse order.\n"
         << "P to process a PO, or Q to quit.\n";

    while (cin >> ch && std::toupper(ch) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a Po number to add: ";
                cin >> po;
                if (st.isFull()) {
                    cout << "stack already full\n";
                } else {
                    st.push(po);
                }
                break;
            case 'p':
            case 'P':
                if (st.isEmpty()) {
                    cout << "stack already empty\n";
                } else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                    break;
                }
        }
        cout << "Please enter A to add a purcharse order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}


