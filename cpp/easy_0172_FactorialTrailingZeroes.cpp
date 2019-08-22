#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n) {
               ret += n / 5;
               n /= 5;
        }
        return ret;
    }
};

int main() {
    int x = 10;
    // long start = GetTickCount();
    cout << Solution().trailingZeroes(30);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}