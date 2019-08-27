#include<iostream>
#include<vector>
#include<set>
#include<windows.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> vec = {0, 1, 1, 2, 1, 2, 2, 3};
//         if (num < 8) {
//             vector<int> res(vec.begin(), vec.begin() + 1 + num);
//             return res;
//         }
//         bool flag= true;
//         while (flag) {
//             int len = vec.size();
//             for (int i = 0; i < len; ++i) {
//                 vec.push_back(vec[i] + 1);
//                 if (vec.size() == num + 1) {
//                     flag = false;
//                     break;
//                 }
//             }            
//         }
//         return vec;
//     }
// };

// 最快实现
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        if(num == 0) return ans; 
        ans[1] = 1;
        if(num == 1) return ans;
        int left = 1, right = 2, i = 2;
        while (i <= num) {
            left = left * 2;
            right = left * 2;
            int mid = left + (right - left) / 2;
            int j = 0; 
            for(i = left; i <= num && i < mid; ++i) {
                ans[i] = ans[left / 2 + j];
                ++j;
            }
            j = 0;
            for(i = mid; i <= num && i < right; ++i) {
                ans[i] = ans[left / 2 + j] + 1;
                ++j;
            }
        }
        return ans;
    }
};

int main() {
    int num = 8;
    // long start = GetTickCount();
    vector<int> res = Solution().countBits(num);
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}