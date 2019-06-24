#include<iostream>
#include<windows.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// // 回溯，超出时间限制
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         vector<vector<int>> vec;
//         if (t.empty()) return "";
//         if (t.size() > s.size()) return "";
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == t.front()) {
//                 vector<int> buff;
//                 buff.push_back(i);
//                 search(s, t, buff, vec, i, i - 1, 1);
//                 while (buff.size() != 1) {
//                     buff.pop_back();
//                 }
//                 search(s, t, buff, vec, i, i + 1, 1);
//             }
//         }
//         // 计算头与尾
//         if (vec.size() == 0) {
//             return "";
//         }
//         else {
//             int index = 0;
//             int minLen = INT_MAX;
//             for (int i = 0; i < vec.size(); ++i) {
//                 // vector<int>::iterator tail = max_element(vec[i].begin(), vec[i].end());
//                 // vector<int>::iterator head = min_element(vec[i].begin(), vec[i].end());
//                 // int len = *tail - *head + 1;

//                 // int len = vec[i][vec[i].size() - 1] - vec[i][0] + 1;
                
//                 sort(vec[i].begin(), vec[i].end());
//                 int len = vec[i][vec[i].size() - 1] - vec[i][0] + 1;
//                 if (len < minLen) {
//                     index = i;
//                     minLen = len;
//                 }
//             }
//             // vector<int>::iterator tail = max_element(vec[index].begin(), vec[index].end());
//             // vector<int>::iterator head = min_element(vec[index].begin(), vec[index].end());
//             // return s.substr(*head, *tail - *head + 1);
//             return s.substr(vec[index][0], minLen);
//         }
//     }
    
//     void search(string s, string t, vector<int>& buff, vector<vector<int>>& vec, int index, int next, int level) {
//         if (level >= t.size()) {
//             if (!vec.empty()) {
//                 if (buff == vec[vec.size() - 1]) {
//                     return;
//                 }
//             }
//             vec.push_back(buff);
//             return;
//         }
//         if (next < 0 || next >= s.size()) {
//             return;
//         }
//         if (s[next] != t[level]) {
//             if (next < index) {
//                 search(s, t, buff, vec, next, next - 1, level);
//             }
//             else if (next >= index) {
//                 search(s, t, buff, vec, next, next + 1, level);
//             }
//         }
//         else {
//             if (buff.size() == t.size()) {
//                 buff.pop_back();
//             }
//             // vector<int> temp;
//             // for (int i = 0; i < buff.size(); ++i) {
//             //     temp.push_back(buff[i]);
//             // }
//             // sort(temp.begin(), temp.end());
//             // if (!binary_search(temp.begin(), temp.end(), next)) {
//             if (!contain(buff, next)) {
//                 buff.push_back(next);
//                 search(s, t, buff, vec, next, next - 1, level + 1);
//                 while (level + 1 < buff.size()) {
//                     buff.pop_back();
//                 }
//                 search(s, t, buff, vec, next, next + 1, level + 1);
//             }
//             else {
//                 if (next < index) {
//                     search(s, t, buff, vec, next, next - 1, level);
//                 }
//                 else if (next >= index) {
//                     search(s, t, buff, vec, next, next + 1, level);
//                 }               
//             }
//         }
//     }

//     bool contain(vector<int>& buff, int next) {
//         for (int i = 0; i < buff.size(); ++i) {
//             if (buff[i] == next) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// https://blog.csdn.net/weixin_41958153/article/details/81623474
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        
        // 统计t中出现的字符数
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        
        for (int right = 0; right < S.size(); ++right) {
            // 每遇到一个t中的字符，则减1
            if (m.find(S[right]) != m.end()) {
                --m[S[right]];
                // 如果那个字符的数量还大于等于0，则说明那个字符原来至少有一个，则count+1
                if (m[S[right]] >= 0) ++count;
                // 当数目相同时，也就是窗口中能找到t中所有元素了
                while (count == T.size()) {
                    // 如果子窗口边界小于最小长度
                    if (right - left + 1 < minLen) {
                        // 更新最小长度
                        minLen = right - left + 1;
                        // 取最小长度对应的字符串
                        res = S.substr(left, minLen);
                    }
                    // 如果m中存在窗口的左边界元素,说明我们移除掉的是一个必须的组成字符
                    if (m.find(S[left]) != m.end()) {
                        // 则把对应的数量+1
                        ++m[S[left]];
                        // 如果它的数量大于0，我们的count需要-1。
                        if (m[S[left]] > 0) --count;
                    }
                    // 子窗口左移
                    ++left;
                }
            }
        }
        return res;
    }
};

int main() {
    // string s = "ADOBECODEBANC";
    // string t = "ABC";

    // string s = "bbaa";
    // string t = "aba";

    // string s = "cabeca";
    // string t = "cae";

    // string s = "adobecodebanc";
    // string t = "abdbac";

    // string s = "baAaABabBba";
    // string t = "AbbB";

    // string s = "bccbacaaababaabcbabbbbabbcca";
    // string t = "caccabbabcacbabcb";

    string s = "abcaaccbacabbbbbbcbaacbcabcca";
    string t = "abbbbbbaacbbbccccabbc";
    long start = GetTickCount();
    cout << Solution().minWindow(s, t);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}