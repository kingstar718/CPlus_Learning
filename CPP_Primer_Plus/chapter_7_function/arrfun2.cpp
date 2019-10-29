//
// Created by wujinxing on 2019/10/29.
//
#include <iostream>

const int ArSize = 8;

int sum_arr(int arr[], int n); //prototype
void show_array(const int arr[], int n);

int main() {


    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    std::cout << cookies << " = array address, ";
    std::cout << sizeof(cookies) << " = size of cookies\n";

    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    sum = sum_arr(cookies, 3); //计算前三个元素的和
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, 4); //计算5678四个数的和
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    //只读数组
    show_array(cookies, ArSize);
    return 0;
}

int sum_arr(int arr[], int n) {
    int total = 0;
    std::cout << arr << " = arr, ";
    std::cout << sizeof(arr) << " = sizeof arr\n";
    for (int i = 0; i < n; ++i) {
        total += arr[i];
    }
    return total;
}

void show_array(const int arr[], int n) {
    using namespace std;
    for (int i = 0; i < n; ++i) {
        cout << "Property # " << (i + 1) << ": $";
        cout << arr[i] << endl;
    }
}