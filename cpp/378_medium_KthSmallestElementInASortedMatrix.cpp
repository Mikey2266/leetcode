#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         vector<int> q;
//         int row = matrix.size();
//         if (row == 0) {
//             return 0;
//         }
//         int column = matrix[0].size();
//         int x = 0;
//         int y = 0;
//         while (true) {
//             for (int i = x; i < column; ++i) {
//                 q.push_back(matrix[y][i]);
//             }
//             for (int j = y + 1; j < row; ++j) {
//                 q.push_back(matrix[j][x]);
//             }
//             x++;
//             y++;
//             if ((x >= column || y >= row) || (q.size() >= k && matrix[x][y] > matrix[y - 1][column - 1] && matrix[x][y] > matrix[row - 1][x - 1])) {
//                 break;
//             }
//         }
//         sort(q.begin(), q.end());
//         return q[k - 1];
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rowLen = matrix.size();
        int left = matrix[0][0];
        int right = matrix.back().back();
        while (left < right) {
            int count = 0;
            int mid = left + ((right - left) >> 1);
            for (const auto &item : matrix) {
                count += upper_bound(item.begin(), item.end(), mid) - item.begin();
            }
            if (count < k){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 7};
    vector<int> nums2 = {5, 10, 14, 16};
    vector<int> nums3 = {8, 10, 18, 19};
    vector<int> nums4 = {9, 12, 22, 24};
    // vector<int> nums5 = {1, 3};
    vector<vector<int>> matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);
    matrix.push_back(nums4);
    // matrix.push_back(nums5);
    int k = 14;
    // long start = GetTickCount();
    cout << Solution().kthSmallest(matrix, k);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}