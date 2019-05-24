#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int maxNum = 1;
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         if (n == 0) {
//             return 0;
//         }
//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                     if (dp[i] > maxNum) {
//                         maxNum = dp[i];
//                     }                   
//                 }
//             }
//         }
//         return maxNum;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
	 
   int n = nums.size();
    if (n == 0)
        return 0;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
        if (it == temp.end())
            temp.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return temp.size();
    }
};

int main() {
    vector<int> num_1 = {10, 9, 2, 5, 3, 4};
    long start = GetTickCount();
    cout << Solution().lengthOfLIS(num_1);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}