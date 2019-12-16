#include<iostream>
#include<windows.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
        vector<int> dp(len, -1);
        for (int i = 0; i < len; ++i) {
            /* 分别计算最后一段区间长度 j ∈[1, K]时的解，并更新位置i时的最优解 */
            int domainMax = A[i];
            for (int j = 1; j <= K && i - j + 1 >= 0; ++j) {
                domainMax = max(domainMax, A[i - j + 1]);
                if (i - j >= 0) {
                    dp[i] = max(dp[i], dp[i - j] + j * domainMax);
                } else {
                    dp[i] = max(dp[i], j * domainMax);
                }
            }
        }
        return dp[len - 1];
    }
};

int main() {
    vector<int> A = {1, 15, 7, 9, 2, 5, 10};
    int K = 3;
    // long start = GetTickCount();
    cout << Solution().maxSumAfterPartitioning(A, K);
    // cout << GetTickCount() - start << endl;
    return 0;
}