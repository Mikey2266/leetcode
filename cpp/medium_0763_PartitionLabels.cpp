#include<iostream>
#include<windows.h>
#include<vector>


using namespace std;

// class Solution {
// public:
//     vector<int> partitionLabels(string S) {
//         int arr[26] = {0};
//         for (int i = S.length() - 1; i >=0; --i) {
//             if (!arr[S[i] - 'a']) {
//                 arr[S[i] - 'a'] = i;
//             }
//         }
//         int begin = 0;
//         int max_len = 0;
//         vector<int> res;
//         for (int i = 0; i < S.length(); ++i) {
//             if (arr[S[i] - 'a'] > max_len) {
//                 max_len = arr[S[i] - 'a'];
//             }
//             if (i == max_len) {
//                 res.push_back(max_len - begin + 1);
//                 max_len = i + 1;
//                 begin = i + 1;
//             }
//         }
//         return res;
//     }
// };

// 最快实现, 思路相同
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v(26, 0);
        // 记录单个字符出现的最后一个位置
        for (int i = 0; i < S.size(); ++i) {
            v[S[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < S.size(); ++i) {
            end = max(end, v[S[i] - 'a']);
            if (i == end) {
               ans.push_back(end - start + 1);
               start = end + 1;
            }
        }
        return ans;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    // long start = GetTickCount();
    vector<int> res = Solution().partitionLabels(s);
    // cout << GetTickCount() - start << endl;
    return 0;
}