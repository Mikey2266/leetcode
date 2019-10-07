#include<iostream>
#include<vector>
#include<windows.h>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> temp = {INT_MAX};
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == C) {
                temp.push_back(i);
            }
        }
        temp.push_back(INT_MAX);
        vector<int> res;
        int j = 1;
        for (int i = 0; i < S.length();) {
            if (i <= temp[j]) {
                res.push_back(min(abs(temp[j] - i), abs(temp[j - 1] - i)));
                i++;
            }
            else {
                j++;
            }
        }
        return res;
    }
};

int main() {
    string S = "loveleetcode";
    char C = 'e';
    // long start = GetTickCount();
    vector<int> res = Solution().shortestToChar(S, C);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}