#include<iostream>
#include<vector>
#include<windows.h>
#include<math.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
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
//             }
//         }
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] == -1) {
//                 vec.push_back(i + 1);
//             }
//         }
//         return vec;
//     }
// };

// 最快实现
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 用负数标注表示该位置有数存在, 注意数字从1开始
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                if(nums[nums[i] - 1] > 0)
                    nums[nums[i] - 1] = -nums[nums[i] - 1];
            }
            else {
                if(nums[-nums[i] - 1] > 0)
                    nums[-nums[i] - 1] = -nums[-nums[i] - 1];
            }
        }
        vector<int> r;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0)
                r.push_back(i + 1);
        }
        return r;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    // long start = GetTickCount();
    vector<int> vec = Solution().findDisappearedNumbers(nums);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}