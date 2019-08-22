#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 为空，则返回空
        if (intervals.empty()) return {};
        // 冒泡排序
        int num = intervals.size() - 1;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num - i; j++) {
                if (intervals[j][0] > intervals[j+1][0]) {
                    swapVec(intervals[j], intervals[j+1]);
                }
            }
        }
        // 合并区间
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res[res.size()-1][1] < intervals[i][1] && intervals[i][0] < res[res.size()-1][1]) {
                res[res.size()-1][1] = intervals[i][1];
            }
            else if (intervals[i][0] > res[res.size()-1][1]) {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    // 交换
    void swapVec(vector<int>& vec1, vector<int>& vec2) {
        vector<int> temp = {0, 0};
        temp[0] = vec2[0];
        temp[1] = vec2[1];
        vec2[0] = vec1[0];
        vec2[1] = vec1[1];
        vec1[0] = temp[0];
        vec1[1] = temp[1];
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {3, 6};
    vector<int> nums3 = {2, 10};
    vector<int> nums4 = {15, 18};
    vector<vector<int>> intervals;
    intervals.push_back(nums1);
    intervals.push_back(nums2);
    intervals.push_back(nums3);
    intervals.push_back(nums4);
    long start = GetTickCount();
    Solution().merge(intervals);
    long end = GetTickCount();
    cout << endl;
    cout << end - start << endl;
    return 0;
}