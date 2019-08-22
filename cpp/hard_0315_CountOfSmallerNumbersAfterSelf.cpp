#include<iostream>
#include<vector>
#include<algorithm>
#include<windows.h>

using namespace std;

// // 二分
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int>t, res(nums.size());
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             int left = 0, right = t.size();
//             while (left < right) {
//                 int mid = left + (right - left) / 2;
//                 if (t[mid] >= nums[i]) right = mid;
//                 else left = mid + 1;
//             }
//             res[i] = right;
//             t.insert(t.begin() + right, nums[i]);
//         }
//         return res;
//     }
// };

// 最快实现
class Solution {
private:
    vector<int> tree_arr;
    
    // X & (-X): 当一个偶数与它的负值相与时，结果是能被这个偶数整除的最大的2的n次幂, 当一个奇数与它的负值向与时结果一定是1
    // 类似编码的功能？
    int lowbit(int x) { return x & (-x); }
    
    void add(int idx, int val) {
        int n = tree_arr.size();
        while (idx < tree_arr.size()) {
            tree_arr[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    int pre_sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree_arr[idx];
            idx -= lowbit(idx);
        }
        return res;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        // 树状数组
        if (nums.size() <= 0) return {};
        int maxi = nums[0], mini = nums[0];
        for (auto e: nums)
            if (e > maxi) maxi = e;
            else if (e < mini) mini = e;
        int n = maxi - mini + 2;  // 个数是maxi - mini + 1, 又因为要从0开始，所以再+1
        tree_arr.resize(n, 0);
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i ) {
            res[i] = pre_sum(nums[i] - mini);
            add(nums[i] - mini + 1, 1);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {5, -1, 6, 1};
    // vector<int> nums = {2, 0, 1};
    // long start = GetTickCount();
    Solution().countSmaller(nums);
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}