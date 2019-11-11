//
// Created by wujinxing on 2019/11/11.
// instroducing the vector template
//
#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main() {

    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> rating(NUM);
    vector<string> titles(NUM);
    cout << "You will do exaactly as told. You will enter\n"
         << NUM << " book titles and your rating (0-10).\n";

    int i;
    for (int i = 0; i < NUM; ++i) {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter you rating (0-10): ";
        cin >> rating[i];
        cin.get();
    }

    cout << "Thank you. You entered the following:\n"
         << "Rating\tBook\n";

    for (i = 0; i < NUM; i++) {
        cout << rating[i] << "\t" << titles[i] << endl;
    }

    return 0;
}
