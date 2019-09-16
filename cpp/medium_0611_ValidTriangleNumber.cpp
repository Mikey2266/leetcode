#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

// // 回溯, 超出时间限制
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int res = 0;
//         vector<int> temp;
//         int index = 0;
//         for (;index < nums.size(); ++index) {
//             if (nums[index] != 0) break;
//         }
//         backTracking(nums, index, temp, res);
//         return res;
//     }
    
//     void backTracking(vector<int>& nums, int index, vector<int> temp, int& res) {
//         if (temp.size() == 3) {
//             if (temp[0] + temp[1] > temp[2]) {
//                 res++;
//             }
//             return;
//         }
//         while (index < nums.size()) {
//             temp.push_back(nums[index]);
//             backTracking(nums, ++index, temp, res);
//             temp.pop_back();
//         }
//         return;
//     }
// };

// 二分
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int len = nums.size();
        //! 此处不能用 (i <= nums.size() - 3), 会溢出
        for (int i = 0; i <= len - 3; ++i) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j <= len - 2; ++j) {
                // 二分查找
                int target = nums[i] + nums[j];
                int lo = j + 1;
                int hi = nums.size() - 1;
                while (lo <= hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (nums[mid] >= target) hi = mid - 1;
                    else lo = mid + 1;
                }
                res += hi - j;
            }
        }
        return res;
    }
};

// // 最快
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int cnt = 0;
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         int l1 = 0;
//         while(l1 < len - 2 && nums[l1] == 0) ++l1;
//         for (int l3 = len - 1; l3 > l1 + 1; --l3) {
//             for(int l2 = l3 - 1, k = l1; l2 > k;) {
//                 if(nums[k] + nums[l2] > nums[l3]) {
//                     cnt += l2 - k;
//                     --l2;
//                 }
//                 else ++k;
//             }
//         }
//         return cnt;
//     }
// };

int main() {
    // vector<int> num_1 = {1, 1};
    // vector<int> num_1 = {2, 2, 3, 4, 1, 0};
    vector<int> num_1 = {23, 28, 1, 94, 30, 70, 93, 57, 81, 13,
                         26, 92, 80, 60, 98, 13, 69, 77, 45, 7,
                         85, 66, 82, 19, 58, 75, 28, 16, 85, 66,
                         55, 61, 92, 42, 77, 88, 60, 90, 14, 43,
                         75, 80, 70, 65, 77, 97, 18, 40, 75, 46,
                         81, 49, 51, 24, 89, 29, 69, 14, 69, 66,
                         95, 70, 34, 83, 79, 87, 35, 9, 70, 55, 
                         96, 100, 52, 40, 19, 4, 56, 78, 97, 3,
                         56, 98, 30, 0, 58, 14, 76, 89, 71, 76,
                         82, 41, 10, 42, 53, 44, 87, 73, 78, 46};
    // long start = GetTickCount();
    cout << Solution().triangleNumber(num_1);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}