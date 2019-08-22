#include<iostream>
#include<vector>
#include<algorithm>
#include<windows.h>

using namespace std;

// // 递归, 超出时间限制
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         int res = 0;
//         if (!matrix.size()) return 0;
//         for (int i = 0; i < matrix.size(); ++i) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 int len = 1;
//                 int a = max(go(matrix, i - 1, j, len, matrix[i][j]), go(matrix, i + 1, j, len, matrix[i][j]));
//                 int b = max(go(matrix, i, j - 1, len, matrix[i][j]), go(matrix, i, j + 1, len, matrix[i][j]));
//                 int temp = max(a, b);
//                 if (temp > res) res = temp;
//             }
//         }
//         return res;
//     }
    
//     int go(vector<vector<int>>& matrix, int row, int col, int len, int pre) {
//         int rowB = matrix.size();
//         int colB = matrix[0].size();
//         if (row < 0 || row >= rowB) return len;
//         if (col < 0 || col >= colB) return len;
//         int temp = matrix[row][col];
//         if (temp > pre) {
//             len++;
//             return max(max(go(matrix, row - 1, col, len, temp), go(matrix, row + 1, col, len, temp)), max(go(matrix, row, col - 1, len, temp), go(matrix, row, col + 1, len, temp)));
//         }
//         return len;
//     }
// };

// https://www.cnblogs.com/grandyang/p/5148030.html
class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, dp, x, y);
            mx = max(mx, len);
        }
        dp[i][j] = mx;
        return mx;
    }
};

int main() {
    // vector<int> nums1 = {9, 9, 4};
    // vector<int> nums2 = {6, 6, 8};
    // vector<int> nums3 = {2, 1, 1};
    vector<int> nums1 = {3, 4, 5};
    vector<int> nums2 = {3, 2, 6};
    vector<int> nums3 = {2, 2, 1};
    // vector<int> nums1 = {7, 8, 9};
    // vector<int> nums2 = {9, 7, 6};
    // vector<int> nums3 = {7, 2, 3};
    vector<vector<int>> matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);
    // long start = GetTickCount();
    cout << Solution().longestIncreasingPath(matrix);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}