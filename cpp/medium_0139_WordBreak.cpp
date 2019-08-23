#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         if (s.empty() || s.length() == 0) return false;
//         vector<bool> res(s.length() + 1, false);
//         res[0] = true;
//         for (int i = 0; i < s.length(); ++i) {
//             string temp = s.substr(0, i + 1);
//             for (int j = 0; j <= i; ++j) {
//                 if (res[j] && dict.count(temp)) {
//                     res[i + 1] = true;
//                     break;
//                 }
//                 temp = temp.substr(1, temp.length());
//             }
//         }
//         return res[s.length()];
//     }
// };

// 最快实现
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> df(s.size() + 1, false);
        df[0] = true;
        for(int i = 1; i <= s.size(); ++i) {
            for(const auto& word: wordDict){
                if (i >= word.size() && df[i - word.size()] && s.substr(i - word.size(), word.size()) == word) {
                    df[i]  = true;
                    break;
                }
            }
        }
        return df[s.size()];
    }
};

int main() {
    // string s = "leetcode";
    // vector<string> wordDict = {"leet", "code"};
    string s = "goalspecial";
    vector<string> wordDict = {"go", "goal", "goals", "special"};
    // long start = GetTickCount();
    cout << Solution().wordBreak(s, wordDict);
    // long end = GetTickCount();
    // cout << endl;
    // cout << end - start << endl;
    return 0;
}