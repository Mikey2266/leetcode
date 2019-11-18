#include<iostream>
#include<stack>
#include<windows.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.length() == 0) return 0;
        stack<char> st;
        st.push(s[0]);
        int res = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (st.empty()) res++;
            if ((!st.empty() && st.top() == 'L' && s[i] == 'R') || (!st.empty() && st.top() == 'R' && s[i] == 'L')) {
                st.pop();
                continue;
            }
            else st.push(s[i]);
        }
        return res + 1;
    }
};

int main() {
    string s = "RLRRLLRLRL";
    // long start = GetTickCount();
    cout << Solution().balancedStringSplit(s) << endl;
    // cout << GetTickCount() - start << endl;
    return 0;
}