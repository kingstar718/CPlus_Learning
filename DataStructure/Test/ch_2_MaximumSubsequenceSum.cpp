//
// Created by wujinxing on 2019/11/1.
//

/*
 * 找出最大子序列的和以及首尾的节点下标
 * Sample Input
 * 6
 * -2 11 -4 13 -5 -2
 * 10
 * -10 1 2 3 4 -5 -23 3 7 -21
 * 6
 * 5 -8 3 2 5 0
 * 1
 * 10
 * 3
 * -1 -5 -2
 * 3
 * -1 0 -2
 * 0
 * Sample Output
 * 20 11 13
 * 10 1 4
 * 10 3 5
 * 10 10 10
 * 0 -1 -2
 * 0 0 0
 */

//	最大和前面有一段是0	答案错误

#include <iostream>

void MaximumSubsequenceSum(int a[], int n);

using namespace std;

int main() {
    int n;
    int a[100000 + 5];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    MaximumSubsequenceSum(a, n);
    return 0;
}

void MaximumSubsequenceSum(int a[], int n) {
    int left = 0;
    int tmpLeft = 0;
    int right = n - 1;
    int max = 0;
    int tmpSum = 0;
    for (int i = 0; i < n; ++i) {
        tmpSum += a[i];
        if (tmpSum < 0) {
            tmpSum = 0;
            tmpLeft = i + 1; // 新的开头数就是被丢弃的子序列的下一个
        } else if (max < tmpSum) {
            max = tmpSum;
            left = tmpLeft; // 每次更新最大值也就确定了一段子序列，保存此时的开头
            right = i;  // 结尾的数就是每次更新的最大值的下标
        }
    }
    if (max >= 0) {
        cout << max << " " << a[left] << " " << a[right];
    } else {
        cout << 0 << " " << a[0] << " " << a[n - 1];
    }
}