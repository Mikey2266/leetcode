#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int start = 0, end = nums.size() - 1;
        QuickSort_Recur(nums, start, end, k);
        return nums[k];
    }
    
    void QuickSort_Recur(vector<int>& nums, int start, int end, int goal) {
        if(start >= end){
            return;
        }
        int index = Partition(nums, start, end, goal);
        if(index == goal) return;
        QuickSort_Recur(nums, start, index-1, goal);
        QuickSort_Recur(nums, index+1, end, goal);
    }

    int Partition(vector<int>& nums, int start, int end, int goal){
        if (start < 0 || end <= 0|| start >= end)
            return -1;
        int left = start, right = end;
        int k = start;
        if (goal > nums.size() / 2) {
            k = end;
        }
        start = left, end = right;
        while(start <= end) {
            while(nums[start] <= nums[k] && start < k) {
                ++start;
            }
            if(nums[start] > nums[k]) {
                swap(nums, start, k);
                k = start;
                --end;
            }
            if(start >= end) break;
            while (nums[end] >= nums[k] && end > k) {
                --end;
            }
            if(nums[end] < nums[k]) {
                swap(nums, end, k);
                k = end;
                ++start;
            }
            if(start >= end) break;
        }
        return k;
    }
    void swap(vector<int>& nums, int in1, int in2){
        int temp = nums[in1];
        nums[in1] = nums[in2];
        nums[in2] = temp;
    }
};

int main() {
    vector<int> nums = {4, 5, 5, 6, 3, 2, 3, 1, 2};
    int k = 4;
    long start = GetTickCount();
    cout << Solution().findKthLargest(nums, k);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}