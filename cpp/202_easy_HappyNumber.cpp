#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (s.count(n)) break;
            s.insert(n);
        }
        return n == 1;
    }
};

int main() {
    int x = 9;
    // long start = GetTickCount();
    cout << Solution().isHappy(x);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}