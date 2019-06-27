#include<iostream>
#include<windows.h>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int helper(stack<pair<int, int>> &st, int &res, int height) {
        int count = 0;
        if (st.empty() || height > st.top().first) return 0;
        while (!st.empty() && st.top().first > height) {
            count += 1 + st.top().second;
            res = max(res, st.top().first * count);
            st.pop();
        }
        return count;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            st.push(make_pair(heights[i], helper(st, res, heights[i])));
        }
        helper(st, res, -1);
        return res;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    // long start = GetTickCount();
    cout << Solution().largestRectangleArea(heights);
    // long end = GetTickCount();
    // cout << endl;
    // cout << end - start << endl;
    return 0;
}