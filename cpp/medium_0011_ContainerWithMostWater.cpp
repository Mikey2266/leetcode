#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};

int main() {
    // vector<int> nums1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> nums1 = {8, 10, 14, 0, 13, 10, 9, 9, 11, 11};
   // long start = GetTickCount();
    cout << Solution().maxArea(nums1);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}