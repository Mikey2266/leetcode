#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if (nums.size() < 2) return true;
//         // vector<vector<bool>> dict;
//         vector<bool> visited(nums.size(), false);
//         visited[0] = true;
//         for (int i = 0; i < nums.size() - 1; i++) {
//             // vector<bool> vec(nums.size(), false);
//             // if (dict.size() == 0) {
//             if (visited[i]) {
//                 for (int j = i + 1; j < nums.size() && j < i + 1 + nums[i]; j++) {
//                     if (j == nums.size() - 1) {
//                         return true;
//                     }
//                     // vec[j] = true;
//                     visited[j] = true;
//                 }
//                 // dict.push_back(vec);
//             }
//             // else {
//             //     if (visited[i]) {
//             //         for (int j = i + 1; j < nums.size() && j < i + 1 + nums[i]; j++) {
//             //             if (j == nums.size() - 1) {
//             //                 return true;
//             //             }
//             //             vec[j] = true;
//             //             visited[j] = true;
//             //         }
//                     // dict.push_back(vec);
//             //     }
//             // }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int flag = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i <= flag) {
                if (i + nums[i] > flag) {
                    flag = i + nums[i];
                    if (flag >= nums.size() - 1) {
                        return true;
                    }
                }
            }
            else
                break;
        }
        return false;
    }
};

int main() {
    // vector<int> num_1 = {1, 1, 1, 0};
    // vector<int> num_1 = {1, 0, 2, 3};
    // vector<int> num_1 = {3, 2, 1, 0, 4};
    // vector<int> num_1 = {2, 3, 1, 1, 4};
    vector<int> num_1 = {3, 0, 8, 2, 0, 0, 1};
    // long start = GetTickCount();
    cout << Solution().canJump(num_1);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}