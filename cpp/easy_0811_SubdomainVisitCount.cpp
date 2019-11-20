#include<iostream>
#include<vector>
#include<windows.h>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        for (int i = 0; i < cpdomains.size(); ++i) {
            int head = cpdomains[i].find_first_of(" ");
            if (head != string::npos) {
                int count = atoi(cpdomains[i].substr(0, head).c_str());
                string s = cpdomains[i].substr(head + 1, cpdomains[i].size() - head - 1);
                while (1) {
                    if (m.find(s) == m.end()) m[s] = 0;
                    m[s] += count;
                    int ptr = s.find_first_of(".");
                    if (ptr == string::npos) break;
                    else {
                        s = s.substr(ptr + 1, s.length() - ptr - 1);
                    }
                }
            }
        }
        vector<string> res;
        for (auto &each : m) {
            res.push_back(to_string(each.second) + " " + each.first);
        }
        return res;
    }
};

int main() {
    vector<string> v = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    // long start = GetTickCount();
    vector<string> res = Solution().subdomainVisits(v);
    // cout << GetTickCount() - start << endl;
    return 0;
}