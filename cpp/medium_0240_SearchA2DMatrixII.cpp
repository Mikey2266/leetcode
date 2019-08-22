#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// 回溯
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.size() == 0) {
//             return false;
//         }
//         if (matrix[0].size() == 0) {
//             return false;
//         }
//         if (matrix[0][0] == target) {
//                 return true;
//         }
//         if (matrix[0].size() == 1) {
//             for (int j = 0; j < matrix.size(); j++) {
//                 if (matrix[j][0] == target) {
//                     return true;
//                 }
//             }
//         }
//         for (int i = 1; i < matrix[0].size(); i++) {
//             if (matrix[0][i] == target) {
//                 return true;
//             }
//             if (i == matrix[0].size()-1 || (matrix[0][i-1] < target && matrix[0][i] > target)) {
//                 for (int j = 1; j < matrix.size(); j++) {
//                     if (matrix[j][i] == target || matrix[j][0]== target || matrix[j-1][0] == target) {
//                         return true;
//                     }
//                     if (j == matrix.size()-1) {
//                         return backTrack(matrix, j, i-1, target, false);
//                     }
//                     else if (matrix[j][0] > target && matrix[j-1][0] < target) {
//                         return backTrack(matrix, j-1, i-1, target, false);
//                     }
//                 }
//             }
//         }
//         return false;
//     }
    
//     bool backTrack(vector<vector<int>>& matrix, int row, int column, int target, bool flag) {
//         if (matrix[row][column] == target) {
//             flag = true;
//             return flag;
//         }
//         if (row > 0 && matrix[row][column] > target && !flag) {
//             flag = backTrack(matrix, row-1, column, target, flag);
//         }
//         if (column > 0 && matrix[row][column] > target && !flag) {
//             flag = backTrack(matrix, row, column-1, target, flag);
//         }
//         return flag;
//     }
// };

// 二分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][0] <= target || matrix[j][matrix[0].size()-1] >=0) {
                int res = binarySearch(matrix[j], target);
                if (res != -1) {
                    return true;
                }
            }
            if (matrix[j][0] > target) {
                break;
            }
        }
        return false;
    }
    int binarySearch(vector<int>& list, int target) {
        int left = 0;
        int right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] == target) {
                return mid;
            }
            if (list[mid] < target) {
                left = mid + 1;
            }
            if (list[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    // vector<int> num_1 = {1, 4};
    // vector<int> num_2 = {2, 5};
    // vector<int> num_1 = {1, 3, 5, 7, 9};
    // vector<int> num_2 = {2, 4, 6, 8, 10};
    // vector<int> num_3 = {11, 13, 15, 17, 19};
    // vector<int> num_4 = {12, 14, 16, 18, 20};
    // vector<int> num_5 = {21, 22, 23, 24, 25};
    vector<int> num_1 = {4, 7, 11, 12, 16, 21, 23, 26};
    vector<int> num_2 = {5, 12, 17, 17, 18, 23, 26, 31};
    vector<int> num_3 = {8, 15, 21, 25, 26, 29, 33, 34};
    vector<int> num_4 = {13,20, 26, 26, 29, 34, 39, 40};
    vector<int> num_5 = {18, 21, 31, 36, 41, 42, 42, 44};
    vector<int> num_6 = {19, 23, 31, 39, 46, 49, 50, 53};
    vector<int> num_7 = {23, 25, 33, 40, 50, 51, 55, 60};
    vector<int> num_8 = {27, 28, 33, 44, 51, 56, 61, 65};
    vector<int> num_9 = {32, 35, 39, 45, 54, 56, 65, 68};
    vector<int> num_10 = {33, 38, 40, 49, 56, 57, 66, 71};
    int target = 51;
    vector<vector<int>> matrix;
    matrix.push_back(num_1);
    matrix.push_back(num_2);
    matrix.push_back(num_3);
    matrix.push_back(num_4);
    matrix.push_back(num_5);
    matrix.push_back(num_6);
    matrix.push_back(num_7);
    matrix.push_back(num_8);
    matrix.push_back(num_9);
    matrix.push_back(num_10);
    long start = GetTickCount();
    cout << Solution().searchMatrix(matrix, target);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}