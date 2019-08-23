#include<iostream>
#include<windows.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> each;
        backTrack(s, each, res);
        return res;
    }

    void backTrack(string s, vector<string>& each, vector<vector<string>>& res) {
        int len = s.length();
        if (!s.length()) {
            res.push_back(each);
            return;
        }
        for (int i = 1; i <= len; ++i) {
            string temp = s.substr(0, i);
            if (isPalindrome(temp)) {
                each.push_back(temp);
                backTrack(s.substr(i, len - i), each, res);
                each.erase(each.end());
            }
        }
    }
    
    bool isPalindrome(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; ++i)
            if (s[i] != s[len - i - 1])
                return false;
        return true;
    };
};

int main() {
    string s = "acbc";
    // long start = GetTickCount();
    vector<vector<string>> res;
    res = Solution().partition(s);
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}