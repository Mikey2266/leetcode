#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// 贪心算法有问题, 例如1, 3, 4凑成6
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> count(coins.size(), 0);
//         sort(coins.begin(), coins.end());
//         long long sum = backTrack(&count, coins, amount);
//         int num = 0;
//         if (sum != amount) {
//             return -1;
//         }
//         else {
//             for (int i = 0; i < coins.size(); i++) {
//                 num += count[i];
//                 cout << count[i] << endl;
//             }            
//         }
//         return num;
//     }
    
//     long long backTrack(vector<int>* count, vector<int>& coins, int amount) {
//         int len = coins.size();
//         long long sum = 0;
//         for (int i = 0; i < len; i++) {
//             sum = 0;
//             for (int j = 0; j < len; j++) {
//                 sum += (*count)[j] * coins[len-1-j];
//             }
//             if (sum >= amount) {
//                 return sum;
//             }
//             while (sum < amount) {
//                 (*count)[i] += 1;
//                 sum = backTrack(count, coins, amount);
//             }
//             if (sum == amount) {
//                 return sum;
//             }
//             else {
//                 (*count)[i] -= 1;                
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        if(n == 0 || amount == 0) {
            return 0;
        }
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount ; i++){
            for(int j = 0; j < coins.size() && coins[j] <= i; j++){
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        if(dp[amount] == amount + 1) return -1;
        else return dp[amount];
    }
};

int main() {
    // vector<int> num_1 = {1, 2147483647};
    // int amount = 2;
    // vector<int> num_1 = {2, 5, 10, 1};
    // int amount = 27;
    // vector<int> num_1 = {186, 419, 83, 408};
    // int amount = 6249;
    vector<int> num_1 = {1, 2, 5};
    int amount = 11;   
    long start = GetTickCount();
    cout << Solution().coinChange(num_1, amount);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}