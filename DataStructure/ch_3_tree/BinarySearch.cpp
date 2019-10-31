//
// Created by wujinxing on 2019/10/31.
//
#include <iostream>

using namespace std;

class List {
private:
    int *data;
    int len;
public:
    List(int arr[], int n) {
        data = arr;
        len = n;
    };

    int List_len() {
        return len;
    }

    int Position(int i) {
        return data[i];
    }

    ~List() {
        cout << "destroy..." << endl;
    }
    void Show(){
        for (int i = 0; i < len; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int BinarySearch(List L, int k) {

    int left = 0, right = L.List_len() - 1, NotFound = -1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (k < L.Position(mid))
            right = mid - 1;
        else if (k > L.Position(mid))
            left = mid + 1;
        else
            return mid;
    }
    return NotFound;
}

/* 你的代码将被嵌在这里 */
int BinarySearch2(List L, int X) {
    int left = 0, right = L.List_len();
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (L.Position(mid) == X) {
            return mid;
        } else if (L.Position(mid) > X) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    List L = {arr, 5};
    L.Show();
    int pos = BinarySearch2(L, 1);
    cout << pos << endl;
    return 0;
}

