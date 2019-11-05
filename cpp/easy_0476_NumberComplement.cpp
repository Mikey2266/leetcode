#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// https://leetcode-cn.com/problems/number-complement/solution/c-ji-suan-gao-wei-jian-dan-wei-yun-suan-by-da-li-w/
class Solution {
public:
    const int N = sizeof(int) * 8;
    // // 二分法找到最高位, 普通
    // int findHighBit(long long n) {
    //     int left = 0;
    //     int right = N ;
    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if (n >= ((long long)1 << mid)) {
    //             left = mid + 1;
    //         } else {
    //             right = mid - 1;
    //         }
    //     }
    //     return right;
    // }
    // 二分法找到最高位, 较快
    int findHighBit(long long n) {
        int left = 0;
        int right = N;
        while (left < right) {
            int mid = left + (right - mid + 1) / 2;
            if (n >= ((long long)1 << mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int findComplement(int num) {
        int high_mask = ((long long)1 << (findHighBit(num) + 1)) - 1;
        return high_mask ^ num;
    }
};

int main() {
    int n = 5;
    // long start = GetTickCount();
    cout << Solution().findComplement(n) << endl;
    // cout << GetTickCount() - start << endl;
    return 0;
}