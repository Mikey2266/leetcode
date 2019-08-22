#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x, ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    // vector<int> num_1 = {10, 9, 2, 5, 3, 4};
    int x = 2147395599;
    // long start = GetTickCount();
    cout << Solution().mySqrt(x);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}