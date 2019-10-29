//
// Created by wujinxing on 2019/10/29.
//
#include <iostream>

using namespace std;

int MaxSeqSum(int arr[], int n);

int main() {
    int k;
    cin >> k;
    int arr[k];
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }

    int sum = MaxSeqSum(arr, k);
    cout << sum;

    return 0;
}

int MaxSeqSum(int arr[], int n) {
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    int i;
    for (i = 0; i < n; ++i) {
        ThisSum += arr[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}