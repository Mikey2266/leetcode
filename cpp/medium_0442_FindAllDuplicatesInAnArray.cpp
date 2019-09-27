#include<iostream>
#include<vector>
#include<windows.h>
#include<math.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> vec;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] - 1 != i) {
//                 int temp = nums[i];
//                 nums[i] = -1;
//                 while(temp != -1 && nums[temp - 1] != temp) {
//                     int p = nums[temp - 1];
//                     nums[temp - 1] = temp;
//                     temp = p;
//                 }
//                 if (temp != -1) {
//                     vec.push_back(temp);
//                 }
//             }
//         }
//         return nums;
//     }
// };

// 最快实现
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    // long start = GetTickCount();
    vector<int> vec = Solution().findDuplicates(nums);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}