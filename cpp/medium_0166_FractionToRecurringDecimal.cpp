#include<iostream>
#include<windows.h>
#include<map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long t = numerator, d = denominator;
        map<long long, int> A;
        string ans;
        if (t * d < 0) ans = "-";
        t = abs(t), d = abs(d);
        ans += to_string(t / d);
        t %= d;
        if (!t) return ans;
        ans += '.';
        while (t) {
            if (A.count(t)) {
                ans.insert(A[t], "("), ans.push_back(')');
                return ans;
            }
            A[t] = ans.size(), ans += '0' + t * 10 / d;
            t = t * 10 % d;
        }
        return ans;
    }
};

int main() {
    int numerator = 23, denominator = 99;
    // long start = GetTickCount();
    cout << Solution().fractionToDecimal(numerator, denominator);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}