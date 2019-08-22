#include<iostream>
#include<windows.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> vec;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] < 48) {
                if (s[i] == '+') vec.push_back(-1);
                if (s[i] == '-') vec.push_back(-2);
                if (s[i] == '*') vec.push_back(-3);
                if (s[i] == '/') vec.push_back(-4);
            }
            else {
                int j = i + 1;
                for (; j < s.length(); j++) {
                    if (s[j] == ' ' || s[j] < 48) break;
                }
                int num = str2int(s.substr(i, j - i));
                i = j - 1;
                if (vec.empty()) {
                    vec.push_back(num);
                }
                else {
                    int flag = vec.back();
                    if (flag == -3) {
                        vec.pop_back();
                        int res = vec.back() * num;
                        vec.pop_back();
                        vec.push_back(res);
                    }
                    else if (flag == -4) {
                        vec.pop_back();
                        int res = vec.back() / num;
                        vec.pop_back();
                        vec.push_back(res);
                    }
                    else vec.push_back(num);                    
                }
            }
        }
        int ans = vec[0];
        if (vec.size() == 1) return ans;
        else {
            for (int i = 0; 2 * i + 2 < vec.size(); ++i) {
                if (vec[2 * i + 1] == -2) {
                    ans = ans - vec[2 * i + 2];
                }
                if (vec[2 * i + 1] == -1) {
                    ans = ans + vec[2 * i + 2];
                }
            }
        }
        return ans;
    }

    int str2int(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
};

int main() {
    string s = "3+2*2";
    // long start = GetTickCount();
    cout << Solution().calculate(s);
    // long end = GetTickCount();
    // cout << endl;
    // cout << end - start << endl;
    return 0;
}