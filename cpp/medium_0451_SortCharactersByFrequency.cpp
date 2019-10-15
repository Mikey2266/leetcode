#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<string>

using namespace std;

// class Solution {
// private:
//     static bool cmp(pair<char, int>& a, pair<char, int>& b) {
//         return a.second > b.second;
//     }
// public:
//     string frequencySort(string s) {
//         vector<pair<char, int>> dic;
//         for (int i = 0; i < 95; ++i) dic.push_back(make_pair(' ' + i, 0));
//         for (int i = 0; i < s.length(); ++i) dic[s[i] - ' '].second++;
//         sort(dic.begin(), dic.end(), cmp);
//         string res = "";
//         for (int i = 0; i < dic.size(); ++i) {
//             if (!dic[i].second) break;
//             int temp = dic[i].second;
//             for (int j = 0; j < temp; ++j) {
//                 res += dic[i].first;
//             }
//         }
//         return res;
//     }
// };

// 最快实现
class Solution {
public:
    string frequencySort(string s) {
        // 保存字符出现的次数, ASCII表
        int charCountArr[127] = {0};
        // 字符序列
        int charSeqtArr[128] = {0};
        char charArr[128] = {0};
        int MaxCount = s.length();
        for(char c : s) {
            charCountArr[c] ++;
        }
        // 对字符出现的次数数目进行计数
        int* countArr = new int[MaxCount + 1]{0};
        for(int n : charCountArr){
            countArr[n] ++;
        }
        for (int i = 1; i <= MaxCount; ++i) {
            countArr[i] = countArr[i] + countArr[i-1];
        }
        for (int j = 126; j >= 0; --j) {
            charArr[countArr[charCountArr[j]]] = j;
            charSeqtArr[countArr[charCountArr[j]]] = charCountArr[j];
            countArr[charCountArr[j]]--;
        }
        char *result = new char[MaxCount + 1];
        int index = 0;
        for (int j = 127; j > 0; --j) {
            char curChar = charArr[j];
            int repeat = charSeqtArr[j];
            if(curChar == 0 ){
                break;
            }
            for (int k = 0; k < repeat; ++k){
                result[index] = curChar;
                index++;
            }
        }
        result[index] = '\0';
        return result;
    }
};

int main() {
    // long start = GetTickCount();
    cout << Solution().frequencySort("his s he a ha he  ha ae") << endl;
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}