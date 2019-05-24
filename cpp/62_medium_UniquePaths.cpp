#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if ((m < 3 && n == 1) || (m == 1 && n < 3)) {
//             return 1;
//         }
//         if (m < 1 || n < 1) {
//             return 0;
//         }
//         return uniquePaths(m-1, n) + uniquePaths(m, n-1);
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 1));
        if (m < 1 || n < 1) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                res[j][i] = res[j][i - 1] + res[j-1][i];
            }
        }
        return res[m-1][n-1];
    }
};

int main() {
    int m = 30;
    int n = 30;
    long start = GetTickCount();
    cout << Solution().uniquePaths(m, n);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}